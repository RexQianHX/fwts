/*
 * Copyright (C) 2014 Canonical
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

#ifndef __AUTH_VAR_DEF_H__
#define __AUTH_VAR_DEF_H__

/*
 * AuthVarCreate,
 * timestamp: 2014.09.08:03:41:15
 * GUID: 7f5c5d52-2f14-4f12-967cdb60db05a0fd
 * attributes = UEFI_VAR_NON_VOLATILE, UEFI_VAR_BOOTSERVICE_ACCESS,
 *		UEFI_VAR_RUNTIME_ACCESS, UEFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS
 * Variable name: AuthVarTest
 * data content: 1234567890abcdef
 */
static uint8_t AuthVarCreate[] = {
	0xde, 0x07, 0x09, 0x08, 0x03, 0x29, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0b, 0x05, 0x00, 0x00, 0x00, 0x02, 0xf1, 0x0e,
	0x9d, 0xd2, 0xaf, 0x4a, 0xdf, 0x68, 0xee, 0x49, 0x8a, 0xa9, 0x34, 0x7d,
	0x37, 0x56, 0x65, 0xa7, 0x30, 0x82, 0x04, 0xef, 0x06, 0x09, 0x2a, 0x86,
	0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x02, 0xa0, 0x82, 0x04, 0xe0, 0x30,
	0x82, 0x04, 0xdc, 0x02, 0x01, 0x01, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x09,
	0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x30,
	0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01,
	0xa0, 0x82, 0x02, 0xfd, 0x30, 0x82, 0x02, 0xf9, 0x30, 0x82, 0x01, 0xe1,
	0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x09, 0x00, 0xbb, 0x94, 0x92, 0x5f,
	0x3b, 0x5e, 0xd3, 0x2d, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
	0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x30, 0x13, 0x31, 0x11, 0x30,
	0x0f, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x08, 0x74, 0x65, 0x73, 0x74,
	0x2d, 0x6b, 0x65, 0x79, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x34, 0x30, 0x38,
	0x31, 0x32, 0x31, 0x30, 0x32, 0x31, 0x33, 0x30, 0x5a, 0x17, 0x0d, 0x31,
	0x34, 0x30, 0x39, 0x31, 0x31, 0x31, 0x30, 0x32, 0x31, 0x33, 0x30, 0x5a,
	0x30, 0x13, 0x31, 0x11, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c,
	0x08, 0x74, 0x65, 0x73, 0x74, 0x2d, 0x6b, 0x65, 0x79, 0x30, 0x82, 0x01,
	0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
	0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01,
	0x0a, 0x02, 0x82, 0x01, 0x01, 0x00, 0xe5, 0xbf, 0x24, 0xb1, 0x10, 0x46,
	0x55, 0xad, 0x70, 0x77, 0x14, 0xc3, 0x1b, 0x55, 0xa0, 0x72, 0xfa, 0x3c,
	0x3c, 0x44, 0x3e, 0xc3, 0xd7, 0xfa, 0x05, 0x94, 0xeb, 0x70, 0x6a, 0xe3,
	0x47, 0x58, 0xb5, 0xab, 0x83, 0x6e, 0x7a, 0x43, 0xdd, 0x51, 0x9a, 0x31,
	0x4a, 0x4a, 0x4f, 0xf0, 0x65, 0xfe, 0xae, 0x10, 0x30, 0xf8, 0xaa, 0x69,
	0x54, 0xaf, 0xff, 0x4b, 0x3d, 0x48, 0x5d, 0x09, 0x9c, 0x94, 0x87, 0x3a,
	0xf6, 0x56, 0xeb, 0xb6, 0x80, 0x07, 0x77, 0x1e, 0x92, 0x8b, 0x19, 0xc3,
	0xa6, 0x8b, 0x4b, 0x0f, 0x60, 0x8f, 0x88, 0xca, 0x89, 0x41, 0x1d, 0x18,
	0xb6, 0xde, 0x16, 0x75, 0xaa, 0xaa, 0xa7, 0xba, 0x88, 0xbd, 0x0f, 0x62,
	0x27, 0x7e, 0xe1, 0x11, 0x67, 0x6a, 0xf2, 0x8a, 0xd9, 0xf0, 0xc2, 0x56,
	0x60, 0x7f, 0xfd, 0xd7, 0x62, 0x71, 0x75, 0x8f, 0x09, 0xf8, 0x52, 0x37,
	0xc9, 0xf2, 0xef, 0x56, 0xd5, 0x81, 0x95, 0xb3, 0x7f, 0xd9, 0xcc, 0xf4,
	0xbc, 0xd0, 0x5e, 0x8c, 0x8b, 0x78, 0x14, 0x2a, 0xe0, 0x3d, 0xc5, 0xd1,
	0xf2, 0x46, 0xd4, 0xab, 0xbe, 0xd0, 0x30, 0x5c, 0xb6, 0x29, 0x62, 0x48,
	0x0f, 0xc7, 0x62, 0xa5, 0x9e, 0x9c, 0xc8, 0x29, 0xfc, 0x7e, 0xa8, 0x96,
	0xc4, 0x25, 0xc1, 0x8c, 0x2a, 0x33, 0x9d, 0xe3, 0x2e, 0x5b, 0x30, 0xff,
	0x62, 0xaf, 0xae, 0x48, 0xc6, 0x37, 0x3a, 0xb6, 0x93, 0x15, 0x23, 0x80,
	0x45, 0xa2, 0xfd, 0x3b, 0x43, 0x99, 0xf1, 0x88, 0x77, 0x82, 0x79, 0x39,
	0x5f, 0x48, 0x98, 0x3f, 0xb6, 0xc3, 0xbd, 0x1c, 0xcd, 0xd4, 0xf4, 0x2d,
	0x7d, 0x37, 0x5a, 0xcb, 0xbc, 0xae, 0xdc, 0x77, 0xa2, 0x0f, 0x72, 0x56,
	0xd7, 0xd4, 0xec, 0x59, 0x9d, 0xd9, 0x60, 0x7a, 0xf9, 0x26, 0x94, 0xda,
	0xfd, 0x7c, 0x5c, 0xe8, 0x15, 0x7e, 0x9a, 0xe9, 0x3d, 0x71, 0x02, 0x03,
	0x01, 0x00, 0x01, 0xa3, 0x50, 0x30, 0x4e, 0x30, 0x1d, 0x06, 0x03, 0x55,
	0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x8b, 0x37, 0x99, 0x6d, 0x76, 0x3f,
	0xc5, 0x2b, 0x48, 0xf8, 0x0d, 0x61, 0xf2, 0x62, 0x8e, 0xc6, 0xe7, 0xd5,
	0xb6, 0x4e, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30,
	0x16, 0x80, 0x14, 0x8b, 0x37, 0x99, 0x6d, 0x76, 0x3f, 0xc5, 0x2b, 0x48,
	0xf8, 0x0d, 0x61, 0xf2, 0x62, 0x8e, 0xc6, 0xe7, 0xd5, 0xb6, 0x4e, 0x30,
	0x0c, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01,
	0xff, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
	0x01, 0x0b, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0xb2, 0x28, 0xe3,
	0x94, 0x02, 0x6f, 0xe5, 0x2a, 0xdc, 0x29, 0x7d, 0xcf, 0x2b, 0x88, 0x09,
	0x4f, 0x73, 0x8a, 0xc3, 0x54, 0xfc, 0xa3, 0x40, 0x84, 0x82, 0xce, 0x32,
	0x8d, 0x75, 0x51, 0xa2, 0xc3, 0x3f, 0x01, 0x0f, 0xde, 0x1b, 0x1f, 0x48,
	0xdb, 0x8f, 0xf9, 0xe0, 0xf3, 0x23, 0x78, 0x17, 0x4a, 0x84, 0xbc, 0xf4,
	0x84, 0xb5, 0xe5, 0x8c, 0x17, 0x36, 0x7f, 0x4f, 0x6f, 0x54, 0x47, 0xbd,
	0xe6, 0x40, 0xb0, 0x8a, 0x73, 0x74, 0x65, 0x57, 0x98, 0xf6, 0x77, 0x58,
	0x0e, 0x5f, 0x82, 0x77, 0xb3, 0xd9, 0x87, 0xf8, 0xe9, 0x21, 0x11, 0x37,
	0x4c, 0x6e, 0x5f, 0xda, 0x1e, 0x81, 0xa6, 0xa3, 0x45, 0x09, 0x81, 0x26,
	0xd0, 0xb6, 0xe1, 0x27, 0xa5, 0xc3, 0x6e, 0xed, 0x86, 0xb7, 0x4f, 0xf3,
	0x7e, 0x34, 0xa5, 0x0b, 0x8a, 0xd1, 0x56, 0x65, 0x04, 0xe2, 0x16, 0x71,
	0x11, 0xdc, 0xa8, 0xa6, 0xe0, 0x57, 0x91, 0x63, 0xe2, 0x9d, 0xe7, 0x86,
	0x00, 0xa6, 0xb4, 0x75, 0xf3, 0x37, 0x63, 0x48, 0x41, 0xcd, 0x97, 0x12,
	0x2e, 0x5c, 0xc0, 0xf0, 0x13, 0x62, 0x71, 0xc1, 0x8e, 0x65, 0x28, 0x52,
	0x09, 0x71, 0x87, 0x33, 0x27, 0x77, 0x84, 0x2f, 0xb4, 0x9a, 0x0a, 0x62,
	0xe6, 0x69, 0x05, 0xd7, 0x94, 0x70, 0x8a, 0xb9, 0x61, 0x68, 0xdb, 0xbd,
	0x4b, 0x58, 0xd3, 0x74, 0x0e, 0x3e, 0x00, 0x6c, 0x64, 0x02, 0x22, 0x4f,
	0x62, 0xbe, 0xe1, 0x53, 0x96, 0xa5, 0x6a, 0x7d, 0xf7, 0x8c, 0x77, 0x42,
	0x49, 0xb3, 0xb0, 0x44, 0xf1, 0xa9, 0xd5, 0x64, 0xdf, 0xcc, 0x8b, 0x90,
	0x03, 0x05, 0xb8, 0x07, 0x5f, 0x6e, 0x88, 0x11, 0x7e, 0x93, 0x85, 0xe6,
	0x3c, 0x87, 0x92, 0x74, 0xbb, 0xfe, 0x01, 0x32, 0xe8, 0x0b, 0xa9, 0xab,
	0x15, 0xd4, 0x8a, 0x4f, 0xd7, 0x40, 0x12, 0xe1, 0xde, 0x8a, 0xa8, 0x7c,
	0xf5, 0x31, 0x82, 0x01, 0xb6, 0x30, 0x82, 0x01, 0xb2, 0x02, 0x01, 0x01,
	0x30, 0x20, 0x30, 0x13, 0x31, 0x11, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x04,
	0x03, 0x0c, 0x08, 0x74, 0x65, 0x73, 0x74, 0x2d, 0x6b, 0x65, 0x79, 0x02,
	0x09, 0x00, 0xbb, 0x94, 0x92, 0x5f, 0x3b, 0x5e, 0xd3, 0x2d, 0x30, 0x0d,
	0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
	0x00, 0xa0, 0x69, 0x30, 0x18, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
	0x0d, 0x01, 0x09, 0x03, 0x31, 0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
	0xf7, 0x0d, 0x01, 0x07, 0x01, 0x30, 0x1c, 0x06, 0x09, 0x2a, 0x86, 0x48,
	0x86, 0xf7, 0x0d, 0x01, 0x09, 0x05, 0x31, 0x0f, 0x17, 0x0d, 0x31, 0x34,
	0x31, 0x30, 0x30, 0x38, 0x30, 0x33, 0x34, 0x31, 0x31, 0x35, 0x5a, 0x30,
	0x2f, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x04,
	0x31, 0x22, 0x04, 0x20, 0x7d, 0x9f, 0x1b, 0x65, 0x76, 0x70, 0x66, 0xe3,
	0xa0, 0x6a, 0x53, 0x01, 0xd9, 0xde, 0x6f, 0x6a, 0x88, 0xcb, 0x76, 0xb3,
	0xf8, 0xd6, 0xc4, 0x45, 0x3a, 0x8f, 0x7b, 0x9d, 0x06, 0x50, 0xc6, 0x12,
	0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
	0x01, 0x05, 0x00, 0x04, 0x82, 0x01, 0x00, 0xb5, 0x61, 0x49, 0xea, 0xfc,
	0xfe, 0x13, 0xfc, 0xd5, 0x92, 0x5a, 0xf5, 0x11, 0x88, 0x2a, 0xba, 0x0f,
	0x3d, 0x3d, 0x56, 0x8a, 0x69, 0x2b, 0xcc, 0x3a, 0x95, 0x09, 0xb6, 0x06,
	0xd9, 0x36, 0x17, 0x63, 0x40, 0xd7, 0xc8, 0x5a, 0xb3, 0xca, 0x2d, 0xd2,
	0xea, 0xa0, 0x9a, 0x82, 0x04, 0x75, 0x66, 0xeb, 0x41, 0x9b, 0x1a, 0x23,
	0x70, 0xf0, 0xf1, 0x1a, 0x69, 0x0b, 0xb2, 0x8d, 0x8f, 0x7f, 0x6a, 0x96,
	0x2a, 0x77, 0x30, 0x0c, 0x06, 0xff, 0x1c, 0x9d, 0x71, 0x41, 0xe3, 0x91,
	0x22, 0xbc, 0xaf, 0xb5, 0x39, 0x0d, 0xb6, 0x5b, 0x03, 0x0b, 0xf1, 0xa6,
	0x98, 0xb4, 0x15, 0xce, 0x23, 0x09, 0xcf, 0xad, 0x7c, 0xb9, 0x41, 0x2e,
	0xf4, 0x9f, 0x50, 0x49, 0x13, 0xf7, 0x87, 0x07, 0x7e, 0x5e, 0x9c, 0xc0,
	0x79, 0x61, 0xfb, 0xa2, 0xf4, 0xf7, 0x3c, 0xa1, 0xb7, 0x1b, 0x68, 0x56,
	0x5c, 0x04, 0x74, 0x97, 0xdc, 0xf5, 0x3e, 0x07, 0x93, 0xd5, 0x43, 0xb7,
	0x36, 0xb9, 0xc9, 0xc8, 0x65, 0x4c, 0x24, 0xce, 0x58, 0x6d, 0x9e, 0x60,
	0x54, 0x10, 0x6c, 0xb5, 0x4e, 0xbe, 0x47, 0x9b, 0xef, 0x31, 0xa1, 0xdc,
	0x0c, 0x84, 0xe5, 0xff, 0xd2, 0xdd, 0x2d, 0x8e, 0xa1, 0x7e, 0x9f, 0x02,
	0x98, 0x46, 0x1a, 0x7f, 0x6e, 0x4f, 0x70, 0x68, 0x4a, 0x1d, 0xa7, 0x9c,
	0x0e, 0x1d, 0x42, 0xaf, 0x6f, 0x0f, 0x6d, 0x8f, 0x91, 0x69, 0x6a, 0xff,
	0x73, 0x86, 0xc6, 0xc3, 0x24, 0x7d, 0x60, 0x67, 0xb4, 0xae, 0xa8, 0xb4,
	0x19, 0xba, 0x7a, 0x61, 0xc9, 0xad, 0xcc, 0xcf, 0x9f, 0xfe, 0x13, 0x1e,
	0xc3, 0x2c, 0xfd, 0x3a, 0x25, 0xdf, 0xa2, 0xc6, 0xb2, 0x15, 0x18, 0x54,
	0xbd, 0x51, 0xc1, 0x84, 0x62, 0x0f, 0x72, 0x8d, 0x67, 0xce, 0xe6, 0xbd,
	0x6e, 0x21, 0x58, 0x1f, 0x77, 0xf4, 0xfc, 0x36, 0xf9, 0x0c, 0x1d, 0x31,
	0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x61, 0x62, 0x63,
	0x64, 0x65, 0x66
};

