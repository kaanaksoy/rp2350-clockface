/*
 * ClockScreen.cpp
 *
 */

#include "ClockScreen.h"
#include "src/core/lv_disp.h"
#include "src/core/lv_event.h"
#include "src/core/lv_obj.h"
#include "src/core/lv_obj_pos.h"
#include "src/core/lv_obj_style.h"
#include "src/font/lv_font.h"
#include "src/misc/lv_area.h"
#include "src/misc/lv_color.h"
#include "src/misc/lv_style.h"
#include "src/widgets/lv_arc.h"
#include "src/widgets/lv_img.h"
#include "src/widgets/lv_label.h"
#include <cstddef>
#include <cstdio>

ClockScreen::ClockScreen() {}

ClockScreen::~ClockScreen() {
  if (clock_timer) {
    lv_timer_del(clock_timer);
  }
}

int16_t ClockScreen::calculate_seconds_angle(int32_t seconds) {
  return -900 + (seconds * 60);
}

int16_t ClockScreen::calculate_minutes_angle(int32_t minutes) {
  return -900 + (minutes * 60);
}

int16_t ClockScreen::calculate_hours_angle(int32_t hours, int32_t minutes) {
  return -900 + (hours * 300) + (minutes * 5);
}

void ClockScreen::init_clock_bg() {

  LV_IMG_DECLARE(clockface_bg_rp2350_dark)
  lv_obj_t *bg = lv_img_create(clock_screen);
  lv_img_set_src(bg, &clockface_bg_rp2350_dark);
  lv_obj_center(bg);
}

void ClockScreen::init_clock_hands() {
  LV_IMG_DECLARE(hours_hand_rp2350_dark)
  hours_hand = lv_img_create(clock_screen);
  lv_img_set_src(hours_hand, &hours_hand_rp2350_dark);
  lv_obj_set_size(hours_hand, 102, 32);
  lv_obj_align(hours_hand, LV_ALIGN_CENTER, 35, 0);
  lv_img_set_pivot(hours_hand, 16, 16);
  lv_img_set_angle(hours_hand, calculate_hours_angle(current_time.hours,
                                                     current_time.minutes));

  LV_IMG_DECLARE(minutes_hand_rp2350_dark)
  minutes_hand = lv_img_create(clock_screen);
  lv_img_set_src(minutes_hand, &minutes_hand_rp2350_dark);
  lv_obj_set_size(minutes_hand, 181, 28);
  lv_obj_align(minutes_hand, LV_ALIGN_CENTER, 76, 0);
  lv_img_set_pivot(minutes_hand, 14, 14);
  lv_img_set_angle(minutes_hand, calculate_minutes_angle(current_time.minutes));

  LV_IMG_DECLARE(seconds_hand_rp2350_dark)
  seconds_hand = lv_img_create(clock_screen);
  lv_img_set_src(seconds_hand, &seconds_hand_rp2350_dark);
  lv_obj_set_size(seconds_hand, 236, 56);
  lv_obj_align(seconds_hand, LV_ALIGN_CENTER, 90, 0);
  lv_img_set_pivot(seconds_hand, 28, 28);
  lv_img_set_angle(seconds_hand, calculate_seconds_angle(current_time.seconds));
}

void ClockScreen::set_time(clock_time_t time) { current_time = time; }

void ClockScreen::set_air_quality(air_quality_t air_quality) {
  this->air_quality = air_quality;
}

void ClockScreen::clock_timer_callback(lv_timer_t *timer) {
  ClockScreen *self = (ClockScreen *)timer->user_data;

  self->current_time.seconds++;
  if (self->current_time.seconds >= 60) {
    self->current_time.seconds = 0;
    self->current_time.minutes++;
    if (self->current_time.minutes >= 60) {
      self->current_time.minutes = 0;
      self->current_time.hours++;
      if (self->current_time.hours >= 12) {
        self->current_time.hours = 0;
      }
    }
  }

  int16_t secondsAngle =
      self->calculate_seconds_angle(self->current_time.seconds);
  int16_t minutesAngle =
      self->calculate_minutes_angle(self->current_time.minutes);
  int16_t hoursAngle = self->calculate_hours_angle(self->current_time.hours,
                                                   self->current_time.minutes);
  lv_img_set_angle(self->seconds_hand, secondsAngle);
  lv_img_set_angle(self->minutes_hand, minutesAngle);
  lv_img_set_angle(self->hours_hand, hoursAngle);

  self->update_complications();
}

