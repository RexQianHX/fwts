/*
 * Copyright (C) 2010 Canonical
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <getopt.h>
#include <sys/utsname.h>

#include "fwts.h"

#define RESULTS_LOG	"results.log"

#define FWTS_RUN_ALL_FLAGS		\
	(FWTS_BATCH |			\
	 FWTS_INTERACTIVE |		\
	 FWTS_BATCH_EXPERIMENTAL |	\
	 FWTS_INTERACTIVE_EXPERIMENTAL |\
	 FWTS_POWER_STATES)

#define LOGFILE(name1, name2)	\
	(name1 != NULL) ? name1 : name2

enum {
	BIOS_TEST_TOOLKIT_PASSED_TEXT,
	BIOS_TEST_TOOLKIT_FAILED_TEXT,
	BIOS_TEST_TOOLKIT_WARNING_TEXT,
	BIOS_TEST_TOOLKIT_ERROR_TEXT,
	BIOS_TEST_TOOLKIT_ADVICE_TEXT,
	BIOS_TEST_TOOLKIT_FRAMEWORK_DEBUG
};

static fwts_list *fwts_framework_test_list;

typedef struct {
	const int env_id;
	const char *env_name;
	const char *env_default;
	char *env_value;
} fwts_framework_setting;

#define ID_NAME(id)	id, # id

static fwts_framework_setting fwts_framework_settings[] = {
	{ ID_NAME(BIOS_TEST_TOOLKIT_PASSED_TEXT),      "PASSED",  NULL },
	{ ID_NAME(BIOS_TEST_TOOLKIT_FAILED_TEXT),      "FAILED",  NULL },
	{ ID_NAME(BIOS_TEST_TOOLKIT_WARNING_TEXT),     "WARNING", NULL },
	{ ID_NAME(BIOS_TEST_TOOLKIT_ERROR_TEXT),       "ERROR",   NULL },
	{ ID_NAME(BIOS_TEST_TOOLKIT_ADVICE_TEXT),      "ADVICE",  NULL },
	{ ID_NAME(BIOS_TEST_TOOLKIT_FRAMEWORK_DEBUG),  "off",     NULL },
};

static void fwts_framework_debug(fwts_framework* framework, const char *fmt, ...);

static int fwts_framework_compare_priority(void *data1, void *data2)
{
	fwts_framework_test *test1 = (fwts_framework_test *)data1;
	fwts_framework_test *test2 = (fwts_framework_test *)data2;

	return (test1->priority - test2->priority);
}

void fwts_framework_test_add(const char *name, 
			     fwts_framework_ops *ops, 
			     const int priority, 
			     const int flags)
{
	fwts_framework_test *new_test;

	if (flags & ~FWTS_RUN_ALL_FLAGS) {
		fprintf(stderr, "Test %s flags must be FWTS_BATCH, FWTS_INTERACTIVE, FWTS_BATCH_EXPERIMENTAL, \n"
			        "FWTS_INTERACTIVE_EXPERIMENTAL or FWTS_POWER_STATES, got %x\n", name, flags);
		exit(EXIT_FAILURE);
	}

	if (fwts_framework_test_list == NULL) {
		fwts_framework_test_list = fwts_list_init();
		if (fwts_framework_test_list == NULL) {
			fprintf(stderr, "FATAL: Could not allocate memory setting up test framework\n");
			exit(EXIT_FAILURE);
		}
	}

	/* This happens early, so if it goes wrong, bail out */
	if ((new_test = calloc(1, sizeof(fwts_framework_test))) == NULL) {
		fprintf(stderr, "FATAL: Could not allocate memory adding tests to test framework\n");
		exit(EXIT_FAILURE);
	}

	for (ops->total_tests = 0; ops->tests[ops->total_tests] != NULL; ops->total_tests++)
		;

	new_test->name = name;
	new_test->ops  = ops;
	new_test->priority = priority;
	new_test->flags = flags;

	fwts_list_add_ordered(fwts_framework_test_list, new_test, fwts_framework_compare_priority);
}

static int fwts_framework_compare_name(void *data1, void *data2)
{
	fwts_framework_test *test1 = (fwts_framework_test *)data1;
	fwts_framework_test *test2 = (fwts_framework_test *)data2;

	return strcmp(test1->name, test2->name);
}

