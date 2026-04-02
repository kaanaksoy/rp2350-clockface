/*
 * Widgets.cpp
 *
 */

#include "Widgets.h"
#include "src/core/lv_obj.h"
#include "src/core/lv_obj_pos.h"
#include "src/core/lv_obj_style.h"
#include "src/widgets/lv_img.h"
#include <cstdio>

Widgets::Widgets() {}

Widgets::~Widgets() { lv_timer_del(clock_timer); }

int16_t Widgets::calculate_seconds_angle(int32_t seconds) {
  return -900 + (seconds * 60);
}

int16_t Widgets::calculate_minutes_angle(int32_t minutes) {
  return -900 + (minutes * 60);
}

int16_t Widgets::calculate_hours_angle(int32_t hours, int32_t minutes) {
  return -900 + (hours * 300) + (minutes * 5);
}

void Widgets::init_clock_bg() {

  LV_IMG_DECLARE(clockface_bg_rp2350_dark)
  lv_obj_t *bg = lv_img_create(lv_scr_act());
  lv_img_set_src(bg, &clockface_bg_rp2350_dark);
  lv_obj_center(bg);
}

void Widgets::init_clock_hands() {
  LV_IMG_DECLARE(hours_hand_rp2350_dark)
  hours_hand = lv_img_create(lv_scr_act());
  lv_img_set_src(hours_hand, &hours_hand_rp2350_dark);
  lv_obj_set_size(hours_hand, 102, 32);
  lv_obj_align(hours_hand, LV_ALIGN_CENTER, 35, 0);
  lv_img_set_pivot(hours_hand, 16, 16);
  lv_img_set_angle(hours_hand, calculate_hours_angle(current_time.hours,
                                                     current_time.minutes));

  LV_IMG_DECLARE(minutes_hand_rp2350_dark)
  minutes_hand = lv_img_create(lv_scr_act());
  lv_img_set_src(minutes_hand, &minutes_hand_rp2350_dark);
  lv_obj_set_size(minutes_hand, 181, 28);
  lv_obj_align(minutes_hand, LV_ALIGN_CENTER, 76, 0);
  lv_img_set_pivot(minutes_hand, 14, 14);
  lv_img_set_angle(minutes_hand, calculate_minutes_angle(current_time.minutes));

  LV_IMG_DECLARE(seconds_hand_rp2350_dark)
  seconds_hand = lv_img_create(lv_scr_act());
  lv_img_set_src(seconds_hand, &seconds_hand_rp2350_dark);
  lv_obj_set_size(seconds_hand, 236, 56);
  lv_obj_align(seconds_hand, LV_ALIGN_CENTER, 90, 0);
  lv_img_set_pivot(seconds_hand, 28, 28);
  lv_img_set_angle(seconds_hand, calculate_seconds_angle(current_time.seconds));
}

void Widgets::set_time(clock_time_t time) { current_time = time; }

void Widgets::clock_timer_callback(lv_timer_t *timer) {
  Widgets *self = (Widgets *)timer->user_data;

  self->current_time.seconds++;
  if (self->current_time.seconds > 60) {
    self->current_time.seconds = self->current_time.seconds % 60;
    self->current_time.minutes++;
    if (self->current_time.minutes > 60) {
      self->current_time.minutes = self->current_time.minutes % 60;
      self->current_time.hours++;
      if (self->current_time.hours > 12) {
        self->current_time.hours = self->current_time.hours % 12;
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
}

void Widgets::init(clock_time_t time) {

  /*Create tileview*/
  xTV = lv_tileview_create(lv_scr_act());
  lv_obj_set_scrollbar_mode(xTV, LV_SCROLLBAR_MODE_OFF);

  set_time(time);

  init_clock_bg();
  init_clock_hands();

  clock_timer = lv_timer_create(clock_timer_callback, 1000, this);
}