void ClockScreen::init_label_complications() {

  LV_FONT_DECLARE(din_cond_medium_regular_num_96)
  static lv_style_t temp_label_style;
  lv_style_init(&temp_label_style);
  lv_style_set_text_opa(&temp_label_style, LV_OPA_COVER);
  lv_style_set_text_color(&temp_label_style, lv_color_hex(0xEAE7E2));
  lv_style_set_text_font(&temp_label_style, &din_cond_medium_regular_num_96);

  temp_label = lv_label_create(clock_screen);
  lv_obj_add_style(temp_label, &temp_label_style, 0);
  lv_label_set_text(temp_label, "22");
  lv_obj_set_style_text_align(temp_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);
  lv_obj_align(temp_label, LV_ALIGN_TOP_MID, 0, 50);

  LV_FONT_DECLARE(din_cond_medium_regular_num_72)
  static lv_style_t humidity_label_style;
  lv_style_init(&humidity_label_style);
  lv_style_set_text_opa(&humidity_label_style, LV_OPA_COVER);
  lv_style_set_text_color(&humidity_label_style, lv_color_hex(0xEAE7E2));
  lv_style_set_text_font(&humidity_label_style,
                         &din_cond_medium_regular_num_72);

  humidity_label = lv_label_create(clock_screen);
  lv_obj_add_style(humidity_label, &humidity_label_style, 0);
  lv_label_set_text(humidity_label, "40");
  lv_obj_set_style_text_align(humidity_label, LV_TEXT_ALIGN_CENTER,
                              LV_PART_MAIN);
  lv_obj_align(humidity_label, LV_ALIGN_BOTTOM_MID, 0, -46);
}

void ClockScreen::init_arc_complications() {

  voc_arc = lv_arc_create(clock_screen);
  lv_obj_set_size(voc_arc, 400, 400);
  lv_arc_set_bg_angles(voc_arc, 150, 210);
  lv_obj_remove_style(voc_arc, NULL, LV_PART_KNOB);
  lv_obj_clear_flag(voc_arc, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_set_style_arc_color(voc_arc, lv_color_hex(0xA9141A),
                             LV_PART_INDICATOR);
  lv_obj_set_style_arc_width(voc_arc, 12, LV_PART_INDICATOR);
  lv_obj_set_style_arc_rounded(voc_arc, true, LV_PART_INDICATOR);
  lv_obj_set_style_arc_opa(voc_arc, LV_OPA_TRANSP,
                           LV_PART_MAIN); // hide the background track
  lv_obj_set_style_bg_opa(voc_arc, LV_OPA_TRANSP, LV_PART_MAIN);
  lv_arc_set_value(voc_arc, 75);
  lv_obj_center(voc_arc);
  lv_event_send(voc_arc, LV_EVENT_VALUE_CHANGED, NULL);

  particulate_matter_arc = lv_arc_create(clock_screen);
  lv_obj_set_size(particulate_matter_arc, 400, 400);
  lv_arc_set_bg_angles(particulate_matter_arc, 330, 30);
  lv_arc_set_mode(particulate_matter_arc, LV_ARC_MODE_REVERSE);
  lv_obj_remove_style(particulate_matter_arc, NULL, LV_PART_KNOB);
  lv_obj_clear_flag(particulate_matter_arc, LV_OBJ_FLAG_CLICKABLE);
  lv_obj_set_style_arc_color(particulate_matter_arc, lv_color_hex(0xA9141A),
                             LV_PART_INDICATOR);
  lv_obj_set_style_arc_width(particulate_matter_arc, 12, LV_PART_INDICATOR);
  lv_obj_set_style_arc_rounded(particulate_matter_arc, true, LV_PART_INDICATOR);
  lv_obj_set_style_arc_opa(particulate_matter_arc, LV_OPA_TRANSP,
                           LV_PART_MAIN); // hide the background track
  lv_obj_set_style_bg_opa(particulate_matter_arc, LV_OPA_TRANSP, LV_PART_MAIN);
  lv_arc_set_value(particulate_matter_arc, 25);
  lv_obj_center(particulate_matter_arc);
  lv_event_send(particulate_matter_arc, LV_EVENT_VALUE_CHANGED, NULL);
}

void ClockScreen::init(clock_time_t time) {

  clock_screen = lv_obj_create(NULL);
  set_time(time);
  init_clock_bg();
  init_label_complications();
  init_arc_complications();
  init_clock_hands();

  clock_timer = lv_timer_create(clock_timer_callback, 1000, this);
}

void ClockScreen::update_complications() {
  lv_label_set_text_fmt(temp_label, "%d", air_quality.temperature);
  lv_label_set_text_fmt(humidity_label, "%d", air_quality.humidity);
  lv_arc_set_value(voc_arc, air_quality.voc);
  lv_arc_set_value(particulate_matter_arc, air_quality.particulate_matter);
}
