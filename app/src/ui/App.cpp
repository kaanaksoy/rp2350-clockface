/*
 * App.cpp
 *
 * This class is responsible for the main application.
 * Author: Kaan Aksoy
 */

#include "App.h"
#include "src/core/lv_disp.h"
#include "src/core/lv_obj_scroll.h"
#include "src/core/lv_obj_style.h"
#include "src/extra/widgets/tileview/lv_tileview.h"
#include "src/misc/lv_anim.h"
#include "src/misc/lv_area.h"
#include "src/widgets/lv_label.h"
#include <pico/time.h>

App::App() {}

App::~App() {}

void App::init() { init_tileview(); }

void App::run() {
  for (;;) {
    lv_timer_handler();
    sleep_ms(1);
  }
}

void App::init_tileview() {
  tv = lv_tileview_create(lv_scr_act());
  lv_obj_set_scrollbar_mode(tv, LV_SCROLLBAR_MODE_OFF);
  lv_obj_set_style_pad_all(tv, 0, LV_PART_MAIN);
  lv_obj_set_style_bg_color(tv, lv_color_hex(0x1C1B19), LV_PART_MAIN);

  /*Config Screen Tile*/
  lv_obj_t *config_screen_tile = lv_tileview_add_tile(tv, 0, 0, LV_DIR_RIGHT);
  config_screen.init(config_screen_tile);

  /*Clock Screen Tile*/
  lv_obj_t *clock_screen_tile =
      lv_tileview_add_tile(tv, 1, 0, LV_DIR_LEFT | LV_DIR_RIGHT);
  clock_screen.init(clock_screen_tile, {12, 30, 0});

  /*Commands Screen Tile*/
  lv_obj_t *commands_screen_tile = lv_tileview_add_tile(tv, 2, 0, LV_DIR_LEFT);

  lv_obj_t *label = lv_label_create(commands_screen_tile);
  lv_label_set_text(label, "Commands Screen");
  lv_obj_center(label);

  //   lv_obj_set_tile(tv, clock_screen_tile, LV_ANIM_OFF);
}