static uint8_t AuthVarCreateData[] = {0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66};

/*
 * AuthVarDel,
 * timestamp: 2014.09.08:06:10:26
 * GUID: 7f5c5d52-2f14-4f12-967cdb60db05a0fd
 * attributes = UEFI_VAR_NON_VOLATILE, UEFI_VAR_BOOTSERVICE_ACCESS,
 *		UEFI_VAR_RUNTIME_ACCESS, UEFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS
 * Variable name: AuthVarTest
 * data content: empty
 */
static uint8_t AuthVarDel[] = {
	0xde, 0x07, 0x09, 0x08, 0x06, 0x0a, 0x1a, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0b, 0x05, 0x00, 0x00, 0x00, 0x02, 0xf1, 0x0e,
	0x9d, 0xd2, 0xaf, 0x4a, 0xdf, 0x68, 0xee, 0x49, 0x8a, 0xa9, 0x34, 0x7d,
	0x37, 0x56, 0x65, 0xa7, 0x30, 0x82, 0x04, 0xef, 0x06, 0x09, 0x2a, 0x86,
	0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x02, 0xa0, 0x82, 0x04, 0xe0, 0x30,
	0x82, 0x04, 0xdc, 0x02, 0x01, 0x01, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x09,
	0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x30,
	0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01,
	0xa0, 0x82, 0x02, 0xfd, 0x30, 0x82, 0x02, 0xf9, 0x30, 0x82, 0x01, 0xe1,
	0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x09, 0x00, 0xbb, 0x94, 0x92, 0x5f,
	0x3b, 0x5e, 0xd3, 0x2d, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
	0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x30, 0x13, 0x31, 0x11, 0x30,
	0x0f, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x08, 0x74, 0x65, 0x73, 0x74,
	0x2d, 0x6b, 0x65, 0x79, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x34, 0x30, 0x38,
	0x31, 0x32, 0x31, 0x30, 0x32, 0x31, 0x33, 0x30, 0x5a, 0x17, 0x0d, 0x31,
	0x34, 0x30, 0x39, 0x31, 0x31, 0x31, 0x30, 0x32, 0x31, 0x33, 0x30, 0x5a,
	0x30, 0x13, 0x31, 0x11, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c,
	0x08, 0x74, 0x65, 0x73, 0x74, 0x2d, 0x6b, 0x65, 0x79, 0x30, 0x82, 0x01,
	0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
	0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01,
	0x0a, 0x02, 0x82, 0x01, 0x01, 0x00, 0xe5, 0xbf, 0x24, 0xb1, 0x10, 0x46,
	0x55, 0xad, 0x70, 0x77, 0x14, 0xc3, 0x1b, 0x55, 0xa0, 0x72, 0xfa, 0x3c,
	0x3c, 0x44, 0x3e, 0xc3, 0xd7, 0xfa, 0x05, 0x94, 0xeb, 0x70, 0x6a, 0xe3,
	0x47, 0x58, 0xb5, 0xab, 0x83, 0x6e, 0x7a, 0x43, 0xdd, 0x51, 0x9a, 0x31,
	0x4a, 0x4a, 0x4f, 0xf0, 0x65, 0xfe, 0xae, 0x10, 0x30, 0xf8, 0xaa, 0x69,
	0x54, 0xaf, 0xff, 0x4b, 0x3d, 0x48, 0x5d, 0x09, 0x9c, 0x94, 0x87, 0x3a,
	0xf6, 0x56, 0xeb, 0xb6, 0x80, 0x07, 0x77, 0x1e, 0x92, 0x8b, 0x19, 0xc3,
	0xa6, 0x8b, 0x4b, 0x0f, 0x60, 0x8f, 0x88, 0xca, 0x89, 0x41, 0x1d, 0x18,
	0xb6, 0xde, 0x16, 0x75, 0xaa, 0xaa, 0xa7, 0xba, 0x88, 0xbd, 0x0f, 0x62,
	0x27, 0x7e, 0xe1, 0x11, 0x67, 0x6a, 0xf2, 0x8a, 0xd9, 0xf0, 0xc2, 0x56,
	0x60, 0x7f, 0xfd, 0xd7, 0x62, 0x71, 0x75, 0x8f, 0x09, 0xf8, 0x52, 0x37,
	0xc9, 0xf2, 0xef, 0x56, 0xd5, 0x81, 0x95, 0xb3, 0x7f, 0xd9, 0xcc, 0xf4,
	0xbc, 0xd0, 0x5e, 0x8c, 0x8b, 0x78, 0x14, 0x2a, 0xe0, 0x3d, 0xc5, 0xd1,
	0xf2, 0x46, 0xd4, 0xab, 0xbe, 0xd0, 0x30, 0x5c, 0xb6, 0x29, 0x62, 0x48,
	0x0f, 0xc7, 0x62, 0xa5, 0x9e, 0x9c, 0xc8, 0x29, 0xfc, 0x7e, 0xa8, 0x96,
	0xc4, 0x25, 0xc1, 0x8c, 0x2a, 0x33, 0x9d, 0xe3, 0x2e, 0x5b, 0x30, 0xff,
	0x62, 0xaf, 0xae, 0x48, 0xc6, 0x37, 0x3a, 0xb6, 0x93, 0x15, 0x23, 0x80,
	0x45, 0xa2, 0xfd, 0x3b, 0x43, 0x99, 0xf1, 0x88, 0x77, 0x82, 0x79, 0x39,
	0x5f, 0x48, 0x98, 0x3f, 0xb6, 0xc3, 0xbd, 0x1c, 0xcd, 0xd4, 0xf4, 0x2d,
	0x7d, 0x37, 0x5a, 0xcb, 0xbc, 0xae, 0xdc, 0x77, 0xa2, 0x0f, 0x72, 0x56,
	0xd7, 0xd4, 0xec, 0x59, 0x9d, 0xd9, 0x60, 0x7a, 0xf9, 0x26, 0x94, 0xda,
	0xfd, 0x7c, 0x5c, 0xe8, 0x15, 0x7e, 0x9a, 0xe9, 0x3d, 0x71, 0x02, 0x03,
	0x01, 0x00, 0x01, 0xa3, 0x50, 0x30, 0x4e, 0x30, 0x1d, 0x06, 0x03, 0x55,
	0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x8b, 0x37, 0x99, 0x6d, 0x76, 0x3f,
	0xc5, 0x2b, 0x48, 0xf8, 0x0d, 0x61, 0xf2, 0x62, 0x8e, 0xc6, 0xe7, 0xd5,
	0xb6, 0x4e, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30,
	0x16, 0x80, 0x14, 0x8b, 0x37, 0x99, 0x6d, 0x76, 0x3f, 0xc5, 0x2b, 0x48,
	0xf8, 0x0d, 0x61, 0xf2, 0x62, 0x8e, 0xc6, 0xe7, 0xd5, 0xb6, 0x4e, 0x30,
	0x0c, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01,
	0xff, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
	0x01, 0x0b, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0xb2, 0x28, 0xe3,
	0x94, 0x02, 0x6f, 0xe5, 0x2a, 0xdc, 0x29, 0x7d, 0xcf, 0x2b, 0x88, 0x09,
	0x4f, 0x73, 0x8a, 0xc3, 0x54, 0xfc, 0xa3, 0x40, 0x84, 0x82, 0xce, 0x32,
	0x8d, 0x75, 0x51, 0xa2, 0xc3, 0x3f, 0x01, 0x0f, 0xde, 0x1b, 0x1f, 0x48,
	0xdb, 0x8f, 0xf9, 0xe0, 0xf3, 0x23, 0x78, 0x17, 0x4a, 0x84, 0xbc, 0xf4,
	0x84, 0xb5, 0xe5, 0x8c, 0x17, 0x36, 0x7f, 0x4f, 0x6f, 0x54, 0x47, 0xbd,
	0xe6, 0x40, 0xb0, 0x8a, 0x73, 0x74, 0x65, 0x57, 0x98, 0xf6, 0x77, 0x58,
	0x0e, 0x5f, 0x82, 0x77, 0xb3, 0xd9, 0x87, 0xf8, 0xe9, 0x21, 0x11, 0x37,
	0x4c, 0x6e, 0x5f, 0xda, 0x1e, 0x81, 0xa6, 0xa3, 0x45, 0x09, 0x81, 0x26,
	0xd0, 0xb6, 0xe1, 0x27, 0xa5, 0xc3, 0x6e, 0xed, 0x86, 0xb7, 0x4f, 0xf3,
	0x7e, 0x34, 0xa5, 0x0b, 0x8a, 0xd1, 0x56, 0x65, 0x04, 0xe2, 0x16, 0x71,
	0x11, 0xdc, 0xa8, 0xa6, 0xe0, 0x57, 0x91, 0x63, 0xe2, 0x9d, 0xe7, 0x86,
	0x00, 0xa6, 0xb4, 0x75, 0xf3, 0x37, 0x63, 0x48, 0x41, 0xcd, 0x97, 0x12,
	0x2e, 0x5c, 0xc0, 0xf0, 0x13, 0x62, 0x71, 0xc1, 0x8e, 0x65, 0x28, 0x52,
	0x09, 0x71, 0x87, 0x33, 0x27, 0x77, 0x84, 0x2f, 0xb4, 0x9a, 0x0a, 0x62,
	0xe6, 0x69, 0x05, 0xd7, 0x94, 0x70, 0x8a, 0xb9, 0x61, 0x68, 0xdb, 0xbd,
	0x4b, 0x58, 0xd3, 0x74, 0x0e, 0x3e, 0x00, 0x6c, 0x64, 0x02, 0x22, 0x4f,
	0x62, 0xbe, 0xe1, 0x53, 0x96, 0xa5, 0x6a, 0x7d, 0xf7, 0x8c, 0x77, 0x42,
	0x49, 0xb3, 0xb0, 0x44, 0xf1, 0xa9, 0xd5, 0x64, 0xdf, 0xcc, 0x8b, 0x90,
	0x03, 0x05, 0xb8, 0x07, 0x5f, 0x6e, 0x88, 0x11, 0x7e, 0x93, 0x85, 0xe6,
	0x3c, 0x87, 0x92, 0x74, 0xbb, 0xfe, 0x01, 0x32, 0xe8, 0x0b, 0xa9, 0xab,
	0x15, 0xd4, 0x8a, 0x4f, 0xd7, 0x40, 0x12, 0xe1, 0xde, 0x8a, 0xa8, 0x7c,
	0xf5, 0x31, 0x82, 0x01, 0xb6, 0x30, 0x82, 0x01, 0xb2, 0x02, 0x01, 0x01,
	0x30, 0x20, 0x30, 0x13, 0x31, 0x11, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x04,
	0x03, 0x0c, 0x08, 0x74, 0x65, 0x73, 0x74, 0x2d, 0x6b, 0x65, 0x79, 0x02,
	0x09, 0x00, 0xbb, 0x94, 0x92, 0x5f, 0x3b, 0x5e, 0xd3, 0x2d, 0x30, 0x0d,
	0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
	0x00, 0xa0, 0x69, 0x30, 0x18, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
	0x0d, 0x01, 0x09, 0x03, 0x31, 0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
	0xf7, 0x0d, 0x01, 0x07, 0x01, 0x30, 0x1c, 0x06, 0x09, 0x2a, 0x86, 0x48,
	0x86, 0xf7, 0x0d, 0x01, 0x09, 0x05, 0x31, 0x0f, 0x17, 0x0d, 0x31, 0x34,
	0x31, 0x30, 0x30, 0x38, 0x30, 0x36, 0x31, 0x30, 0x32, 0x36, 0x5a, 0x30,
	0x2f, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x04,
	0x31, 0x22, 0x04, 0x20, 0xa7, 0x2d, 0xb1, 0x8a, 0xc3, 0x9b, 0x15, 0xb9,
	0xd8, 0x72, 0x1b, 0x33, 0x4e, 0xf7, 0x46, 0xaf, 0x62, 0x26, 0xa7, 0x6d,
	0x18, 0xfa, 0x16, 0x92, 0x9f, 0x90, 0x25, 0x47, 0x5d, 0x2c, 0x12, 0x39,
	0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
	0x01, 0x05, 0x00, 0x04, 0x82, 0x01, 0x00, 0xdc, 0xe7, 0xf2, 0xa2, 0xea,
	0x24, 0x38, 0x52, 0xbf, 0xd1, 0x66, 0xfc, 0xb5, 0x74, 0xf8, 0x5b, 0x6d,
	0x82, 0x20, 0xbc, 0xb5, 0x6f, 0x60, 0x9e, 0xab, 0xe9, 0x8e, 0xcd, 0x22,
	0x99, 0x85, 0xdd, 0xb5, 0xc8, 0x5e, 0x3c, 0x9b, 0x1a, 0xe8, 0x06, 0xfb,
	0x7f, 0x07, 0x91, 0xe6, 0x14, 0xbb, 0x7c, 0xce, 0x86, 0xc7, 0xbe, 0x03,
	0x0f, 0x14, 0x60, 0x59, 0x24, 0x96, 0xc7, 0xb0, 0x9a, 0x77, 0x66, 0x7a,
	0xed, 0x0f, 0x0c, 0xaa, 0x1b, 0xc2, 0x40, 0xa1, 0x8e, 0x2e, 0x8a, 0x27,
	0x57, 0x08, 0xce, 0x3c, 0x4e, 0xd6, 0x4c, 0xcf, 0x1c, 0xc2, 0x8b, 0xef,
	0xf1, 0x96, 0x2f, 0x29, 0xbc, 0x48, 0x03, 0x7f, 0x58, 0x53, 0x58, 0x49,
	0x0a, 0x3e, 0x49, 0x3c, 0x14, 0xed, 0x1f, 0x04, 0x56, 0x99, 0x3e, 0x01,
	0xfb, 0x5d, 0x47, 0xd2, 0xdf, 0xdd, 0x00, 0x6a, 0x65, 0x43, 0x42, 0x2a,
	0xb5, 0xd1, 0xb8, 0x09, 0xf1, 0x82, 0xfd, 0x9e, 0x0e, 0x56, 0x66, 0xf3,
	0x03, 0x52, 0x1a, 0x75, 0x8f, 0x13, 0x2c, 0x92, 0x3c, 0x08, 0xb7, 0x95,
	0xdf, 0x45, 0x31, 0xde, 0xc0, 0x62, 0x45, 0x54, 0xbf, 0x1e, 0xfc, 0xd0,
	0x7e, 0xc1, 0x51, 0xc7, 0x2a, 0x8a, 0xef, 0x31, 0x92, 0xf8, 0x48, 0x1d,
	0x61, 0x87, 0x4b, 0x9a, 0x70, 0xdc, 0x93, 0x12, 0x97, 0x72, 0x6e, 0x6d,
	0xbc, 0xeb, 0x7f, 0x83, 0x3d, 0x54, 0x83, 0xae, 0x6a, 0x7a, 0x47, 0x04,
	0xd3, 0xc0, 0xee, 0xc7, 0x85, 0x0f, 0xd6, 0x89, 0x48, 0xc0, 0x68, 0xe3,
	0x6c, 0x86, 0xcd, 0x17, 0xc0, 0x8d, 0xaa, 0xfd, 0xc6, 0x0d, 0xa6, 0xc4,
	0xc3, 0xef, 0xc5, 0xcc, 0x47, 0xf9, 0x0c, 0x21, 0xe8, 0x86, 0xcb, 0x93,
	0xe0, 0x37, 0x21, 0x2b, 0xa9, 0xe3, 0x7e, 0x6a, 0x6c, 0xde, 0x3e, 0x68,
	0x65, 0xb6, 0xff, 0xbf, 0xbd, 0x08, 0xe1, 0xed, 0x0c, 0x19, 0xb2
};

