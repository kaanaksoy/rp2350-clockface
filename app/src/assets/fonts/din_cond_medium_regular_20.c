/*******************************************************************************
 * Size: 20 px
 * Bpp: 2
 * Opts: --bpp 2 --size 20 --no-compress --stride 1 --align 1 --font
 *DINCond-Medium Regular.ttf --symbols RESTARTHUDOWN --format lvgl -o
 *din_cond_medium_regular_20.c
 ******************************************************************************/

#ifdef __has_include
#if __has_include("lvgl.h")
#ifndef LV_LVGL_H_INCLUDE_SIMPLE
#define LV_LVGL_H_INCLUDE_SIMPLE
#endif
#endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef DIN_COND_MEDIUM_REGULAR_20
#define DIN_COND_MEDIUM_REGULAR_20 1
#endif

#if DIN_COND_MEDIUM_REGULAR_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0041 "A" */
    0x2, 0xc0, 0x0, 0xf4, 0x0, 0x3e, 0x0, 0x1f, 0xc0, 0xb, 0x70, 0x3, 0xdd, 0x0,
    0xe3, 0x80, 0x34, 0xe0, 0x1c, 0x2c, 0xb, 0xb, 0x3, 0xff, 0xd0, 0xfa, 0xb8,
    0x74, 0xf, 0x2c, 0x2, 0xcf, 0x0, 0xb4,

    /* U+0044 "D" */
    0xbf, 0xd0, 0xba, 0xf4, 0xb0, 0x38, 0xb0, 0x3c, 0xb0, 0x3c, 0xb0, 0x2c,
    0xb0, 0x2c, 0xb0, 0x2c, 0xb0, 0x2c, 0xb0, 0x2c, 0xb0, 0x3c, 0xb0, 0x3c,
    0xb0, 0x38, 0xba, 0xf4, 0xbf, 0xd0,

    /* U+0045 "E" */
    0xbf, 0xfb, 0xa9, 0xb0, 0xb, 0x0, 0xb0, 0xb, 0x0, 0xb0, 0xb, 0xfd, 0xba,
    0x8b, 0x0, 0xb0, 0xb, 0x0, 0xb0, 0xb, 0xa9, 0xbf, 0xf0,

    /* U+0048 "H" */
    0xb0, 0x3e, 0xc0, 0xfb, 0x3, 0xec, 0xf, 0xb0, 0x3e, 0xc0, 0xfb, 0xab, 0xef,
    0xff, 0xb0, 0x3e, 0xc0, 0xfb, 0x3, 0xec, 0xf, 0xb0, 0x3e, 0xc0, 0xfb, 0x3,
    0xc0,

    /* U+004E "N" */
    0xb0, 0x1c, 0xb4, 0x1c, 0xbc, 0x1c, 0xbc, 0x1c, 0xbd, 0x1c, 0xbb, 0x1c,
    0xb7, 0x1c, 0xb3, 0x9c, 0xb2, 0xdc, 0xb1, 0xec, 0xb0, 0xfc, 0xb0, 0xbc,
    0xb0, 0x3c, 0xb0, 0x3c, 0xb0, 0x1c,

    /* U+004F "O" */
    0x7, 0xf4, 0x1f, 0xbc, 0x2c, 0x1e, 0x3c, 0xf, 0x38, 0xf, 0x38, 0xf, 0x38,
    0xf, 0x38, 0xf, 0x38, 0xf, 0x38, 0xf, 0x38, 0xf, 0x3c, 0xf, 0x2c, 0x1e,
    0x1f, 0xbc, 0x7, 0xf4,

    /* U+0052 "R" */
    0xbf, 0xd0, 0xba, 0xf4, 0xb0, 0x38, 0xb0, 0x3c, 0xb0, 0x3c, 0xb0, 0x3c,
    0xb0, 0x78, 0xbf, 0xf0, 0xba, 0xd0, 0xb0, 0xe0, 0xb0, 0xf0, 0xb0, 0xb0,
    0xb0, 0x38, 0xb0, 0x3c, 0xb0, 0x2c,

    /* U+0053 "S" */
    0xb, 0xe0, 0x2f, 0xbc, 0x3c, 0x1d, 0x38, 0xd, 0x38, 0x0, 0x3c, 0x0, 0x2f,
    0x80, 0x7, 0xf4, 0x0, 0x7c, 0x0, 0x1d, 0x0, 0xe, 0x38, 0xe, 0x3c, 0x1d,
    0x3f, 0xbc, 0xb, 0xf0,

    /* U+0054 "T" */
    0xbf, 0xfd, 0xaf, 0xa0, 0x38, 0x0, 0xe0, 0x3, 0x80, 0xe, 0x0, 0x38, 0x0,
    0xe0, 0x3, 0x80, 0xe, 0x0, 0x38, 0x0, 0xe0, 0x3, 0x80, 0xe, 0x0, 0x38, 0x0,

    /* U+0055 "U" */
    0xf0, 0x3b, 0xc0, 0xef, 0x3, 0xbc, 0xe, 0xf0, 0x3b, 0xc0, 0xef, 0x3, 0xbc,
    0xe, 0xf0, 0x3b, 0xc0, 0xef, 0x3, 0xbc, 0xe, 0xb0, 0x38, 0xfb, 0xc1, 0xfc,
    0x0,

    /* U+0057 "W" */
    0xf0, 0x2e, 0x3, 0xec, 0xb, 0xc0, 0xeb, 0x43, 0xf0, 0x39, 0xd0, 0xfc, 0x1d,
    0x38, 0x37, 0x47, 0xe, 0x1c, 0xd2, 0xc3, 0xcb, 0x38, 0xb0, 0xb3, 0x8b, 0x38,
    0x2c, 0xd1, 0xce, 0x7, 0x34, 0x73, 0x40, 0xec, 0xe, 0xc0, 0x3f, 0x3, 0xf0,
    0xf, 0xc0, 0xbc, 0x2, 0xe0, 0x2f, 0x0, 0xb4, 0x7, 0x80};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0,
     .adv_w = 0,
     .box_w = 0,
     .box_h = 0,
     .ofs_x = 0,
     .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0,
     .adv_w = 136,
     .box_w = 9,
     .box_h = 15,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 34,
     .adv_w = 143,
     .box_w = 8,
     .box_h = 15,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 64,
     .adv_w = 122,
     .box_w = 6,
     .box_h = 15,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 87,
     .adv_w = 147,
     .box_w = 7,
     .box_h = 15,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 114,
     .adv_w = 153,
     .box_w = 8,
     .box_h = 15,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 144,
     .adv_w = 141,
     .box_w = 8,
     .box_h = 15,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 174,
     .adv_w = 146,
     .box_w = 8,
     .box_h = 15,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 204,
     .adv_w = 134,
     .box_w = 8,
     .box_h = 15,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 234,
     .adv_w = 117,
     .box_w = 7,
     .box_h = 15,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 261,
     .adv_w = 142,
     .box_w = 7,
     .box_h = 15,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 288,
     .adv_w = 209,
     .box_w = 13,
     .box_h = 15,
     .ofs_x = 0,
     .ofs_y = 0}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {0x0,  0x3,  0x4,  0x7,  0xd, 0xe,
                                          0x11, 0x12, 0x13, 0x14, 0x16};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {
    {.range_start = 65,
     .range_length = 23,
     .glyph_id_start = 1,
     .unicode_list = unicode_list_0,
     .glyph_id_ofs_list = NULL,
     .list_length = 11,
     .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY}};

/*-----------------
 *    KERNING
 *----------------*/

/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] = {0, 1, 2, 0, 0, 0,
                                                  2, 3, 4, 5, 6, 7};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] = {0, 1, 0, 0, 0, 0,
                                                   2, 0, 3, 4, 5, 6};

/*Kern values between classes*/
static const int8_t kern_class_values[] = {
    3,  1, 2, -12, 1,  2, 0, 0, 0,  -3, 0, 4, 0, -1, 0, -6, -3, 4, 0,  0, 0,
    -1, 0, 5, -14, -4, 0, 0, 0, 10, 1,  0, 0, 0, 0,  0, 2,  6,  6, 10, 0, 0};

/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes = {
    .class_pair_values = kern_class_values,
    .left_class_mapping = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt = 7,
    .right_class_cnt = 6,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t din_cond_medium_regular_20 = {
#else
lv_font_t din_cond_medium_regular_20 = {
#endif
    .get_glyph_dsc =
        lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap =
        lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 15, /*The maximum line height required by the font*/
    .base_line = 0,    /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by
                         `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};

#endif /*#if DIN_COND_MEDIUM_REGULAR_20*/