static void fwts_framework_show_tests(fwts_framework *fw)
{
	fwts_list_link *item;
	fwts_list *sorted;
	int i;
	int need_nl = 0;

	typedef struct {
		const char *title;
		const int  flag;
	} fwts_categories;

	fwts_categories categories[] = {
		{ "Batch",			FWTS_BATCH },
		{ "Interactive",		FWTS_INTERACTIVE },
		{ "Batch Experimental",		FWTS_BATCH_EXPERIMENTAL },
		{ "Interactive Experimental",	FWTS_INTERACTIVE_EXPERIMENTAL },
		{ "Power States",		FWTS_POWER_STATES },
		{ NULL,			0 },
	};

	for (i=0; categories[i].title != NULL; i++) {
		fwts_framework_test *test;

		if (((fw->flags & FWTS_RUN_ALL_FLAGS) == 0) ||
		    ((fw->flags & FWTS_RUN_ALL_FLAGS) & categories[i].flag)) {
			if ((sorted = fwts_list_init()) == NULL) {
				fprintf(stderr, "FATAL: Could not sort sort tests by name, out of memory.");
				exit(EXIT_FAILURE);
			}
			for (item = fwts_framework_test_list->head; item != NULL; item = item->next) {
				test = (fwts_framework_test*)item->data;
				if ((test->flags & FWTS_RUN_ALL_FLAGS) == categories[i].flag)
					fwts_list_add_ordered(sorted, item->data, fwts_framework_compare_name);
			}

			if (fwts_list_len(sorted) > 0) {
				if (need_nl)
					printf("\n");
				need_nl = 1;
				printf("%s tests:\n", categories[i].title);
	
				for (item = sorted->head; item != NULL; item = item->next) {
					test = (fwts_framework_test*)item->data;
		
					printf(" %-13.13s %s\n", test->name, test->ops->headline());
				}
			}
			fwts_list_free(sorted, NULL);
		}
	}
}

void fwts_framework_minor_test_progress(fwts_framework *fw, const int percent)
{
	float major_percent;
	float minor_percent;
	float process_percent;
	float progress;

	if (percent >=0 && percent <=100)
		fw->minor_test_progress = percent;

	major_percent = (float)100.0 / (float)fw->major_tests_total;
	minor_percent = ((float)major_percent / (float)fw->current_ops->total_tests);
	process_percent = ((float)minor_percent / 100.0);

	progress = (float)(fw->current_major_test_num-1) * major_percent;
	progress += (float)(fw->current_minor_test_num-1) * minor_percent;
	progress += (float)(percent) * process_percent;

	if (fw->flags & FWTS_FRAMEWORK_FLAGS_SHOW_PROGRESS) {
		int percent;

		percent = (100 * (fw->current_minor_test_num-1) / fw->current_ops->total_tests) + 
			  (fw->minor_test_progress / fw->current_ops->total_tests);
		fprintf(stderr, "%-20.20s: %3.0f%%\r", fw->current_major_test->name, progress);
		fflush(stderr);
	}

	/* Output for the dialog tool, dialog --title "fwts" --gauge "" 12 80 0 */

	if (fw->flags & FWTS_FRAMEWORK_FLAGS_SHOW_PROGRESS_DIALOG) {
		fprintf(stdout, "XXX\n");
		fprintf(stdout, "%d\n", (int)progress);
		fprintf(stdout, "Sofar: %d passes, %d failures, %d warnings, %d aborted\n\n",
			fw->total.passed,
			fw->total.failed,
			fw->total.warning,
			fw->total.aborted);
		fprintf(stdout, "Running test #%d '%s': (%d of %d)\n", 
			fw->current_major_test_num,
			fw->current_major_test->name,
			fw->current_minor_test_num, fw->current_ops->total_tests);
		fprintf(stdout, "\n");
		fprintf(stdout, "Purpose: %s\n", fw->current_major_test->ops->headline());
		fprintf(stdout, "XXX\n");
		fflush(stdout);
	}
}

static void fwts_framework_underline(fwts_framework *fw, const int ch)
{
	fwts_log_underline(fw->results, ch);
}

static char *fwts_framework_get_env(const int env_id)
{
	int i;

	for (i=0;i<sizeof(fwts_framework_settings)/sizeof(fwts_framework_setting);i++) {
		if (fwts_framework_settings[i].env_id == env_id) {	
			if (fwts_framework_settings[i].env_value)
				return fwts_framework_settings[i].env_value;
			else {
				const char *value = getenv(fwts_framework_settings[i].env_name);
				if (value == NULL) {
					value = fwts_framework_settings[i].env_default;
				}
				fwts_framework_settings[i].env_value = strdup(value);
				if (fwts_framework_settings[i].env_value)
					return fwts_framework_settings[i].env_value;
				else
					return "";
			}
		}
	}
	return "";
}

static void fwts_framework_free_env(void)
{
	int i;

	for (i=0;i<sizeof(fwts_framework_settings)/sizeof(fwts_framework_setting);i++)
		if (fwts_framework_settings[i].env_value)
			free(fwts_framework_settings[i].env_value);
}

static void fwts_framework_debug(fwts_framework* fw, const char *fmt, ...)
{
	va_list ap;
	char buffer[1024];	
	static int debug = -1;

	if (debug == -1)
		debug = (!strcmp(fwts_framework_get_env(BIOS_TEST_TOOLKIT_FRAMEWORK_DEBUG),"on")) |
			(fw->flags & FWTS_FRAMEWORK_FLAGS_FRAMEWORK_DEBUG);
	if (debug == 0)
		return;

	va_start(ap, fmt);

        vsnprintf(buffer, sizeof(buffer), fmt, ap);
	
	fwts_log_printf(fw->debug, LOG_DEBUG, LOG_LEVEL_NONE, "%s", buffer);

        va_end(ap);
}

