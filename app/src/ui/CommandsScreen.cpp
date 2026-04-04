/*
 * CommandsScreen.cpp
 *
 * This class is responsible for displaying the commands screen.
 * Author: Kaan Aksoy
 */

#include "CommandsScreen.h"
#include "src/core/lv_obj_pos.h"
#include "src/widgets/lv_arc.h"
#include "widgets/StyledButton.h"

CommandsScreen::CommandsScreen() {}

CommandsScreen::~CommandsScreen() {}

void CommandsScreen::init_bg() {
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

void CommandsScreen::init_buttons() {
  StyledButtonConfig neutral_cfg = {};
  neutral_cfg.text = "RESTART";
  neutral_cfg.width = 108;
  neutral_cfg.height = 44;
  neutral_cfg.on_click = NULL;
  neutral_cfg.type = BUTTON_NEUTRAL;
  neutral_cfg.user_data = NULL;

  lv_obj_t *neutral_btn = StyledButton::create(parent, neutral_cfg);
  lv_obj_align(neutral_btn, LV_ALIGN_CENTER, 0, 70);

  StyledButtonConfig primary_cfg = {};
  primary_cfg.text = "SHUTDOWN";
  primary_cfg.width = 108;
  primary_cfg.height = 44;
  primary_cfg.on_click = NULL;
  primary_cfg.type = BUTTON_PRIMARY;
  primary_cfg.user_data = NULL;

  lv_obj_t *primary_btn = StyledButton::create(parent, primary_cfg);
  lv_obj_align(primary_btn, LV_ALIGN_CENTER, 0, -70);
}

void CommandsScreen::init(lv_obj_t *parent) {
  this->parent = parent;
  init_bg();
  init_buttons();
}
