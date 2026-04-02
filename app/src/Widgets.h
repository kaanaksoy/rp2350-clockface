/*
 * Widgets.h
 *
 */

#ifndef EXP_LVGLDASHBOARD_SRC_WIDGETS_H_
#define EXP_LVGLDASHBOARD_SRC_WIDGETS_H_

#include "lvgl.h"
#include "pico/stdlib.h"
#include "src/core/lv_obj.h"
#include "src/misc/lv_area.h"

#define NUM_ARCS 6

struct clock_time_t {
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
};

class Widgets {
public:
  Widgets();
  virtual ~Widgets();

  void init(clock_time_t time);

  void set_time(clock_time_t time);

private:
  int16_t calculate_seconds_angle(int32_t seconds);

  int16_t calculate_minutes_angle(int32_t minutes);

  int16_t calculate_hours_angle(int32_t hours, int32_t minutes);

  void init_clock_bg();

  void init_clock_hands();

  static void clock_timer_callback(lv_timer_t *timer);

  lv_timer_t *clock_timer;

  lv_obj_t *xTV;

  lv_obj_t *seconds_hand;
  lv_obj_t *minutes_hand;
  lv_obj_t *hours_hand;

  clock_time_t current_time;
};

#endif /* EXP_LVGLDASHBOARD_SRC_WIDGETS_H_ */