static int fwts_framework_test_summary(fwts_framework *fw)
{
	fwts_framework_underline(fw,'=');
	fwts_log_summary(fw, "%d passed, %d failed, %d warnings, %d aborted.", 
		fw->major_tests.passed, fw->major_tests.failed, fw->major_tests.warning, fw->major_tests.aborted);
	fwts_framework_underline(fw,'=');

	if (fw->flags & FWTS_FRAMEWORK_FLAGS_STDOUT_SUMMARY) {
		if ((fw->major_tests.aborted > 0) || (fw->major_tests.failed > 0))
			printf("%s\n", fwts_framework_get_env(BIOS_TEST_TOOLKIT_FAILED_TEXT));
		else if (fw->major_tests.warning > 0)
			printf("%s\n", fwts_framework_get_env(BIOS_TEST_TOOLKIT_WARNING_TEXT));
		else
			printf("%s\n", fwts_framework_get_env(BIOS_TEST_TOOLKIT_PASSED_TEXT));
	}

	fwts_log_newline(fw->results);

	return FWTS_OK;
}

static int fwts_framework_total_summary(fwts_framework *fw)
{
	fwts_log_summary(fw, "Summary: %d passed, %d failed, %d warnings, %d aborted.", 
		fw->total.passed, fw->total.failed, fw->total.warning, fw->total.aborted);

	return FWTS_OK;
}

static int fwts_framework_run_test(fwts_framework *fw, const int num_tests, const fwts_framework_test *test)
{		
	fwts_framework_tests *minor_test;	

	fwts_framework_debug(fw, "fwts_framework_run_test() entered");

	fw->major_tests.aborted = 0;
	fw->major_tests.failed  = 0;
	fw->major_tests.passed  = 0;
	fw->major_tests.warning = 0;

	fwts_log_set_owner(fw->results, test->name);

	fw->current_ops = test->ops;
	fw->current_minor_test_num = 1;

	fwts_framework_minor_test_progress(fw, 0);

	if (test->ops->headline) {
		fwts_log_heading(fw, "%s", test->ops->headline());
		fwts_framework_underline(fw,'-');
	}

	fwts_framework_debug(fw, "fwts_framework_run_test() calling ops->init()");

	if (test->ops->init) {
		int ret;
		if ((ret = test->ops->init(fw)) != FWTS_OK) {
			if (fw->flags & FWTS_FRAMEWORK_FLAGS_SHOW_PROGRESS) {
				fprintf(stderr, "%-20.20s Test %s.\n", test->name,
					ret == FWTS_SKIP ? "skipped" : "aborted");		
				fflush(stderr);
			}
			/* Init failed or skipped, so abort */
			if (ret == FWTS_SKIP) {
				/* fwts_log_info(fw, "Skipping test."); */
				fwts_framework_debug(fw, "fwts_framework_run_test() init returned skipped, skip test.");
			} else {
				fwts_log_error(fw, "Aborted test, initialisation failed.");
				fwts_framework_debug(fw, "fwts_framework_run_test() init failed, aborting!");
			}
			for (minor_test = test->ops->tests; *minor_test != NULL; minor_test++) {
				fw->major_tests.aborted++;
				fw->total.aborted++;
			}
			fwts_framework_test_summary(fw);
			return FWTS_OK;
		}
	}

	for (minor_test = test->ops->tests; *minor_test != NULL; minor_test++, fw->current_minor_test_num++) {
		fwts_framework_debug(fw, "exectuting test %d", fw->current_minor_test_num);

		fw->minor_tests.aborted = 0;
		fw->minor_tests.failed  = 0;
		fw->minor_tests.passed  = 0;
		fw->minor_tests.warning = 0;

		fwts_framework_minor_test_progress(fw, 0);
		(*minor_test)(fw);
		fwts_framework_minor_test_progress(fw, 100);
	
		fw->major_tests.aborted += fw->minor_tests.aborted;
		fw->major_tests.failed  += fw->minor_tests.failed;
		fw->major_tests.passed  += fw->minor_tests.passed;
		fw->major_tests.warning += fw->minor_tests.warning;

		if (fw->flags & FWTS_FRAMEWORK_FLAGS_SHOW_PROGRESS) {
			fprintf(stderr, "%-20.20s Test %d of %d completed (%d passed, %d failed, %d warnings, %d aborted).\n", 
				test->name, fw->current_minor_test_num, test->ops->total_tests,
				fw->minor_tests.passed, fw->minor_tests.failed, 
				fw->minor_tests.warning, fw->minor_tests.aborted);
		}
		fwts_log_nl(fw);
	}

	fw->total.aborted += fw->major_tests.aborted;
	fw->total.failed  += fw->major_tests.failed;
	fw->total.passed  += fw->major_tests.passed;
	fw->total.warning += fw->major_tests.warning;

	fwts_framework_debug(fw, "fwts_framework_run_test() calling ops->deinit()");
	if (test->ops->deinit)
		test->ops->deinit(fw);
	fwts_framework_debug(fw, "fwts_framework_run_test() complete");

	fwts_framework_test_summary(fw);

	fwts_log_set_owner(fw->results, "fwts");

	return FWTS_OK;
}

