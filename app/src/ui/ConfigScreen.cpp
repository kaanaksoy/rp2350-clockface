/*
 * ConfigScreen.cpp
 *
 * This class is responsible for displaying the config screen.
 * Author: Kaan Aksoy
 */

#include "ConfigScreen.h"
#include "src/core/lv_obj.h"
#include "src/core/lv_obj_pos.h"
#include "src/core/lv_obj_style.h"
#include "src/misc/lv_color.h"
#include "src/widgets/lv_arc.h"
#include "src/widgets/lv_img.h"
#include <cstddef>
#include <cstring>

ConfigScreen::ConfigScreen() {}

ConfigScreen::~ConfigScreen() {}

void ConfigScreen::init_bg() {
  //   Background Color
  lv_obj_set_style_bg_color(parent, lv_color_hex(0x1C1B19), LV_PART_MAIN);
  lv_obj_set_style_bg_opa(parent, LV_OPA_COVER, LV_PART_MAIN);

  //   Background Ring
  lv_obj_t *ring = lv_arc_create(parent);
  lv_obj_set_size(ring, 472, 472);
  lv_arc_set_bg_angles(ring, 0, 360);
  lv_arc_set_value(ring, 100);
  lv_obj_remove_style(ring, NULL, LV_PART_KNOB);
  lv_obj_clear_flag(ring, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_set_style_arc_color(ring, lv_color_hex(0x16737D), LV_PART_INDICATOR);
  lv_obj_set_style_arc_width(ring, 8, LV_PART_INDICATOR);
  lv_obj_set_style_arc_rounded(ring, true, LV_PART_INDICATOR);
  lv_obj_set_style_arc_opa(ring, LV_OPA_TRANSP, LV_PART_MAIN);
  lv_obj_set_style_bg_opa(ring, LV_OPA_TRANSP, LV_PART_MAIN);
  lv_obj_center(ring);
}

void ConfigScreen::init_config_qr_code() {
  qr_code = lv_qrcode_create(parent, 220, lv_color_hex(0xEAE7E2),
                             lv_color_hex(0x1C1B19));
  lv_qrcode_update(qr_code, config_url, config_url_len);
  lv_obj_center(qr_code);
}

void ConfigScreen::init_refresh_button() {
  // TODO: Implement this
}

void ConfigScreen::init(lv_obj_t *parent) {
  this->parent = parent;
  init_bg();
  init_config_qr_code();
  init_refresh_button();
}

void ConfigScreen::set_config_url(const char *url, size_t len) {
  if (len >= CONFIG_URL_MAX_LENGTH)
    len = CONFIG_URL_MAX_LENGTH - 1;
  lv_memcpy(config_url, url, len);
  config_url[len] = '\0';
  config_url_len = len;
  if (qr_code) {
    lv_qrcode_update(qr_code, config_url, config_url_len);
  }
}