/*
 * AuthVarCreateDiffer, the same as AuthVarCreate, but using different valid key and new timestamp
 * timestamp: 2014.09.08:05:52:01
 * GUID: 7f5c5d52-2f14-4f12-967cdb60db05a0fd
 * attributes = UEFI_VAR_NON_VOLATILE, UEFI_VAR_BOOTSERVICE_ACCESS,
 *		UEFI_VAR_RUNTIME_ACCESS, UEFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS
 * Variable name: AuthVarTest
 * data content: 1234567890abcdef
 */
static uint8_t AuthVarCreateDiff[] = {
	0xde, 0x07, 0x09, 0x08, 0x05, 0x34, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0b, 0x05, 0x00, 0x00, 0x00, 0x02, 0xf1, 0x0e,
	0x9d, 0xd2, 0xaf, 0x4a, 0xdf, 0x68, 0xee, 0x49, 0x8a, 0xa9, 0x34, 0x7d,
	0x37, 0x56, 0x65, 0xa7, 0x30, 0x82, 0x04, 0xef, 0x06, 0x09, 0x2a, 0x86,
	0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x02, 0xa0, 0x82, 0x04, 0xe0, 0x30,
	0x82, 0x04, 0xdc, 0x02, 0x01, 0x01, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x09,
	0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x30,
	0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01,
	0xa0, 0x82, 0x02, 0xfd, 0x30, 0x82, 0x02, 0xf9, 0x30, 0x82, 0x01, 0xe1,
	0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x09, 0x00, 0xe2, 0x7d, 0x10, 0xea,
	0xd8, 0x0d, 0x98, 0x77, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
	0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x30, 0x13, 0x31, 0x11, 0x30,
	0x0f, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x08, 0x74, 0x65, 0x73, 0x74,
	0x2d, 0x6b, 0x65, 0x79, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x34, 0x31, 0x30,
	0x30, 0x38, 0x30, 0x35, 0x34, 0x39, 0x35, 0x38, 0x5a, 0x17, 0x0d, 0x31,
	0x34, 0x31, 0x31, 0x30, 0x37, 0x30, 0x35, 0x34, 0x39, 0x35, 0x38, 0x5a,
	0x30, 0x13, 0x31, 0x11, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c,
	0x08, 0x74, 0x65, 0x73, 0x74, 0x2d, 0x6b, 0x65, 0x79, 0x30, 0x82, 0x01,
	0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
	0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01,
	0x0a, 0x02, 0x82, 0x01, 0x01, 0x00, 0xb2, 0x11, 0xba, 0xfc, 0xb3, 0xb5,
	0xe9, 0xb4, 0xf4, 0x66, 0xc7, 0xe7, 0xa8, 0xed, 0xd1, 0xdb, 0xd9, 0xb2,
	0xb4, 0x72, 0x0e, 0x7a, 0xc2, 0x00, 0xd1, 0xa3, 0x3f, 0x24, 0xa7, 0xc9,
	0x9f, 0xef, 0x14, 0x07, 0x48, 0x2f, 0x6a, 0x54, 0xdb, 0xde, 0x72, 0xa8,
	0xdd, 0xba, 0x2c, 0x61, 0x14, 0xd4, 0x53, 0x54, 0xe7, 0x96, 0xfd, 0xa1,
	0x26, 0x05, 0x63, 0x1d, 0xd7, 0x1a, 0x70, 0xf8, 0xb5, 0x3d, 0x40, 0xc0,
	0x33, 0x35, 0x8a, 0xe9, 0x88, 0x8a, 0x8a, 0x7d, 0x56, 0x39, 0x9b, 0x70,
	0x4a, 0x07, 0xd9, 0xc2, 0x44, 0xe2, 0x12, 0x2e, 0x8b, 0x78, 0x9e, 0x14,
	0x99, 0x7a, 0x47, 0x92, 0x9e, 0x42, 0x0f, 0x76, 0xb7, 0x3d, 0x1f, 0xb4,
	0x20, 0xd2, 0x6d, 0x93, 0xdf, 0x2e, 0xb1, 0x00, 0xa9, 0x94, 0xe0, 0x0b,
	0xe6, 0x57, 0x25, 0x76, 0x99, 0x63, 0xa7, 0x4c, 0x0b, 0x44, 0x48, 0x59,
	0xbe, 0x52, 0xfb, 0x64, 0xca, 0xe0, 0x21, 0x8e, 0xaf, 0xdc, 0xa5, 0xb2,
	0x5b, 0x4a, 0x80, 0x7e, 0xe2, 0x95, 0xa5, 0x95, 0xb7, 0x75, 0x19, 0x44,
	0x77, 0x1b, 0x8f, 0xa0, 0x57, 0xc7, 0xb5, 0x33, 0x7f, 0xbb, 0x5b, 0x41,
	0x63, 0xde, 0xc8, 0xdd, 0x4a, 0x41, 0x98, 0x1a, 0xc0, 0x36, 0xed, 0x8d,
	0x4c, 0xc9, 0x2f, 0x19, 0x39, 0xf4, 0xf4, 0x31, 0xb4, 0x4e, 0x78, 0xff,
	0xab, 0x91, 0xe6, 0xf2, 0x23, 0xdc, 0x79, 0x24, 0x54, 0xba, 0x05, 0x60,
	0x2c, 0xad, 0x29, 0xeb, 0x8e, 0xa0, 0x2d, 0x73, 0x09, 0xbd, 0xdf, 0xe3,
	0x76, 0x98, 0x04, 0x4d, 0x29, 0x7d, 0xdd, 0xd2, 0xbd, 0xa8, 0x32, 0x66,
	0x45, 0x01, 0xff, 0xd7, 0xd0, 0x83, 0xfb, 0xec, 0xaa, 0xb7, 0x45, 0x34,
	0xf4, 0xd8, 0xf1, 0x23, 0x0e, 0x15, 0x84, 0xde, 0x59, 0xe5, 0x2e, 0x06,
	0xd6, 0xb8, 0x11, 0x1d, 0x59, 0xc9, 0x93, 0xea, 0x4e, 0x4b, 0x02, 0x03,
	0x01, 0x00, 0x01, 0xa3, 0x50, 0x30, 0x4e, 0x30, 0x1d, 0x06, 0x03, 0x55,
	0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0xe5, 0x35, 0x8b, 0x82, 0xc5, 0xf0,
	0x10, 0x89, 0x6b, 0xe2, 0xdd, 0x60, 0x20, 0x5a, 0xd6, 0x17, 0x1e, 0x17,
	0x2a, 0xb8, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30,
	0x16, 0x80, 0x14, 0xe5, 0x35, 0x8b, 0x82, 0xc5, 0xf0, 0x10, 0x89, 0x6b,
	0xe2, 0xdd, 0x60, 0x20, 0x5a, 0xd6, 0x17, 0x1e, 0x17, 0x2a, 0xb8, 0x30,
	0x0c, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01,
	0xff, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
	0x01, 0x0b, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0x8d, 0x9e, 0x39,
	0xf2, 0xf8, 0x1f, 0xb3, 0x71, 0x2b, 0x2d, 0xcb, 0x22, 0xf7, 0x23, 0x88,
	0xd4, 0x60, 0xee, 0xb1, 0xf7, 0xce, 0x39, 0x0d, 0xfd, 0xe5, 0x77, 0x5e,
	0x69, 0xf1, 0x39, 0xc6, 0x4b, 0x16, 0x30, 0xc4, 0x95, 0x70, 0x29, 0x3b,
	0x48, 0xe7, 0x6c, 0x33, 0x1d, 0x28, 0xa3, 0x87, 0x0e, 0xcf, 0xd3, 0x63,
	0x1b, 0x1a, 0x51, 0x61, 0xa7, 0x4a, 0x30, 0x47, 0xbc, 0xbc, 0x10, 0xe0,
	0x6e, 0x7b, 0x49, 0x2b, 0x77, 0xa8, 0x31, 0x0b, 0xfa, 0x64, 0xfe, 0x06,
	0x6f, 0xab, 0x59, 0x70, 0x31, 0xcc, 0x94, 0x63, 0x3a, 0x9b, 0xea, 0x8b,
	0xc2, 0xaa, 0x30, 0xed, 0xe0, 0x09, 0x7f, 0x16, 0x60, 0xf3, 0xc6, 0x5b,
	0xcb, 0x7e, 0xed, 0xab, 0x54, 0x8d, 0x46, 0x1f, 0x29, 0xa3, 0xa7, 0x8c,
	0xea, 0xb5, 0xed, 0xbe, 0x80, 0x00, 0x5f, 0x01, 0xbe, 0xa7, 0x92, 0x4f,
	0x3b, 0xe5, 0xc8, 0x3c, 0x93, 0x41, 0xbf, 0x51, 0x1e, 0x09, 0x99, 0xbe,
	0xb7, 0x65, 0x88, 0x93, 0x82, 0x26, 0x9b, 0x90, 0xc7, 0xb8, 0xea, 0x6b,
	0x79, 0x0f, 0xf4, 0x5e, 0x1a, 0x8f, 0x77, 0xdd, 0xa6, 0x7a, 0x53, 0xd4,
	0x9f, 0xb9, 0xab, 0x97, 0xdf, 0x40, 0xd8, 0x42, 0xfd, 0x1a, 0xa7, 0xa9,
	0x90, 0x0c, 0x98, 0x7e, 0xb1, 0x5e, 0xff, 0xeb, 0xd6, 0xec, 0x65, 0xce,
	0xd2, 0x4e, 0xd1, 0x71, 0x4b, 0xd5, 0xb8, 0x78, 0x64, 0xc2, 0x5f, 0xaf,
	0x50, 0x20, 0xa6, 0xf0, 0xba, 0x62, 0xa3, 0xe5, 0x38, 0xa2, 0x9f, 0x17,
	0xda, 0x65, 0xe6, 0x94, 0x1c, 0xa0, 0xc0, 0xf0, 0xf9, 0x5f, 0xeb, 0xdc,
	0x05, 0x70, 0x73, 0x60, 0xa5, 0x54, 0x89, 0x22, 0x84, 0x93, 0x79, 0x27,
	0xe6, 0xf6, 0x51, 0x72, 0x3e, 0x86, 0xd4, 0x7f, 0x0b, 0xb7, 0xed, 0xc4,
	0x09, 0x0f, 0xac, 0xf5, 0x58, 0x88, 0x10, 0xee, 0x8a, 0xc2, 0xeb, 0x12,
	0xe4, 0x31, 0x82, 0x01, 0xb6, 0x30, 0x82, 0x01, 0xb2, 0x02, 0x01, 0x01,
	0x30, 0x20, 0x30, 0x13, 0x31, 0x11, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x04,
	0x03, 0x0c, 0x08, 0x74, 0x65, 0x73, 0x74, 0x2d, 0x6b, 0x65, 0x79, 0x02,
	0x09, 0x00, 0xe2, 0x7d, 0x10, 0xea, 0xd8, 0x0d, 0x98, 0x77, 0x30, 0x0d,
	0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
	0x00, 0xa0, 0x69, 0x30, 0x18, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
	0x0d, 0x01, 0x09, 0x03, 0x31, 0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
	0xf7, 0x0d, 0x01, 0x07, 0x01, 0x30, 0x1c, 0x06, 0x09, 0x2a, 0x86, 0x48,
	0x86, 0xf7, 0x0d, 0x01, 0x09, 0x05, 0x31, 0x0f, 0x17, 0x0d, 0x31, 0x34,
	0x31, 0x30, 0x30, 0x38, 0x30, 0x35, 0x35, 0x32, 0x30, 0x31, 0x5a, 0x30,
	0x2f, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x04,
	0x31, 0x22, 0x04, 0x20, 0xe8, 0xd3, 0xd1, 0xba, 0xf4, 0x1b, 0x87, 0xd3,
	0x4a, 0x66, 0x07, 0x67, 0xd5, 0x92, 0xe5, 0x9b, 0xba, 0xfc, 0xcf, 0xf0,
	0xd8, 0xc7, 0xa6, 0xa7, 0x74, 0xce, 0x27, 0x9c, 0x9f, 0x3e, 0xaa, 0x18,
	0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
	0x01, 0x05, 0x00, 0x04, 0x82, 0x01, 0x00, 0x14, 0xdb, 0xa1, 0x1a, 0x65,
	0x21, 0xa7, 0x00, 0x3a, 0xd4, 0x4a, 0x49, 0x08, 0x90, 0x34, 0x8b, 0xbe,
	0x6d, 0x52, 0x1d, 0x0c, 0xf6, 0x21, 0xcc, 0xdd, 0x4d, 0xb2, 0x0d, 0xc9,
	0x0f, 0x79, 0x87, 0x19, 0x05, 0xaf, 0x1f, 0xc3, 0x8b, 0xd0, 0x52, 0xb4,
	0x60, 0xf0, 0x28, 0x62, 0xd9, 0x70, 0xd5, 0x1b, 0xeb, 0x58, 0xea, 0x5f,
	0x3a, 0x78, 0x3d, 0x3d, 0x55, 0x63, 0xca, 0xf3, 0xf0, 0xce, 0x38, 0x8f,
	0x06, 0xf6, 0x21, 0x61, 0x63, 0x61, 0x37, 0xf6, 0x3d, 0x59, 0x14, 0x66,
	0xcc, 0x2f, 0xdf, 0x52, 0x73, 0x8d, 0x32, 0xf2, 0xb9, 0x99, 0x02, 0x4f,
	0xcb, 0xcc, 0x9e, 0x93, 0xdf, 0xf9, 0x1b, 0x71, 0x38, 0x19, 0x56, 0x15,
	0xd5, 0xc1, 0x7c, 0x29, 0x67, 0x85, 0x69, 0x64, 0xf4, 0xeb, 0x79, 0x76,
	0x83, 0x6d, 0x0d, 0x88, 0x87, 0x0a, 0x6e, 0xbb, 0xc4, 0xbf, 0x88, 0x2f,
	0xa4, 0xe2, 0xd3, 0x19, 0x77, 0xbc, 0xd4, 0xa0, 0x20, 0xf9, 0xc0, 0x79,
	0x0c, 0x39, 0x5d, 0x11, 0xcd, 0x6e, 0xc4, 0x8d, 0x75, 0xb0, 0xb9, 0x81,
	0x66, 0xf1, 0x9e, 0xa7, 0x17, 0x6c, 0x23, 0xde, 0x5a, 0x42, 0x50, 0x85,
	0x29, 0xbc, 0x05, 0x74, 0xe2, 0xa8, 0xbb, 0xb1, 0x86, 0xbf, 0x73, 0x4f,
	0x72, 0xa2, 0xa8, 0xc7, 0x7e, 0x23, 0x50, 0x18, 0x33, 0x24, 0x91, 0x08,
	0xfa, 0x43, 0x0b, 0xdc, 0xd3, 0x17, 0xd3, 0xc1, 0x43, 0x05, 0xda, 0xb2,
	0xc4, 0xa8, 0x34, 0xcc, 0x8b, 0x52, 0xdd, 0x86, 0xba, 0xe9, 0x69, 0xe3,
	0x87, 0x82, 0x91, 0xb9, 0x13, 0x78, 0x45, 0xc0, 0x50, 0x0c, 0xe6, 0xc9,
	0x0b, 0x9b, 0x19, 0x93, 0x38, 0x57, 0xe4, 0x3f, 0xfc, 0x6f, 0x9f, 0x07,
	0x96, 0x55, 0xba, 0x7c, 0x5d, 0x24, 0x12, 0xe6, 0x80, 0x54, 0x16, 0x49,
	0xfb, 0xd9, 0xc9, 0x54, 0xb9, 0x46, 0xe5, 0x18, 0xa1, 0x69, 0xa0, 0x31,
	0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x61, 0x62, 0x63,
	0x64, 0x65, 0x66
};