static void fwts_framework_tests_run(fwts_framework *fw, fwts_list *tests_to_run)
{
	fwts_list_link *item;

	fwts_framework_debug(fw, "fwts_framework_major_tests()");

	fw->current_major_test_num = 1;
	fw->major_tests_total  = fwts_list_len(tests_to_run);

	for (item = tests_to_run->head; item != NULL; item = item->next) {		
		fwts_framework_test *test = (fwts_framework_test*)item->data;

		fw->current_major_test = test;
		fwts_framework_debug(fw, "fwts_framework_major_tests() - test %s",test->name);
		fwts_framework_run_test(fw, fwts_list_len(tests_to_run), test);
		fw->current_major_test_num++;
	}
	fwts_framework_debug(fw, "fwts_framework_major_tests() done");
}

static fwts_framework_test *fwts_framework_test_find(fwts_framework *fw, const char *name)
{
	fwts_list_link *item;

	for (item = fwts_framework_test_list->head; item != NULL; item = item->next) {
		fwts_framework_test *test = (fwts_framework_test*)item->data;
		if (strcmp(name, test->name) == 0)
			return test;
	}

	return NULL;
}

static void fwts_framework_close(fwts_framework *fw)
{
	int failed = ((fw->total.aborted > 0) || 
		      (fw->total.failed > 0) || 
		      (fw->total.warning > 0));

	free(fw->iasl);
	free(fw->dmidecode);
	free(fw->lspci);
	free(fw->debug_logname);
	free(fw->results_logname);

	fwts_framework_free_env();

	fwts_list_free(fwts_framework_test_list, free);

	if (fw && (fw->magic == FWTS_FRAMEWORK_MAGIC))
		free(fw);
	
	exit(failed ? EXIT_FAILURE : EXIT_SUCCESS);
}

void fwts_framework_advice(fwts_framework *fw, const char *fmt, ...)
{
	va_list ap;
	char buffer[4096];

	va_start(ap, fmt);

	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	fwts_framework_debug(fw, "test %d ADVICE: %s.", fw->current_minor_test_num, buffer);
	fwts_log_nl(fw);
	fwts_log_printf(fw->results, LOG_RESULT, LOG_LEVEL_NONE, "%s: %s", 
		fwts_framework_get_env(BIOS_TEST_TOOLKIT_ADVICE_TEXT), buffer);
	fwts_log_nl(fw);

	va_end(ap);
}

void fwts_framework_passed(fwts_framework *fw, const char *fmt, ...)
{
	va_list ap;
	char buffer[4096];

	va_start(ap, fmt);

	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	fwts_framework_debug(fw, "test %d PASSED: %s.", fw->current_minor_test_num, buffer);
	fw->minor_tests.passed++;
	fwts_log_printf(fw->results, LOG_RESULT, LOG_LEVEL_NONE, "%s: test %d, %s", 
		fwts_framework_get_env(BIOS_TEST_TOOLKIT_PASSED_TEXT), fw->current_minor_test_num, buffer);

	va_end(ap);
}

void fwts_framework_failed(fwts_framework *fw, fwts_log_level level, const char *fmt, ...)
{
	va_list ap;
	char buffer[4096];

	va_start(ap, fmt);

	vsnprintf(buffer, sizeof(buffer), fmt, ap);

	fwts_summary_add(fw->current_major_test->name, level, buffer);

	fwts_framework_debug(fw, "test %d FAILED [%s]: %s.", fw->current_minor_test_num, fwts_log_level_to_str(level), buffer);
	fw->minor_tests.failed++;
	fwts_log_printf(fw->results, LOG_RESULT, level, "%s [%s]: test %d, %s", 
		fwts_framework_get_env(BIOS_TEST_TOOLKIT_FAILED_TEXT), fwts_log_level_to_str(level), fw->current_minor_test_num, buffer);


	va_end(ap);
}

void fwts_framework_warning(fwts_framework *fw, const char *fmt, ...)
{
	va_list ap;
	char buffer[1024];

	va_start(ap, fmt);

	vsnprintf(buffer, sizeof(buffer), fmt, ap);
	fwts_framework_debug(fw, "test %d WARNING: %s.", fw->current_minor_test_num, buffer);
	fw->minor_tests.warning++;
	fwts_log_printf(fw->results, LOG_RESULT, LOG_LEVEL_MEDIUM, "%s: test %d, %s", 
		fwts_framework_get_env(BIOS_TEST_TOOLKIT_WARNING_TEXT), fw->current_minor_test_num, buffer);

	va_end(ap);
}

static void fwts_framework_show_version(char * const *argv)
{
	printf("%s, Version %s, %s\n", argv[0], FWTS_VERSION, FWTS_DATE);
}

