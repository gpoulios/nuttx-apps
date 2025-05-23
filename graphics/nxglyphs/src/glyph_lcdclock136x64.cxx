/********************************************************************************************
 * apps/graphics/nxglyphs/src/glyph_lcdclock136x64.cxx
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ********************************************************************************************/

/********************************************************************************************
 * Included Files
 ********************************************************************************************/

#include <nuttx/config.h>
#include <sys/types.h>
#include <stdint.h>

#include "graphics/nxwidgets/crlepalettebitmap.hxx"
#include "graphics/nxglyphs.hxx"

/********************************************************************************************
 * Pre-Processor Definitions
 ********************************************************************************************/

#define BITMAP_NROWS     64
#define BITMAP_NCOLUMNS  136
#define BITMAP_NLUTCODES 56

/********************************************************************************************
 * Private Bitmap Data
 ********************************************************************************************/

using namespace NXWidgets;

#if CONFIG_NXWIDGETS_BPP == 24 ||  CONFIG_NXWIDGETS_BPP == 32
// RGB24 (8-8-8) Colors

static const uint32_t g_lcdClockNormalLut[BITMAP_NLUTCODES] =
{
  0x808c80, 0x7c887c, 0x748474, 0x788478, 0x748074, 0x788878, 0x3c543c, 0x002000,  /* Codes 0-7 */
  0x586c58, 0x647464, 0x304830, 0x546854, 0x203c20, 0x405440, 0x586858, 0x042404,  /* Codes 8-15 */
  0x385038, 0x4c604c, 0x2c442c, 0x6c786c, 0x708070, 0x607060, 0x506450, 0x082408,  /* Codes 16-23 */
  0x082808, 0x1c381c, 0x405840, 0x2c482c, 0x0c280c, 0x6c7c6c, 0x0c2c0c, 0x546454,  /* Codes 24-31 */
  0x284028, 0x506050, 0x5c705c, 0x243c24, 0x445844, 0x102c10, 0x103010, 0x687868,  /* Codes 32-39 */
  0x707c70, 0x344c34, 0x143014, 0x5c6c5c, 0x244024, 0x485c48, 0x203820, 0x3c503c,  /* Codes 40-47 */
  0x183418, 0x284428, 0x384c38, 0x143414, 0x445c44, 0x607460, 0x042004, 0xfcfc00,  /* Codes 48-55 */
};

static const uint32_t g_lcdClockBrightLut[BITMAP_NLUTCODES] =
{
  0x9fa89f, 0x9ca59c, 0x96a296, 0x99a299, 0x969f96, 0x99a599, 0x6c7e6c, 0x3f573f,  /* Codes 0-7 */
  0x819081, 0x8a968a, 0x637563, 0x7e8d7e, 0x576c57, 0x6f7e6f, 0x818d81, 0x425a42,  /* Codes 8-15 */
  0x697b69, 0x788778, 0x607260, 0x909990, 0x939f93, 0x879387, 0x7b8a7b, 0x455a45,  /* Codes 16-23 */
  0x455d45, 0x546954, 0x6f816f, 0x607560, 0x485d48, 0x909c90, 0x486048, 0x7e8a7e,  /* Codes 24-31 */
  0x5d6f5d, 0x7b877b, 0x849384, 0x5a6c5a, 0x728172, 0x4b604b, 0x4b634b, 0x8d998d,  /* Codes 32-39 */
  0x939c93, 0x667866, 0x4e634e, 0x849084, 0x5a6f5a, 0x758475, 0x576957, 0x6c7b6c,  /* Codes 40-47 */
  0x516651, 0x5d725d, 0x697869, 0x4e664e, 0x728472, 0x879687, 0x425742, 0xfcfc3f,  /* Codes 48-55 */
};

#elif CONFIG_NXWIDGETS_BPP == 16
// RGB16 (565) Colors (four of the colors in this map are duplicates)

static const uint16_t g_lcdClockNormalLut[BITMAP_NLUTCODES] =
{
  0x8470, 0x7c4f, 0x742e, 0x7c2f, 0x740e, 0x7c4f, 0x3aa7, 0x0100, 0x5b6b, 0x63ac,  /* Codes 0-9 */
  0x3246, 0x534a, 0x21e4, 0x42a8, 0x5b4b, 0x0120, 0x3a87, 0x4b09, 0x2a25, 0x6bcd,  /* Codes 10-19 */
  0x740e, 0x638c, 0x532a, 0x0921, 0x0941, 0x19c3, 0x42c8, 0x2a45, 0x0941, 0x6bed,  /* Codes 20-29 */
  0x0961, 0x532a, 0x2a05, 0x530a, 0x5b8b, 0x21e4, 0x42c8, 0x1162, 0x1182, 0x6bcd,  /* Codes 30-39 */
  0x73ee, 0x3266, 0x1182, 0x5b6b, 0x2204, 0x4ae9, 0x21c4, 0x3a87, 0x19a3, 0x2a25,  /* Codes 40-49 */
  0x3a67, 0x11a2, 0x42e8, 0x63ac, 0x0100, 0xffe0,  /* Codes 50-55 */
};