/*
 * AuthVarAppend,
 * timestamp: 2014.09.08:06:06:46
 * GUID: 7f5c5d52-2f14-4f12-967cdb60db05a0fd
 * attributes = UEFI_VAR_NON_VOLATILE, UEFI_VAR_BOOTSERVICE_ACCESS,
 *		UEFI_VAR_RUNTIME_ACCESS, UEFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS,
 * 		UEFI_VARIABLE_APPEND_WRITE
 * Variable name: AuthVarTest
 * data content: 9876543210
 */
static uint8_t AuthVarAppend[] = {
	0xde, 0x07, 0x09, 0x08, 0x06, 0x06, 0x2e, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x0b, 0x05, 0x00, 0x00, 0x00, 0x02, 0xf1, 0x0e,
	0x9d, 0xd2, 0xaf, 0x4a, 0xdf, 0x68, 0xee, 0x49, 0x8a, 0xa9, 0x34, 0x7d,
	0x37, 0x56, 0x65, 0xa7, 0x30, 0x82, 0x04, 0xef, 0x06, 0x09, 0x2a, 0x86,
	0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x02, 0xa0, 0x82, 0x04, 0xe0, 0x30,
	0x82, 0x04, 0xdc, 0x02, 0x01, 0x01, 0x31, 0x0f, 0x30, 0x0d, 0x06, 0x09,
	0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x30,
	0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01,
	0xa0, 0x82, 0x02, 0xfd, 0x30, 0x82, 0x02, 0xf9, 0x30, 0x82, 0x01, 0xe1,
	0xa0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x09, 0x00, 0xbb, 0x94, 0x92, 0x5f,
	0x3b, 0x5e, 0xd3, 0x2d, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
	0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x30, 0x13, 0x31, 0x11, 0x30,
	0x0f, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x08, 0x74, 0x65, 0x73, 0x74,
	0x2d, 0x6b, 0x65, 0x79, 0x30, 0x1e, 0x17, 0x0d, 0x31, 0x34, 0x30, 0x38,
	0x31, 0x32, 0x31, 0x30, 0x32, 0x31, 0x33, 0x30, 0x5a, 0x17, 0x0d, 0x31,
	0x34, 0x30, 0x39, 0x31, 0x31, 0x31, 0x30, 0x32, 0x31, 0x33, 0x30, 0x5a,
	0x30, 0x13, 0x31, 0x11, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c,
	0x08, 0x74, 0x65, 0x73, 0x74, 0x2d, 0x6b, 0x65, 0x79, 0x30, 0x82, 0x01,
	0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
	0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01,
	0x0a, 0x02, 0x82, 0x01, 0x01, 0x00, 0xe5, 0xbf, 0x24, 0xb1, 0x10, 0x46,
	0x55, 0xad, 0x70, 0x77, 0x14, 0xc3, 0x1b, 0x55, 0xa0, 0x72, 0xfa, 0x3c,
	0x3c, 0x44, 0x3e, 0xc3, 0xd7, 0xfa, 0x05, 0x94, 0xeb, 0x70, 0x6a, 0xe3,
	0x47, 0x58, 0xb5, 0xab, 0x83, 0x6e, 0x7a, 0x43, 0xdd, 0x51, 0x9a, 0x31,
	0x4a, 0x4a, 0x4f, 0xf0, 0x65, 0xfe, 0xae, 0x10, 0x30, 0xf8, 0xaa, 0x69,
	0x54, 0xaf, 0xff, 0x4b, 0x3d, 0x48, 0x5d, 0x09, 0x9c, 0x94, 0x87, 0x3a,
	0xf6, 0x56, 0xeb, 0xb6, 0x80, 0x07, 0x77, 0x1e, 0x92, 0x8b, 0x19, 0xc3,
	0xa6, 0x8b, 0x4b, 0x0f, 0x60, 0x8f, 0x88, 0xca, 0x89, 0x41, 0x1d, 0x18,
	0xb6, 0xde, 0x16, 0x75, 0xaa, 0xaa, 0xa7, 0xba, 0x88, 0xbd, 0x0f, 0x62,
	0x27, 0x7e, 0xe1, 0x11, 0x67, 0x6a, 0xf2, 0x8a, 0xd9, 0xf0, 0xc2, 0x56,
	0x60, 0x7f, 0xfd, 0xd7, 0x62, 0x71, 0x75, 0x8f, 0x09, 0xf8, 0x52, 0x37,
	0xc9, 0xf2, 0xef, 0x56, 0xd5, 0x81, 0x95, 0xb3, 0x7f, 0xd9, 0xcc, 0xf4,
	0xbc, 0xd0, 0x5e, 0x8c, 0x8b, 0x78, 0x14, 0x2a, 0xe0, 0x3d, 0xc5, 0xd1,
	0xf2, 0x46, 0xd4, 0xab, 0xbe, 0xd0, 0x30, 0x5c, 0xb6, 0x29, 0x62, 0x48,
	0x0f, 0xc7, 0x62, 0xa5, 0x9e, 0x9c, 0xc8, 0x29, 0xfc, 0x7e, 0xa8, 0x96,
	0xc4, 0x25, 0xc1, 0x8c, 0x2a, 0x33, 0x9d, 0xe3, 0x2e, 0x5b, 0x30, 0xff,
	0x62, 0xaf, 0xae, 0x48, 0xc6, 0x37, 0x3a, 0xb6, 0x93, 0x15, 0x23, 0x80,
	0x45, 0xa2, 0xfd, 0x3b, 0x43, 0x99, 0xf1, 0x88, 0x77, 0x82, 0x79, 0x39,
	0x5f, 0x48, 0x98, 0x3f, 0xb6, 0xc3, 0xbd, 0x1c, 0xcd, 0xd4, 0xf4, 0x2d,
	0x7d, 0x37, 0x5a, 0xcb, 0xbc, 0xae, 0xdc, 0x77, 0xa2, 0x0f, 0x72, 0x56,
	0xd7, 0xd4, 0xec, 0x59, 0x9d, 0xd9, 0x60, 0x7a, 0xf9, 0x26, 0x94, 0xda,
	0xfd, 0x7c, 0x5c, 0xe8, 0x15, 0x7e, 0x9a, 0xe9, 0x3d, 0x71, 0x02, 0x03,
	0x01, 0x00, 0x01, 0xa3, 0x50, 0x30, 0x4e, 0x30, 0x1d, 0x06, 0x03, 0x55,
	0x1d, 0x0e, 0x04, 0x16, 0x04, 0x14, 0x8b, 0x37, 0x99, 0x6d, 0x76, 0x3f,
	0xc5, 0x2b, 0x48, 0xf8, 0x0d, 0x61, 0xf2, 0x62, 0x8e, 0xc6, 0xe7, 0xd5,
	0xb6, 0x4e, 0x30, 0x1f, 0x06, 0x03, 0x55, 0x1d, 0x23, 0x04, 0x18, 0x30,
	0x16, 0x80, 0x14, 0x8b, 0x37, 0x99, 0x6d, 0x76, 0x3f, 0xc5, 0x2b, 0x48,
	0xf8, 0x0d, 0x61, 0xf2, 0x62, 0x8e, 0xc6, 0xe7, 0xd5, 0xb6, 0x4e, 0x30,
	0x0c, 0x06, 0x03, 0x55, 0x1d, 0x13, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01,
	0xff, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01,
	0x01, 0x0b, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0xb2, 0x28, 0xe3,
	0x94, 0x02, 0x6f, 0xe5, 0x2a, 0xdc, 0x29, 0x7d, 0xcf, 0x2b, 0x88, 0x09,
	0x4f, 0x73, 0x8a, 0xc3, 0x54, 0xfc, 0xa3, 0x40, 0x84, 0x82, 0xce, 0x32,
	0x8d, 0x75, 0x51, 0xa2, 0xc3, 0x3f, 0x01, 0x0f, 0xde, 0x1b, 0x1f, 0x48,
	0xdb, 0x8f, 0xf9, 0xe0, 0xf3, 0x23, 0x78, 0x17, 0x4a, 0x84, 0xbc, 0xf4,
	0x84, 0xb5, 0xe5, 0x8c, 0x17, 0x36, 0x7f, 0x4f, 0x6f, 0x54, 0x47, 0xbd,
	0xe6, 0x40, 0xb0, 0x8a, 0x73, 0x74, 0x65, 0x57, 0x98, 0xf6, 0x77, 0x58,
	0x0e, 0x5f, 0x82, 0x77, 0xb3, 0xd9, 0x87, 0xf8, 0xe9, 0x21, 0x11, 0x37,
	0x4c, 0x6e, 0x5f, 0xda, 0x1e, 0x81, 0xa6, 0xa3, 0x45, 0x09, 0x81, 0x26,
	0xd0, 0xb6, 0xe1, 0x27, 0xa5, 0xc3, 0x6e, 0xed, 0x86, 0xb7, 0x4f, 0xf3,
	0x7e, 0x34, 0xa5, 0x0b, 0x8a, 0xd1, 0x56, 0x65, 0x04, 0xe2, 0x16, 0x71,
	0x11, 0xdc, 0xa8, 0xa6, 0xe0, 0x57, 0x91, 0x63, 0xe2, 0x9d, 0xe7, 0x86,
	0x00, 0xa6, 0xb4, 0x75, 0xf3, 0x37, 0x63, 0x48, 0x41, 0xcd, 0x97, 0x12,
	0x2e, 0x5c, 0xc0, 0xf0, 0x13, 0x62, 0x71, 0xc1, 0x8e, 0x65, 0x28, 0x52,
	0x09, 0x71, 0x87, 0x33, 0x27, 0x77, 0x84, 0x2f, 0xb4, 0x9a, 0x0a, 0x62,
	0xe6, 0x69, 0x05, 0xd7, 0x94, 0x70, 0x8a, 0xb9, 0x61, 0x68, 0xdb, 0xbd,
	0x4b, 0x58, 0xd3, 0x74, 0x0e, 0x3e, 0x00, 0x6c, 0x64, 0x02, 0x22, 0x4f,
	0x62, 0xbe, 0xe1, 0x53, 0x96, 0xa5, 0x6a, 0x7d, 0xf7, 0x8c, 0x77, 0x42,
	0x49, 0xb3, 0xb0, 0x44, 0xf1, 0xa9, 0xd5, 0x64, 0xdf, 0xcc, 0x8b, 0x90,
	0x03, 0x05, 0xb8, 0x07, 0x5f, 0x6e, 0x88, 0x11, 0x7e, 0x93, 0x85, 0xe6,
	0x3c, 0x87, 0x92, 0x74, 0xbb, 0xfe, 0x01, 0x32, 0xe8, 0x0b, 0xa9, 0xab,
	0x15, 0xd4, 0x8a, 0x4f, 0xd7, 0x40, 0x12, 0xe1, 0xde, 0x8a, 0xa8, 0x7c,
	0xf5, 0x31, 0x82, 0x01, 0xb6, 0x30, 0x82, 0x01, 0xb2, 0x02, 0x01, 0x01,
	0x30, 0x20, 0x30, 0x13, 0x31, 0x11, 0x30, 0x0f, 0x06, 0x03, 0x55, 0x04,
	0x03, 0x0c, 0x08, 0x74, 0x65, 0x73, 0x74, 0x2d, 0x6b, 0x65, 0x79, 0x02,
	0x09, 0x00, 0xbb, 0x94, 0x92, 0x5f, 0x3b, 0x5e, 0xd3, 0x2d, 0x30, 0x0d,
	0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x05,
	0x00, 0xa0, 0x69, 0x30, 0x18, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7,
	0x0d, 0x01, 0x09, 0x03, 0x31, 0x0b, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
	0xf7, 0x0d, 0x01, 0x07, 0x01, 0x30, 0x1c, 0x06, 0x09, 0x2a, 0x86, 0x48,
	0x86, 0xf7, 0x0d, 0x01, 0x09, 0x05, 0x31, 0x0f, 0x17, 0x0d, 0x31, 0x34,
	0x31, 0x30, 0x30, 0x38, 0x30, 0x36, 0x30, 0x36, 0x34, 0x36, 0x5a, 0x30,
	0x2f, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x09, 0x04,
	0x31, 0x22, 0x04, 0x20, 0xdf, 0xdc, 0xc0, 0x0e, 0xd3, 0xfd, 0xb4, 0x82,
	0xf6, 0x0f, 0x00, 0x31, 0x34, 0xdc, 0xd9, 0x26, 0xce, 0x71, 0x86, 0x0e,
	0x14, 0x8f, 0xdc, 0x22, 0x20, 0x96, 0xaa, 0x2e, 0x36, 0x0a, 0xbb, 0xf7,
	0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
	0x01, 0x05, 0x00, 0x04, 0x82, 0x01, 0x00, 0x0e, 0x9d, 0x75, 0xbe, 0x07,
	0x26, 0xa8, 0xe4, 0x13, 0x1f, 0x82, 0x62, 0xd5, 0x5d, 0xc1, 0xaf, 0x65,
	0xd1, 0xa5, 0xd7, 0x37, 0xe4, 0xe9, 0x30, 0xff, 0xf8, 0xc9, 0x7d, 0x07,
	0x1a, 0x6f, 0x67, 0x16, 0x1b, 0x56, 0x73, 0x4e, 0x64, 0xc7, 0x7e, 0xa9,
	0x7d, 0xdd, 0xe5, 0x23, 0x59, 0x71, 0x41, 0xf3, 0x8d, 0x4e, 0x1d, 0x26,
	0x6a, 0x63, 0x6d, 0x52, 0x9e, 0x62, 0x8b, 0xfa, 0xe0, 0x34, 0x37, 0xb1,
	0xd3, 0x1b, 0xbf, 0x7a, 0x33, 0x93, 0x18, 0x7c, 0xaa, 0xfa, 0x8e, 0x57,
	0x92, 0xb3, 0xe0, 0xf1, 0x52, 0x6e, 0x4c, 0xe3, 0xe8, 0x3c, 0x80, 0x27,
	0x60, 0xe3, 0xcc, 0x2d, 0xc4, 0xec, 0x0a, 0x76, 0xf2, 0xe1, 0xcc, 0xe2,
	0x00, 0xf9, 0x9d, 0x89, 0x44, 0x60, 0x97, 0x3b, 0x21, 0x73, 0x34, 0x97,
	0x09, 0x62, 0x9a, 0x8c, 0xd9, 0x61, 0x13, 0xa3, 0xc8, 0x38, 0xc3, 0xbb,
	0xa8, 0xdc, 0xa2, 0xbd, 0x80, 0xb1, 0xd7, 0x69, 0xe5, 0x02, 0xe5, 0xe4,
	0x0d, 0xa7, 0x5c, 0xfe, 0xb6, 0x5c, 0x87, 0x03, 0x56, 0x8d, 0xc5, 0x8a,
	0xc4, 0xac, 0x3e, 0x6c, 0xf9, 0xd4, 0xec, 0xe3, 0xf9, 0xf6, 0x54, 0x82,
	0x53, 0x61, 0x4c, 0xd4, 0xde, 0xb0, 0x85, 0xdb, 0x78, 0xe9, 0xef, 0xfc,
	0xa6, 0x20, 0x95, 0x6b, 0x32, 0xc4, 0x3f, 0xec, 0xa3, 0x80, 0x1e, 0x64,
	0x39, 0x55, 0x5e, 0x19, 0xea, 0x36, 0xc8, 0x1a, 0x1b, 0x0e, 0x37, 0xe2,
	0x82, 0xed, 0xb3, 0xfa, 0xec, 0xad, 0xa3, 0x4c, 0xb0, 0x38, 0xf5, 0xd8,
	0xe0, 0x75, 0xa0, 0x06, 0xf1, 0xb0, 0xff, 0x05, 0xc2, 0xe3, 0xc8, 0x73,
	0x5f, 0xb5, 0xc2, 0xc6, 0x24, 0x70, 0xb8, 0x1d, 0xd8, 0x48, 0x5f, 0x00,
	0xa8, 0x82, 0x84, 0xf8, 0xc4, 0x79, 0xc8, 0xdc, 0x52, 0x45, 0x4e, 0x28,
	0x1f, 0x82, 0x23, 0x8e, 0xd9, 0x30, 0xee, 0xeb, 0xdb, 0x3c, 0xbb, 0x39,
	0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31, 0x30
};

static uint8_t AuthVarAppendData[] = {0x39, 0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31, 0x30};

#endif