static void fwts_framework_strdup(char **ptr, const char *str)
{
	if (ptr == NULL)
		return;

	if (*ptr)
		free(*ptr);
	*ptr = strdup(str);
}

static void fwts_framework_syntax(char * const *argv)
{
	int i;
	typedef struct {
		char *opt;
		char *info;
	} fwts_syntax_info;

	static fwts_syntax_info syntax_help[] = {
		{ "Arguments:",			NULL },
		{ "-a, --all",			"Run all tests." },
		{ "-b, --batch",		"Just run non-interactive tests." },
		{ "--batch-experimental",	"Just run Batch Experimental tests." },
		{ "--debug-output=file",	"Output debug to a named file." },
		{ "",				"Filename can also be stdout or stderr." },
		{ "--dmidecode=path",		"Specify path to dmidecode table." },
		{ "-d, --dump",			"Dump out logs." },
		{ "-f, --force-clean",		"Force a clean results log file." },
		{ "--fwts-debug",		"Enable run-time test suite framework debug." },
		{ "-h, --help",			"Print this help." },
		{ "--iasl=path",		"Specify path to iasl." },
		{ "-i, --interactive",		"Just run interactive tests." },
		{ "--interactive-experimental",	"Just run Interactive Experimental tests." },
		{ "--klog=file",		"Specify kernel log file rather than reading it" },
		{ "",				"from the kernel." },
		{ "--log-fields",		"Show available log filtering fields." },
		{ "--log-filter=expr",		"Define filters to dump out specific log fields:" },
		{ "\te.g. --log-filter=RES,SUM  - dump out results and summary.", NULL },
		{ "\t     --log-filter=ALL,~INF - dump out all fields except info fields.", NULL },
		{ "--log-format=fields",	"Define output log format." },
		{ "\te.g. --log-format=\"\%date \%time [\%field] (\%owner): \"", NULL },
		{ "\tfields: \%date  - date",	NULL },
		{ "\t\t\%time  - time", 	NULL },
		{ "\t\t\%field - log filter field",	NULL },
		{ "\t\t\%owner - name of test program",	NULL },
		{ "\t\t\%level - failure test level",	NULL },
		{ "\t\t\%line  - log line number",	NULL },
		{ "--lspci=path",		"Specify path to lspci." },
		{ "--no-s3",			"Don't run S3 suspend/resume tests." },
		{ "",				"  deprecated, use --skip_test=s3 instead." },
		{ "--no-s4",			"Don't run S4 hibernate/resume tests." },
		{ "",				"  deprecated, use --skip_test=s4 instead." },
		{ "-P, --power-states",		"Test S3, S4 power states." },
		{ "--results-no-separators",	"No horizontal separators in results log." },
		{ "-r, --results-output=file",	"Output results to a named file. Filename can" },
		{ "",				"also be stdout or stderr." },
		{ "--s3-delay-delta=N",		"Time to be added to delay between S3 iterations." },
		{ "--s3-min-delay=N",		"Minimum time between S3 iterations." },
		{ "--s3-max-delay=N",		"tMaximum time between S3 iterations." },
		{ "--s3-multiple=N",		"Run S3 tests N times." },
		{ "--s4-multiple=N",		"Run S4 tests N times." },
		{ "-p, --show-progress",	"Output test progress report to stderr." },
		{ "-D, --show-progess-dialog",	"Output test progress for use in dialog tool." },
		{ "-s, --show-tests",		"Show available tests." },
		{ "-S, --skip_test=t1[,t2]",	"Ship tests named t1, t2.." },
		{ "--stdout-summary",		"Output SUCCESS or FAILED to stdout at end of tests." },
		{ "--table-path=path",		"Path to ACPI tables." },
		{ "-v, --version",		"Show version." },
		{ "-w, --log-width=N",		"Define the output log width in characters." },
		{ NULL, NULL }
	};

	printf("Usage %s: [OPTION] [TEST]\n", argv[0]);
	for (i=0; syntax_help[i].opt != NULL; i++) 
		if (syntax_help[i].info) 
			printf("%-28.28s %s\n", syntax_help[i].opt, syntax_help[i].info);
		else
			printf("%s\n", syntax_help[i].opt);

}

