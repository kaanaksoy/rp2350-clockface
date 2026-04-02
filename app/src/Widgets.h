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
#include <cstdint>

#define NUM_ARCS 6

struct clock_time_t {
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
};

struct air_quality_t {
  uint8_t temperature;
  uint8_t humidity;
  uint8_t particulate_matter;
  uint8_t voc;
};

class Widgets {
public:
  Widgets();
  virtual ~Widgets();

  void init(clock_time_t time);

  void set_time(clock_time_t time);

  void set_air_quality(air_quality_t air_quality);

private:
  int16_t calculate_seconds_angle(int32_t seconds);
  int16_t calculate_minutes_angle(int32_t minutes);
  int16_t calculate_hours_angle(int32_t hours, int32_t minutes);

  void init_clock_bg();
  void init_clock_hands();
  static void clock_timer_callback(lv_timer_t *timer);

  void init_label_complications();

  void init_arc_complications();

  lv_obj_t *xTV;

  lv_timer_t *clock_timer;

  lv_obj_t *seconds_hand;
  lv_obj_t *minutes_hand;
  lv_obj_t *hours_hand;

  lv_obj_t *temp_label;
  lv_obj_t *humidity_label;

  lv_obj_t *voc_arc;
  lv_obj_t *particulate_matter_arc;

  clock_time_t current_time;
  air_quality_t air_quality;
};

#endif /* EXP_LVGLDASHBOARD_SRC_WIDGETS_H_ */