static const uint16_t g_lcdClockBrightLut[BITMAP_NLUTCODES] =
{
  0x9d53, 0x9d33, 0x9512, 0x9d13, 0x94f2, 0x9d33, 0x6bed, 0x3aa7, 0x8490, 0x8cb1,  /* Codes 0-9 */
  0x63ac, 0x7c6f, 0x536a, 0x6bed, 0x8470, 0x42c8, 0x6bcd, 0x7c2f, 0x638c, 0x94d2,  /* Codes 10-19 */
  0x94f2, 0x8490, 0x7c4f, 0x42c8, 0x42e8, 0x534a, 0x6c0d, 0x63ac, 0x4ae9, 0x94f2,  /* Codes 20-29 */
  0x4b09, 0x7c4f, 0x5b6b, 0x7c2f, 0x8490, 0x5b6b, 0x740e, 0x4b09, 0x4b09, 0x8cd1,  /* Codes 30-39 */
  0x94f2, 0x63cc, 0x4b09, 0x8490, 0x5b6b, 0x742e, 0x534a, 0x6bcd, 0x532a, 0x5b8b,  /* Codes 40-49 */
  0x6bcd, 0x4b29, 0x742e, 0x84b0, 0x42a8, 0xffe7,  /* Codes 50-55 */
};

#elif CONFIG_NXWIDGETS_BPP == 8
// 8-bit color lookups.  NOTE:  This is really dumb!  The lookup index is 8-bits and it used
// to lookup an 8-bit value.  There is no savings in that!  It would be better to just put
// the 8-bit color/greyscale value in the run-length encoded image and save the cost of these
// pointless lookups.  But these p;ointless lookups do make the logic compatible with the
// 16- and 24-bit types.
///

#  ifdef CONFIG_NXWIDGETS_GREYSCALE
// 8-bit Greyscale

static const uint8_t g_lcdClockNormalLut[BITMAP_NLUTCODES] =
{
  0x87, 0x83, 0x7d, 0x7f, 0x7b, 0x81, 0x4a, 0x12, 0x63, 0x6d, 0x3e, 0x5f, 0x30, 0x4b, 0x61, 0x16,  /* Codes 0-15 */
  0x46, 0x57, 0x3a, 0x73, 0x79, 0x69, 0x5b, 0x18, 0x1a, 0x2c, 0x4e, 0x3c, 0x1c, 0x75, 0x1e, 0x5d,  /* Codes 16-31 */
  0x36, 0x59, 0x67, 0x32, 0x4f, 0x20, 0x22, 0x71, 0x77, 0x42, 0x24, 0x65, 0x34, 0x53, 0x2e, 0x47,  /* Codes 32-47 */
  0x28, 0x38, 0x43, 0x26, 0x52, 0x6b, 0x14, 0xdf,  /* Codes 48-55 */
}

static const uint8_t g_lcdClockBrightLut[BITMAP_NLUTCODES] =
{
  0xa4, 0xa1, 0x9d, 0x9e, 0x9b, 0xa0, 0x76, 0x4d, 0x89, 0x91, 0x6d, 0x86, 0x63, 0x77, 0x88, 0x50,  /* Codes 0-15 */
  0x73, 0x80, 0x6a, 0x95, 0x9a, 0x8e, 0x83, 0x51, 0x53, 0x60, 0x79, 0x6c, 0x54, 0x97, 0x56, 0x85,  /* Codes 16-31 */
  0x67, 0x82, 0x8c, 0x64, 0x7a, 0x57, 0x59, 0x94, 0x98, 0x70, 0x5a, 0x8b, 0x66, 0x7d, 0x61, 0x74,  /* Codes 32-47 */
  0x5d, 0x69, 0x71, 0x5c, 0x7c, 0x8f, 0x4e, 0xe6,  /* Codes 48-55 */
};

#  else /* CONFIG_NXWIDGETS_GREYSCALE */
// RGB8 (332) Colors

static const nxgl_mxpixel_t g_lcdClockNormalLut[BITMAP_NLUTCODES] =
{
  0x92, 0x72, 0x71, 0x71, 0x71, 0x71, 0x29, 0x04, 0x4d, 0x6d, 0x28, 0x4d, 0x24, 0x49, 0x4d, 0x04,  /* Codes 0-15 */
  0x28, 0x4d, 0x28, 0x6d, 0x71, 0x6d, 0x4d, 0x04, 0x04, 0x04, 0x49, 0x28, 0x04, 0x6d, 0x04, 0x4d,  /* Codes 16-31 */
  0x28, 0x4d, 0x4d, 0x24, 0x49, 0x04, 0x04, 0x6d, 0x6d, 0x28, 0x04, 0x4d, 0x28, 0x49, 0x24, 0x29,  /* Codes 32-47 */
  0x04, 0x28, 0x28, 0x04, 0x49, 0x6d, 0x04, 0xfc,  /* Codes 48-55 */
};