static void fwts_framework_heading_info(fwts_framework *fw, fwts_list *tests_to_run)
{
	struct tm tm;
	time_t now;
	struct utsname buf;
	char *tests = NULL;
	int len = 1;
	fwts_list_link *item;

	time(&now);
	localtime_r(&now, &tm);

	uname(&buf);

	fwts_log_info(fw, "Results generated by fwts: Version %s (built %s).", FWTS_VERSION, FWTS_DATE);
	fwts_log_nl(fw);
	fwts_log_info(fw, "This test run on %2.2d/%2.2d/%-2.2d at %2.2d:%2.2d:%2.2d on host %s %s %s %s %s.",
		tm.tm_mday, tm.tm_mon, (tm.tm_year+1900) % 100,
		tm.tm_hour, tm.tm_min, tm.tm_sec,
		buf.sysname, buf.nodename, buf.release, buf.version, buf.machine);
	fwts_log_nl(fw);
	
	for (item = tests_to_run->head; item != NULL; item = item->next) {
		fwts_framework_test *test = (fwts_framework_test*)item->data;
		len += strlen(test->name) + 1;
	}

	if ((tests = calloc(len, 1)) != NULL) {
		for (item = tests_to_run->head; item != NULL; item = item->next) {
			fwts_framework_test *test = (fwts_framework_test*)item->data;
			if (item != tests_to_run->head) 
				strcat(tests, " ");
			strcat(tests, test->name);
		}

		fwts_log_info(fw, "Running tests: %s.\n", 
			fwts_list_len(tests_to_run) == 0 ? "None" : tests);
		fwts_log_newline(fw->results);
		free(tests);
	}
}

static fwts_framework_test *fwts_framework_skip_test(fwts_list *tests_to_skip, fwts_framework_test *test)
{
	fwts_list_link *item;

	for (item = tests_to_skip->head; item != NULL; item = item->next)
		if (test == (fwts_framework_test*)item->data)
			return test;

	return NULL;
}

static int fwts_framework_skip_test_parse(fwts_framework *fw, const char *arg, fwts_list *tests_to_skip)
{
	char *str;
	char *token;
	char *saveptr = NULL;
	fwts_framework_test *test;

	for (str = (char*)arg; (token = strtok_r(str, ",", &saveptr)) != NULL; str = NULL) {
		if ((test = fwts_framework_test_find(fw, token)) == NULL) {
			fprintf(stderr, "No such test '%s'\n", token);
			return FWTS_ERROR;
		} else
			fwts_list_append(tests_to_skip, test);
	}

	return FWTS_OK;
}

