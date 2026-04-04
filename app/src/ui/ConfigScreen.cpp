/*
 * ConfigScreen.cpp
 *
 * This class is responsible for displaying the config screen.
 * Author: Kaan Aksoy
 */

#include "ConfigScreen.h"

ConfigScreen::ConfigScreen() {}

ConfigScreen::~ConfigScreen() {}

void ConfigScreen::init_config_qr_code() {
  // TODO: Implement this
}

void ConfigScreen::init_refresh_button() {
  // TODO: Implement this
}

void ConfigScreen::init(lv_obj_t *parent) {
  this->parent = parent;
  init_config_qr_code();
  init_refresh_button();
}

void ConfigScreen::set_config_url() {
  // TODO: Implement this
}