static const uint8_t g_lcdClockBrightLut[BITMAP_NLUTCODES] =
{
  0xb6, 0x96, 0x96, 0x96, 0x96, 0x96, 0x71, 0x49, 0x92, 0x92, 0x6d, 0x92, 0x4d, 0x71, 0x92, 0x49,  /* Codes 0-15 */
  0x6d, 0x71, 0x6d, 0x92, 0x96, 0x92, 0x71, 0x49, 0x49, 0x4d, 0x71, 0x6d, 0x49, 0x92, 0x4d, 0x92,  /* Codes 16-31 */
  0x4d, 0x71, 0x92, 0x4d, 0x71, 0x4d, 0x4d, 0x92, 0x92, 0x6d, 0x4d, 0x92, 0x4d, 0x71, 0x4d, 0x6d,  /* Codes 32-47 */
  0x4d, 0x4d, 0x6d, 0x4d, 0x71, 0x92, 0x49, 0xfd,  /* Codes 48-55 */
};

#  endif
#else
#  error Unsupported pixel format
#endif

static const struct SRlePaletteBitmapEntry g_lcdClockRleEntries[] =
{
  {136,   0},                                                                                        // Row 0
  {136,   0},                                                                                        // Row 1
  {136,   0},                                                                                        // Row 2
  {136,   0},                                                                                        // Row 3
  { 31,   0}, {  1,   1}, { 16,   2}, {  1,   1}, { 28,   0}, {  1,   1}, { 16,   2}, {  1,   3},    // Row 4
  { 41,   0},
  { 17,   0}, {  1,   1}, {  1,   4}, {  1,   3}, {  9,   0}, {  1,   5}, {  1,   4}, {  1,   6},    // Row 5
  { 16,   7}, {  1,   8}, {  1,   3}, {  2,   4}, {  1,   1}, { 22,   0}, {  1,   1}, {  1,   4},
  {  1,   9}, { 16,   7}, {  1,  10}, {  1,   1}, {  1,   3}, { 11,   0}, {  1,   3}, { 16,   4},
  {  1,   1}, { 10,   0},
  { 16,   0}, {  1,   1}, {  1,  11}, {  1,   7}, {  1,  12}, {  1,   2}, {  7,   0}, {  1,   3},    // Row 6
  {  1,  13}, { 18,   7}, {  1,   8}, {  1,  12}, {  2,   7}, {  1,  14}, {  1,   1}, { 20,   0},
  {  1,   1}, {  1,   9}, { 17,   7}, {  1,  15}, {  1,  16}, {  1,  17}, {  1,  10}, {  1,   3},
  {  9,   0}, {  1,   3}, {  1,  18}, { 16,   7}, {  1,  19}, {  1,   0}, {  1,   4}, {  1,  20},
  {  1,   1}, {  6,   0},
  { 16,   0}, {  1,  21}, {  3,   7}, {  1,  12}, {  1,   4}, {  6,   0}, {  1,  22}, {  1,  23},    // Row 7
  { 17,   7}, {  1,  24}, {  1,  11}, {  1,  25}, {  3,   7}, {  1,   9}, { 20,   0}, {  1,   4},
  { 17,   7}, {  1,  15}, {  1,  16}, {  1,   3}, {  1,  26}, {  1,   7}, {  1,  10}, {  1,   3},
  {  7,   0}, {  1,   3}, {  1,  27}, { 16,   7}, {  1,  28}, {  1,  29}, {  1,  20}, {  1,  30},
  {  1,   7}, {  1,   9}, {  1,   1}, {  5,   0},
  { 15,   0}, {  1,   1}, {  1,  31}, {  4,   7}, {  1,  32}, {  7,   0}, {  1,  33}, {  1,  24},    // Row 8
  { 15,   7}, {  1,  28}, {  1,  34}, {  1,  35}, {  4,   7}, {  1,   9}, { 20,   0}, {  1,   4},
  {  1,  30}, { 15,   7}, {  1,  15}, {  1,  16}, {  1,   3}, {  1,  36}, {  3,   7}, {  1,  16},
  {  7,   0}, {  1,  13}, {  1,  15}, { 15,   7}, {  1,  30}, {  1,  29}, {  1,   0}, {  1,  37},
  {  3,   7}, {  1,   4}, {  5,   0},
  { 15,   0}, {  1,  21}, {  5,   7}, {  1,  32}, {  8,   0}, {  1,  17}, {  1,  38}, {  1,  24},    // Row 9
  { 13,   7}, {  1,  14}, {  1,  20}, {  1,  25}, {  4,   7}, {  1,   9}, { 21,   0}, {  1,   4},
  {  1,  38}, {  1,  37}, { 13,   7}, {  1,  18}, {  1,   0}, {  1,  22}, {  4,   7}, {  1,  16},
  {  6,   0}, {  1,   4}, {  1,  29}, {  1,  16}, {  2,  38}, {  1,  15}, { 12,   7}, {  1,  39},
  {  1,   0}, {  1,  40}, {  1,  30}, {  3,   7}, {  1,   4}, {  5,   0},
  { 14,   0}, {  1,   1}, {  1,  22}, {  4,   7}, {  1,  15}, {  1,  41}, { 10,   0}, {  1,  17},    // Row 10
  {  1,  42}, {  1,  24}, { 10,   7}, {  1,  30}, {  1,  43}, {  1,  44}, {  5,   7}, {  1,   9},
  { 23,   0}, {  1,  40}, {  1,  37}, { 11,   7}, {  1,  15}, {  1,  16}, {  1,   3}, {  1,  26},
  {  4,   7}, {  1,  16}, {  5,   0}, {  1,   4}, {  1,  10}, {  1,   7}, {  1,   6}, {  1,   3},
  {  1,   0}, {  1,   6}, {  1,  23}, { 10,   7}, {  1,  37}, {  1,  19}, {  1,   0}, {  1,  42},
  {  4,   7}, {  1,   4}, {  5,   0},
  { 13,   0}, {  1,   5}, {  1,  22}, {  5,   7}, {  1,  44}, { 13,   0}, {  1,  45}, { 10,  42},    // Row 11
  {  1,  43}, {  1,  40}, {  1,  46}, {  5,   7}, {  1,   9}, { 24,   0}, {  1,  40}, { 11,  42},
  {  1,  16}, {  1,   0}, {  1,  22}, {  5,   7}, {  1,  16}, {  5,   0}, {  1,  16}, {  3,   7},
  {  1,   6}, {  1,   2}, {  1,   0}, {  1,  47}, { 10,  42}, {  1,  39}, {  1,   0}, {  1,  29},
  {  1,  37}, {  4,   7}, {  1,   4}, {  5,   0},
  { 13,   0}, {  1,   9}, {  6,   7}, {  1,  44}, { 25,   0}, {  1,  32}, {  6,   7}, {  1,   9},    // Row 12
  { 37,   0}, {  1,   2}, {  1,  26}, {  5,   7}, {  1,  16}, {  5,   0}, {  1,  16}, {  4,   7},
  {  1,   6}, {  1,   9}, {  1,   2}, { 11,   0}, {  1,  19}, {  1,  37}, {  5,   7}, {  1,   4},
  {  5,   0},
  { 13,   0}, {  1,   9}, {  6,   7}, {  1,  44}, { 24,   0}, {  1,  29}, {  1,  46}, {  5,   7},    // Row 13
  {  1,  42}, {  1,  39}, { 37,   0}, {  1,  31}, {  6,   7}, {  1,  16}, {  5,   0}, {  1,  16},
  {  6,   7}, {  1,  22}, { 11,   0}, {  1,  48}, {  6,   7}, {  1,   4}, {  5,   0},
  { 13,   0}, {  1,   9}, {  6,   7}, {  1,  44}, { 24,   0}, {  1,  49}, {  6,   7}, {  1,  21},    // Row 14
  { 38,   0}, {  1,  31}, {  5,   7}, {  1,  28}, {  1,  45}, {  5,   0}, {  1,  16}, {  5,   7},
  {  1,  37}, {  1,  43}, { 11,   0}, {  1,  48}, {  5,   7}, {  1,  48}, {  1,   3}, {  5,   0},
  { 13,   0}, {  1,   9}, {  6,   7}, {  1,  44}, { 24,   0}, {  1,  49}, {  6,   7}, {  1,  21},    // Row 15
  { 38,   0}, {  1,  31}, {  5,   7}, {  1,  50}, {  6,   0}, {  1,  16}, {  5,   7}, {  1,  22},
  { 12,   0}, {  1,  48}, {  5,   7}, {  1,   4}, {  6,   0},
  { 13,   0}, {  1,   9}, {  5,   7}, {  1,  24}, {  1,   6}, { 24,   0}, {  1,  49}, {  6,   7},    // Row 16
  {  1,  21}, { 37,   0}, {  1,   4}, {  1,   6}, {  5,   7}, {  1,  50}, {  6,   0}, {  1,  16},
  {  5,   7}, {  1,  22}, { 12,   0}, {  1,  48}, {  5,   7}, {  1,   4}, {  6,   0},
  { 12,   0}, {  1,   3}, {  1,  45}, {  5,   7}, {  1,  35}, { 25,   0}, {  1,  49}, {  6,   7},    // Row 17
  {  1,  21}, { 37,   0}, {  1,  11}, {  6,   7}, {  1,  50}, {  5,   0}, {  1,  29}, {  1,  49},
  {  5,   7}, {  1,  22}, { 11,   0}, {  1,   9}, {  1,  37}, {  5,   7}, {  1,   4}, {  6,   0},
  { 12,   0}, {  1,  39}, {  6,   7}, {  1,  35}, { 25,   0}, {  1,  49}, {  6,   7}, {  1,  21},    // Row 18
  { 37,   0}, {  1,  11}, {  6,   7}, {  1,  50}, {  5,   0}, {  1,   6}, {  6,   7}, {  1,  22},
  { 11,   0}, {  1,  48}, {  6,   7}, {  1,   4}, {  6,   0},
  { 12,   0}, {  1,  39}, {  6,   7}, {  1,  35}, { 25,   0}, {  1,  49}, {  6,   7}, {  1,  21},    // Row 19
  { 37,   0}, {  1,  11}, {  6,   7}, {  1,  50}, {  5,   0}, {  1,   6}, {  6,   7}, {  1,  22},
  { 11,   0}, {  1,  48}, {  6,   7}, {  1,   4}, {  6,   0},
  { 12,   0}, {  1,  39}, {  6,   7}, {  1,  35}, { 25,   0}, {  1,  49}, {  5,   7}, {  1,  25},    // Row 20
  {  1,  19}, { 37,   0}, {  1,  11}, {  6,   7}, {  1,  50}, {  5,   0}, {  1,   6}, {  6,   7},
  {  1,  22}, { 11,   0}, {  1,  48}, {  6,   7}, {  1,   4}, {  6,   0},
  { 12,   0}, {  1,  39}, {  6,   7}, {  1,  35}, { 24,   0}, {  1,   9}, {  1,  25}, {  5,   7},    // Row 21
  {  1,  21}, { 38,   0}, {  1,  11}, {  6,   7}, {  1,  50}, {  5,   0}, {  1,   6}, {  6,   7},
  {  1,  22}, { 11,   0}, {  1,  48}, {  6,   7}, {  1,   4}, {  6,   0},
  { 12,   0}, {  1,  39}, {  6,   7}, {  1,  35}, { 24,   0}, {  1,  18}, {  6,   7}, {  1,  21},    // Row 22
  { 37,   0}, {  1,  20}, {  1,  50}, {  5,   7}, {  1,  38}, {  1,  22}, {  5,   0}, {  1,   6},
  {  6,   7}, {  1,  22}, { 11,   0}, {  1,  48}, {  5,   7}, {  1,  32}, {  1,   3}, {  6,   0},
  { 11,   0}, {  1,   3}, {  1,  26}, {  5,   7}, {  1,  28}, {  1,  36}, { 24,   0}, {  1,  18},    // Row 23
  {  6,   7}, {  1,  21}, { 37,   0}, {  1,  14}, {  6,   7}, {  1,  41}, {  5,   0}, {  1,  39},
  {  1,  44}, {  5,   7}, {  1,  25}, {  1,  21}, { 10,   0}, {  1,   8}, {  1,  37}, {  5,   7},
  {  1,  20}, {  7,   0},
  { 11,   0}, {  1,  39}, {  6,   7}, {  1,  12}, { 25,   0}, {  1,  18}, {  6,   7}, {  1,  21},    // Row 24
  { 37,   0}, {  1,  14}, {  6,   7}, {  1,  41}, {  5,   0}, {  1,   6}, {  6,   7}, {  1,  17},
  { 11,   0}, {  1,  48}, {  6,   7}, {  1,  20}, {  7,   0},
  { 11,   0}, {  1,  39}, {  6,   7}, {  1,  12}, { 25,   0}, {  1,  18}, {  6,   7}, {  1,  21},    // Row 25
  { 37,   0}, {  1,  14}, {  6,   7}, {  1,  41}, {  5,   0}, {  1,   6}, {  6,   7}, {  1,  17},
  { 11,   0}, {  1,  48}, {  6,   7}, {  1,  20}, {  7,   0},
  { 11,   0}, {  1,  39}, {  6,   7}, {  1,  12}, { 25,   0}, {  1,  18}, {  6,   7}, {  1,  21},    // Row 26
  { 37,   0}, {  1,  14}, {  6,   7}, {  1,  41}, {  5,   0}, {  1,   6}, {  6,   7}, {  1,  17},
  { 11,   0}, {  1,  48}, {  6,   7}, {  1,  20}, {  7,   0},
  { 11,   0}, {  1,  39}, {  6,   7}, {  1,  12}, { 25,   0}, {  1,  18}, {  6,   7}, {  1,  21},    // Row 27
  { 37,   0}, {  1,  14}, {  6,   7}, {  1,  41}, {  5,   0}, {  1,   6}, {  6,   7}, {  1,  17},
  { 11,   0}, {  1,  48}, {  6,   7}, {  1,  20}, {  7,   0},
  { 11,   0}, {  1,   4}, {  1,  18}, {  5,   7}, {  1,  12}, { 25,   0}, {  1,  18}, {  5,   7},    // Row 28
  {  1,  49}, {  1,  29}, { 37,   0}, {  1,  14}, {  5,   7}, {  1,  42}, {  1,  11}, {  5,   0},
  {  1,   6}, {  5,   7}, {  1,  12}, {  1,   9}, { 11,   0}, {  1,  48}, {  6,   7}, {  1,  20},
  {  7,   0},
  { 12,   0}, {  1,  20}, {  1,  27}, {  4,   7}, {  1,  12}, { 11,   0}, {  1,   9}, { 13,  36},    // Row 29
  {  1,   6}, {  1,  16}, {  1,  38}, {  3,   7}, {  1,  34}, { 25,   0}, {  1,   3}, { 11,  36},
  {  1,  11}, {  1,  39}, {  1,  44}, {  4,   7}, {  1,  41}, {  5,   0}, {  1,  21}, {  1,  12},
  {  3,   7}, {  1,  12}, {  1,  16}, {  1,   9}, {  1,  43}, { 10,  36}, {  1,  20}, {  1,  45},
  {  1,  28}, {  5,   7}, {  1,  20}, {  7,   0},
  { 13,   0}, {  1,  20}, {  1,  10}, {  3,   7}, {  1,  12}, {  9,   0}, {  1,   9}, {  1,  26},    // Row 30
  {  1,  35}, { 13,   7}, {  1,  18}, {  1,  19}, {  1,  22}, {  1,  38}, {  2,   7}, {  1,  34},
  { 24,   0}, {  1,   3}, {  1,  16}, { 11,   7}, {  1,  42}, {  1,  26}, {  1,  13}, {  1,  47},
  {  1,  44}, {  2,   7}, {  1,  41}, {  5,   0}, {  1,  13}, {  3,   7}, {  1,  12}, {  1,  21},
  {  1,  43}, {  1,  26}, {  1,  48}, { 10,   7}, {  1,  41}, {  1,  26}, {  1,   6}, {  1,  47},
  {  1,  24}, {  2,   7}, {  1,  41}, {  1,   3}, {  7,   0},
  { 14,   0}, {  1,  20}, {  1,  10}, {  2,   7}, {  1,  12}, {  8,   0}, {  1,   9}, {  1,  44},    // Row 31
  { 16,   7}, {  1,  49}, {  2,  13}, {  1,  37}, {  1,   7}, {  1,  34}, { 22,   0}, {  1,   5},
  {  1,  13}, {  1,  16}, { 14,   7}, {  1,  42}, {  1,  11}, {  1,  39}, {  1,  44}, {  1,   7},
  {  1,  41}, {  5,   0}, {  1,  13}, {  2,   7}, {  1,  12}, {  1,  21}, {  1,  43}, {  1,  48},
  { 14,   7}, {  1,  41}, {  1,   4}, {  1,  45}, {  1,  24}, {  1,   7}, {  1,  40}, {  8,   0},
  { 15,   0}, {  1,  20}, {  2,  13}, {  1,  22}, {  7,   0}, {  1,   9}, {  1,  44}, { 19,   7},    // Row 32
  {  1,  14}, {  1,  22}, {  1,  13}, {  1,  40}, { 20,   0}, {  1,   1}, {  1,   6}, {  1,  16},
  { 17,   7}, {  1,  42}, {  1,  11}, {  1,  39}, {  1,  13}, {  1,   8}, {  5,   0}, {  1,  21},
  {  3,  13}, {  1,   6}, {  1,  48}, { 16,   7}, {  1,  10}, {  1,   6}, {  2,  13}, {  1,   3},
  {  8,   0},
  { 15,   0}, {  1,  40}, {  1,  47}, {  1,  17}, {  5,   0}, {  1,  39}, {  2,  47}, {  1,   6},    // Row 33
  {  1,  26}, {  1,  44}, { 17,   7}, {  1,  18}, {  1,  29}, { 23,   0}, {  1,   1}, {  1,   6},
  { 18,   7}, {  1,  51}, {  1,  14}, {  1,   9}, {  1,  47}, {  1,  14}, {  8,   0}, {  1,  16},
  { 18,   7}, {  1,  41}, {  1,  26}, {  1,   2}, {  1,  36}, {  1,   3}, {  8,   0},
  { 13,   0}, {  1,  20}, {  1,  16}, {  1,  18}, {  1,   7}, {  1,  12}, {  5,   0}, {  1,  31},    // Row 34
  {  2,   7}, {  1,  42}, {  1,  11}, {  1,   9}, {  1,  44}, { 14,   7}, {  1,  18}, {  1,  36},
  {  1,  29}, { 25,   0}, {  1,   1}, {  1,   6}, { 15,   7}, {  1,  42}, {  1,  36}, {  1,  13},
  {  1,  16}, {  1,  35}, {  1,   7}, {  1,  41}, {  8,   0}, {  1,  21}, {  1,  25}, { 16,   7},
  {  1,  41}, {  1,   4}, {  1,  52}, {  1,  16}, {  1,  23}, {  1,  40}, {  8,   0},
  { 11,   0}, {  1,   4}, {  1,  16}, {  1,  18}, {  3,   7}, {  1,  12}, {  5,   0}, {  1,  31},    // Row 35
  {  3,   7}, {  1,  42}, {  1,  11}, {  1,   9}, {  1,  44}, { 12,   7}, {  1,  18}, {  1,  19},
  { 28,   0}, {  1,   5}, {  1,  52}, {  1,   6}, { 11,   7}, {  1,  42}, {  1,  52}, {  1,  14},
  {  1,  39}, {  1,  35}, {  3,   7}, {  1,  41}, {  9,   0}, {  1,  21}, {  1,  25}, { 13,   7},
  {  1,  41}, {  1,  52}, {  1,  47}, {  1,  16}, {  1,  24}, {  2,   7}, {  1,  40}, {  8,   0},
  { 10,   0}, {  1,   4}, {  1,  18}, {  5,   7}, {  1,  12}, {  5,   0}, {  1,  31}, {  4,   7},    // Row 36
  {  1,  42}, {  1,  41}, {  1,   6}, { 12,  45}, {  1,  19}, { 31,   0}, {  1,   3}, { 11,  45},
  {  1,  14}, {  1,  39}, {  1,  41}, {  1,  35}, {  4,   7}, {  1,  41}, { 10,   0}, {  1,  21},
  { 13,  45}, {  1,  16}, {  1,  41}, {  1,  24}, {  4,   7}, {  1,  40}, {  8,   0},
  {  9,   0}, {  1,   4}, {  1,  18}, {  6,   7}, {  1,  12}, {  5,   0}, {  1,  31}, {  6,   7},    // Row 37
  {  1,  16}, { 56,   0}, {  1,  39}, {  1,  35}, {  5,   7}, {  1,  25}, {  1,  21}, { 23,   0},
  {  1,  52}, {  1,  28}, {  6,   7}, {  1,  40}, {  8,   0},
  {  9,   0}, {  1,  29}, {  7,   7}, {  1,  12}, {  5,   0}, {  1,  31}, {  6,   7}, {  1,  16},    // Row 38
  { 56,   0}, {  1,   8}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  25}, {  7,   7}, {  1,  40},
  {  8,   0},
  {  9,   0}, {  1,  29}, {  6,   7}, {  1,  38}, {  1,  43}, {  4,   0}, {  1,   9}, {  1,  46},    // Row 39
  {  6,   7}, {  1,  16}, { 56,   0}, {  1,   8}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  25},
  {  7,   7}, {  1,  40}, {  8,   0},
  {  9,   0}, {  1,  29}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  11}, {  7,   7}, {  1,  16},    // Row 40
  { 56,   0}, {  1,   8}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  25}, {  6,   7}, {  1,  36},
  {  1,   3}, {  8,   0},
  {  9,   0}, {  1,  29}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  11}, {  6,   7}, {  1,  35},    // Row 41
  {  1,   9}, { 56,   0}, {  1,   8}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  25}, {  6,   7},
  {  1,  29}, {  9,   0},
  {  9,   0}, {  1,  29}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  11}, {  6,   7}, {  1,  50},    // Row 42
  { 57,   0}, {  1,   8}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  25}, {  6,   7}, {  1,  29},
  {  9,   0},
  {  9,   0}, {  1,  29}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  11}, {  6,   7}, {  1,  50},    // Row 43
  { 56,   0}, {  1,  39}, {  1,  25}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  25}, {  6,   7},
  {  1,  29}, {  9,   0},
  {  8,   0}, {  1,   4}, {  1,  12}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  11}, {  6,   7},    // Row 44
  {  1,  50}, { 56,   0}, {  1,  43}, {  7,   7}, {  1,  10}, { 24,   0}, {  1,  25}, {  6,   7},
  {  1,  29}, {  9,   0},
  {  8,   0}, {  1,  40}, {  7,   7}, {  1,  25}, {  5,   0}, {  1,  11}, {  6,   7}, {  1,  50},    // Row 45
  { 56,   0}, {  1,  43}, {  6,   7}, {  1,  12}, {  1,  39}, { 23,   0}, {  1,  47}, {  1,  24},
  {  6,   7}, {  1,  29}, {  9,   0},
  {  8,   0}, {  1,  40}, {  7,   7}, {  1,  25}, {  5,   0}, {  1,  11}, {  6,   7}, {  1,  50},    // Row 46
  { 56,   0}, {  1,  43}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  12}, {  7,   7}, {  1,  29},
  {  9,   0},
  {  8,   0}, {  1,  40}, {  6,   7}, {  1,  42}, {  1,   9}, {  4,   0}, {  1,  21}, {  1,  42},    // Row 47
  {  6,   7}, {  1,  50}, { 56,   0}, {  1,  43}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  12},
  {  6,   7}, {  1,  22}, {  1,   5}, {  9,   0},
  {  8,   0}, {  1,  40}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  14}, {  7,   7}, {  1,  50},    // Row 48
  { 56,   0}, {  1,  43}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  12}, {  6,   7}, {  1,  19},
  { 10,   0},
  {  8,   0}, {  1,  40}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  14}, {  6,   7}, {  1,  32},    // Row 49
  {  1,  40}, { 56,   0}, {  1,  43}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  12}, {  6,   7},
  {  1,  19}, { 10,   0},
  {  8,   0}, {  1,  40}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  14}, {  6,   7}, {  1,  41},    // Row 50
  { 57,   0}, {  1,  43}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  12}, {  6,   7}, {  1,  19},
  { 10,   0},
  {  8,   0}, {  1,  40}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  14}, {  6,   7}, {  1,  41},    // Row 51
  { 57,   0}, {  1,  43}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  12}, {  6,   7}, {  1,  19},
  { 10,   0},
  {  8,   0}, {  1,  40}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  14}, {  3,   7}, {  1,  44},    // Row 52
  {  2,  39}, {  1,  20}, { 57,   0}, {  1,  43}, {  6,   7}, {  1,  10}, { 24,   0}, {  1,  12},
  {  6,   7}, {  1,  19}, { 10,   0},
  {  8,   0}, {  1,  40}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,  14}, {  1,  12}, {  2,  39},    // Row 53
  {  1,  20}, {  1,  11}, {  1,  42}, {  1,  26}, { 57,   0}, {  1,  43}, {  6,   7}, {  1,  10},
  { 24,   0}, {  1,  12}, {  6,   7}, {  1,  19}, { 10,   0},
  {  8,   0}, {  1,  40}, {  6,   7}, {  1,  25}, {  5,   0}, {  1,   3}, {  1,  20}, {  1,   8},    // Row 54
  {  2,  38}, {  1,  28}, {  1,   7}, {  1,  23}, { 11,  38}, {  1,  31}, { 28,   0}, {  1,   1},
  { 15,  38}, {  1,  27}, {  1,   5}, {  1,  17}, {  4,   7}, {  1,  44}, {  1,   4}, {  8,   0},
  {  1,  45}, { 13,  38}, {  1,  21}, {  1,   0}, {  1,  20}, {  1,  48}, {  5,   7}, {  1,  19},
  { 10,   0},
  {  8,   0}, {  1,   1}, {  1,  34}, {  4,   7}, {  1,  48}, {  1,  20}, {  5,   0}, {  1,  43},    // Row 55
  {  1,  37}, {  1,  24}, { 16,   7}, {  1,  17}, { 26,   0}, {  3,  37}, { 15,   7}, {  1,  15},
  {  1,  27}, {  1,   8}, {  4,   7}, {  1,  18}, {  6,   0}, {  1,  17}, {  2,  37}, {  1,  23},
  { 13,   7}, {  1,  28}, {  1,  37}, {  1,  53}, {  1,  25}, {  5,   7}, {  1,  19}, { 10,   0},
  {  9,   0}, {  1,  29}, {  4,   7}, {  1,  48}, {  6,   0}, {  1,  14}, { 18,   7}, {  1,  24},    // Row 56
  {  1,  31}, { 25,   0}, { 19,   7}, {  1,  12}, {  1,   8}, {  4,   7}, {  1,  18}, {  5,   0},
  {  1,  17}, {  1,  23}, { 18,   7}, {  1,  34}, {  1,   4}, {  1,  48}, {  3,   7}, {  1,  43},
  {  1,   1}, { 10,   0},
  {  9,   0}, {  1,   1}, {  1,  21}, {  2,   7}, {  1,  42}, {  1,   4}, {  6,   0}, {  1,  14},    // Row 57
  { 19,   7}, {  1,  17}, { 25,   0}, { 19,   7}, {  1,  54}, {  1,  49}, {  1,  22}, {  3,   7},
  {  1,  18}, {  5,   0}, {  1,  52}, { 19,   7}, {  1,  24}, {  1,   9}, {  1,  25}, {  3,   7},
  {  1,  39}, { 11,   0},
  { 10,   0}, {  1,  19}, {  2,   7}, {  1,  48}, {  7,   0}, {  1,  14}, { 19,   7}, {  1,  15},    // Row 58
  {  1,  31}, { 24,   0}, {  1,   4}, { 19,   7}, {  1,  35}, {  1,  14}, {  2,   7}, {  1,  32},
  {  1,   3}, {  5,   0}, {  1,   5}, {  1,   6}, { 19,   7}, {  1,  21}, {  1,  25}, {  2,   7},
  {  1,  34}, {  1,   1}, { 11,   0},
  { 10,   0}, {  1,   1}, {  1,  21}, {  1,  42}, {  1,   3}, {  7,   0}, {  1,   1}, {  1,  33},    // Row 59
  { 19,   7}, {  1,  22}, { 25,   0}, {  1,   2}, { 19,   7}, {  1,  15}, {  1,   7}, {  1,  44},
  {  1,   3}, {  7,   0}, {  1,  36}, { 19,   7}, {  1,  15}, {  2,   7}, {  1,  34}, {  1,   1},
  { 12,   0},
  { 11,   0}, {  1,   1}, {  1,   3}, {  9,   0}, {  1,   1}, {  1,   3}, {  1,  17}, { 17,   7},    // Row 60
  {  1,  15}, {  1,  31}, { 24,   0}, {  1,   1}, { 19,   7}, {  1,  35}, {  1,   3}, {  1,   5},
  {  8,   0}, {  1,   1}, {  1,   3}, {  1,   6}, { 18,   7}, {  1,  43}, {  1,   3}, {  1,   1},
  { 13,   0},
  { 24,   0}, {  1,   1}, { 18,   5}, {  1,   1}, { 25,   0}, {  2,   5}, {  1,   4}, { 15,   7},    // Row 61
  {  1,  12}, {  1,   1}, { 12,   0}, {  1,   1}, {  1,  47}, { 17,   7}, {  1,  21}, { 15,   0},
  { 72,   0}, { 16,   1}, { 14,   0}, { 19,   1}, { 15,   0},                                        // Row 62
  {  1,  55}, {135,   0},                                                                            // Row 63
 };

/********************************************************************************************
 * Public Bitmap Structure Definitions
 ********************************************************************************************/

const struct SRlePaletteBitmap NXWidgets::g_lcdClockBitmap =
{
  CONFIG_NXWIDGETS_BPP,  // bpp    - Bits per pixel
  CONFIG_NXWIDGETS_FMT,  // fmt    - Color format
  BITMAP_NLUTCODES,      // nlut   - Number of colors in the lLook-Up Table (LUT)
  BITMAP_NCOLUMNS,       // width  - Width in pixels
  BITMAP_NROWS,          // height - Height in rows
  {                      // lut    - Pointer to the beginning of the Look-Up Table (LUT)
    g_lcdClockNormalLut, //          Index 0: Unselected LUT
    g_lcdClockBrightLut, //          Index 1: Selected LUT
  },
  g_lcdClockRleEntries   // data   - Pointer to the beginning of the RLE data
};