int fwts_framework_args(const int argc, char * const *argv)
{
	int ret = FWTS_OK;

	struct option long_options[] = {
		{ "stdout-summary", 0, 0, 0 },		
		{ "fwts-debug", 0, 0, 0 },
		{ "help", 0, 0, 0 },
		{ "results-output", 1, 0, 0 },
		{ "results-no-separators", 0, 0, 0 },
		{ "debug-output", 1, 0, 0 },
		{ "log-filter", 1, 0, 0 },
		{ "log-fields", 0, 0, 0 },	
		{ "log-format", 1, 0, 0 },
		{ "iasl", 1, 0, 0 },
		{ "show-progress", 0, 0, 0 },
		{ "show-tests", 0, 0, 0 },
		{ "klog", 1, 0, 0, },
		{ "dmidecode", 1, 0, 0, },
		{ "s3-multiple", 1, 0, 0, },
		{ "no-s3", 0, 0, 0 },
		{ "no-s4", 0, 0, 0 },
		{ "log-width", 1, 0, 0 },
		{ "lspci", 1, 0, 0, },
		{ "batch", 0, 0, 0 },
		{ "interactive", 0, 0, 0 },
		{ "force-clean", 0, 0, 0 },
		{ "version", 0, 0, 0 },
		{ "dump", 0, 0, 0 },
		{ "s4-multiple", 1, 0, 0, },
		{ "table-path", 1, 0, 0 },
		{ "batch-experimental", 0, 0, 0 },
		{ "interactive-experimental", 0, 0, 0 },
		{ "s3-min-delay", 1, 0, 0 },
		{ "s3-max-delay", 1, 0, 0 },
		{ "s3-delay-delta", 1, 0, 0 },
		{ "power-states", 0, 0, 0 },
		{ "all", 0, 0, 0 },
		{ "show-progress-dialog", 0, 0, 0 },
		{ "skip-test", 1, 0, 0 },
		{ 0, 0, 0, 0 }
	};

	fwts_list *tests_to_run;
	fwts_list *tests_to_skip;
	fwts_framework *fw;

	if ((fw = (fwts_framework *)calloc(1, sizeof(fwts_framework))) == NULL)
		return FWTS_ERROR;

	fw->magic = FWTS_FRAMEWORK_MAGIC;
	fw->flags = FWTS_FRAMEWORK_FLAGS_DEFAULT;

	fw->s3_min_delay = 0;
	fw->s3_max_delay = 30;
	fw->s3_delay_delta = 0.5;

	fwts_summary_init();

	fwts_framework_strdup(&fw->iasl, FWTS_IASL_PATH);
	fwts_framework_strdup(&fw->dmidecode, FWTS_DMIDECODE_PATH);
	fwts_framework_strdup(&fw->lspci, FWTS_LSPCI_PATH);
	fwts_framework_strdup(&fw->debug_logname, "stderr");
	fwts_framework_strdup(&fw->results_logname, RESULTS_LOG);

	tests_to_run  = fwts_list_init();
	tests_to_skip = fwts_list_init();
	if ((tests_to_run == NULL) || (tests_to_skip == NULL)) {
		fwts_log_error(fw, "Run out of memory preparing to run tests.");
		goto tidy_close;
	}

	for (;;) {
		int c;
		int option_index;

		if ((c = getopt_long(argc, argv, "?r:vfhbipsw:dDPaS:", long_options, &option_index)) == -1)
			break;
	
		switch (c) {
		case 0:
			switch (option_index) {
			case 0: /* --stdout-summary */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_STDOUT_SUMMARY;
				break;	
			case 1: /* --fwts_framework_-debug */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_FRAMEWORK_DEBUG;
				break;		
			case 2: /* --help */
				fwts_framework_syntax(argv);
				goto tidy_close;
			case 3: /* --results-output */
				fwts_framework_strdup(&fw->results_logname, optarg);
				break;
			case 4: /* --results-no-separators */
				fwts_log_filter_unset_field(LOG_SEPARATOR);
				break;
			case 5: /* --debug-output */
				fwts_framework_strdup(&fw->debug_logname, optarg);
				fw->flags |= FWTS_FRAMEWORK_FLAGS_FRAMEWORK_DEBUG;
				break;
			case 6: /* --log-filter */
				fwts_log_filter_unset_field(~0);
				fwts_log_set_field_filter(optarg);
				break;
			case 7: /* --log-fields */
				fwts_log_print_fields();
				goto tidy_close;
				break;
			case 8: /* --log-format */
				fwts_log_set_format(optarg);
				break;	
			case 9: /* --iasl */
				fwts_framework_strdup(&fw->iasl, optarg);
				break;
			case 10: /* --show-progress */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_SHOW_PROGRESS;
				break;
			case 11: /* --show-tests */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_SHOW_TESTS;
				break;
			case 12: /* --klog */
				fwts_framework_strdup(&fw->klog, optarg);
				break;
			case 13: /* --dmidecode */
				fwts_framework_strdup(&fw->dmidecode, optarg);
				break;
			case 14: /* --s3-multiple */
				fw->s3_multiple = atoi(optarg);
				break;
			case 15: /* --no-s3 */
				fwts_framework_skip_test_parse(fw, "s3", tests_to_skip);
				fprintf(stderr, "--no-s3 is deprecated, use --skip-tests s3 or -S s3\n");
				break;
			case 16: /* --no-s4 */
				fwts_framework_skip_test_parse(fw, "s4", tests_to_skip);
				fprintf(stderr, "--no-s4 is deprecated, use --skip-tests s4 or -S s4\n");
				break;
			case 17: /* --log-width=N */
				fwts_log_set_line_width(atoi(optarg));
				break;
			case 18: /* --lspci=pathtolspci */
				fwts_framework_strdup(&fw->lspci, optarg);
				break;
			case 19: /* --batch */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_BATCH;
				break;
			case 20: /* --interactive */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_INTERACTIVE;
				break;
			case 21: /* --force-clean */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_FORCE_CLEAN;
				break;
			case 22: /* --version */
				fwts_framework_show_version(argv);
				goto tidy_close;
				break;
			case 23: /* --dump */
				fwts_dump_info(fw, NULL);
				goto tidy_close;
				break;
			case 24: /* --s4-multiple */
				fw->s4_multiple = atoi(optarg);
				break;
			case 25: /* --table-path */
				fwts_framework_strdup(&fw->acpi_table_path, optarg);
				break;
			case 26: /* --batch-experimental */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_BATCH_EXPERIMENTAL;
				break;
			case 27: /* --interactive-experimental */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_INTERACTIVE_EXPERIMENTAL;
				break;
			case 28: /* --s3-min-delay */
				fw->s3_min_delay = atoi(optarg);
				break;
			case 29: /* --s3-max-delay */
				fw->s3_max_delay = atoi(optarg);
				break;
			case 30: /* --s3-delay-delta */
				fw->s3_delay_delta = atof(optarg);
				break;
			case 31: /* --power-states */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_POWER_STATES;
				break;
			case 32: /* --all */
				fw->flags |= FWTS_RUN_ALL_FLAGS;
				break;
			case 33: /* --show-progress */
				fw->flags |= FWTS_FRAMEWORK_FLAGS_SHOW_PROGRESS_DIALOG;
				break;
			case 34: /* --skip-test */
				if (fwts_framework_skip_test_parse(fw, optarg, tests_to_skip) != FWTS_OK)
					goto tidy_close;
				break;
			}
			break;
		case 'a': /* --all */
			fw->flags |= FWTS_RUN_ALL_FLAGS;
			break;
		case 'd': /* --dump */
			fwts_dump_info(fw, NULL);
			goto tidy_close;
			break;
		case 'f':
			fw->flags |= FWTS_FRAMEWORK_FLAGS_FORCE_CLEAN;
			break;
		case 'h':
		case '?':
			fwts_framework_syntax(argv);
			goto tidy_close;
			break;
		case 'b': /* --batch */
			fw->flags |= FWTS_FRAMEWORK_FLAGS_BATCH;
			break;
		case 'i': /* --interactive */
			fw->flags |= FWTS_FRAMEWORK_FLAGS_INTERACTIVE;
			break;
		case 'p': /* --show-progress */
			fw->flags |= FWTS_FRAMEWORK_FLAGS_SHOW_PROGRESS;
			break;
		case 'D': /* --show-progress-dialog */
			fw->flags |= FWTS_FRAMEWORK_FLAGS_SHOW_PROGRESS_DIALOG;
			break;
		case 's': /* --show-tests */
			fw->flags |= FWTS_FRAMEWORK_FLAGS_SHOW_TESTS;
			break;
		case 'S': /* --skip-test */
			if (fwts_framework_skip_test_parse(fw, optarg, tests_to_skip) != FWTS_OK)
				goto tidy_close;
			break;
		case 'w': /* --log-width=N */
			fwts_log_set_line_width(atoi(optarg));
			break;
		case 'r': /* --results-output */
			fwts_framework_strdup(&fw->results_logname, optarg);
			break;
		case 'P': /* --power-states */
			fw->flags |= FWTS_FRAMEWORK_FLAGS_POWER_STATES;
			break;
		case 'v': /* --version */
			fwts_framework_show_version(argv);
			goto tidy_close;
			break;
		}
	}	

	if ((fw->s3_min_delay < 0) || (fw->s3_min_delay > 3600)) {
		fprintf(stderr, "--s3-min-delay cannot be less than zero or more than 1 hour!\n");
		goto tidy_close;
	}
	if (fw->s3_max_delay < fw->s3_min_delay || fw->s3_max_delay > 3600)  {
		fprintf(stderr, "--s3-max-delay cannot be less than --s3-min-delay or more than 1 hour!\n");
		goto tidy_close;
	}
	if (fw->s3_delay_delta <= 0.001) {
		fprintf(stderr, "--s3-delay_delta cannot be less than 0.001\n");
		goto tidy_close;
	}

	if (fw->flags & FWTS_FRAMEWORK_FLAGS_SHOW_TESTS) {
		fwts_framework_show_tests(fw);
		goto tidy_close;
	}

	if ((fw->flags & FWTS_RUN_ALL_FLAGS) == 0)
		fw->flags |= FWTS_FRAMEWORK_FLAGS_BATCH;

	if ((fw->iasl == NULL) ||
	    (fw->dmidecode == NULL) ||
	    (fw->lspci == NULL) || 
	    (fw->debug_logname == NULL) ||
	    (fw->results_logname == NULL)) {
		ret = FWTS_ERROR;
		fprintf(stderr, "%s: Memory allocation failure.", argv[0]);
		goto tidy_close;
	}

	if ((fw->debug = fwts_log_open("fwts", 
			fw->debug_logname, "a+")) == NULL) {
		ret = FWTS_ERROR;
		fprintf(stderr, "%s: Cannot open debug log.\n", argv[0]);
		goto tidy_close;
	}

	
	if ((fw->results = fwts_log_open("fwts", 
			fw->results_logname, 
			fw->flags & FWTS_FRAMEWORK_FLAGS_FORCE_CLEAN ? "w" : "a")) == NULL) {
		ret = FWTS_ERROR;
		fprintf(stderr, "%s: Cannot open results log '%s'.\n", argv[0], fw->results_logname);
		goto tidy_close;
	}


	if (optind < argc)  {
		/* Run specified tests */
		for (; optind < argc; optind++) {
			fwts_framework_test *test = fwts_framework_test_find(fw, argv[optind]);

			if (test == NULL) {
				fprintf(stderr, "No such test '%s'\n",argv[optind]);
				fwts_framework_show_tests(fw);
				ret = FWTS_ERROR;
				goto tidy;
			}

			if (fwts_framework_skip_test(tests_to_skip, test) == NULL) 
				fwts_list_append(tests_to_run, test);
		}
	} else  {
		/* Find tests that are eligible for running */
		fwts_list_link *item;
		for (item = fwts_framework_test_list->head; item != NULL; item = item->next) {
			fwts_framework_test *test = (fwts_framework_test*)item->data;
			if (fw->flags & test->flags & FWTS_RUN_ALL_FLAGS)
				if (fwts_framework_skip_test(tests_to_skip, test) == NULL) 
					fwts_list_append(tests_to_run, test);
		}
	}

	printf("Running %d tests, results written to %s\n", 
		fwts_list_len(tests_to_run),
		fw->results_logname);

	fwts_framework_heading_info(fw, tests_to_run);
	fwts_framework_tests_run(fw, tests_to_run);

	fwts_log_set_owner(fw->results, "summary");
	fwts_log_summary(fw, "");
	fwts_framework_total_summary(fw);
	fwts_log_summary(fw, "");
	fwts_summary_report(fw);

tidy:
	fwts_list_free(tests_to_skip, NULL);
	fwts_list_free(tests_to_run, NULL);
	fwts_log_close(fw->results);
	fwts_log_close(fw->debug);

tidy_close:
	fwts_acpi_free_tables();
	fwts_summary_deinit();
	fwts_framework_close(fw);

	return ret;
}
