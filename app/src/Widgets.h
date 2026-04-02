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

struct clock_time_t {
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
};

struct air_quality_t {
  uint8_t temperature;        // 0-99
  uint8_t humidity;           // 0-99
  uint8_t particulate_matter; // 0-100
  uint8_t voc;                // 0-100
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

  void update_complications();

  lv_timer_t *clock_timer = nullptr;

  lv_obj_t *seconds_hand = nullptr;
  lv_obj_t *minutes_hand = nullptr;
  lv_obj_t *hours_hand = nullptr;

  lv_obj_t *temp_label = nullptr;
  lv_obj_t *humidity_label = nullptr;

  lv_obj_t *voc_arc = nullptr;
  lv_obj_t *particulate_matter_arc = nullptr;

  clock_time_t current_time;
  air_quality_t air_quality = {22, 40, 25, 75};
};

#endif /* EXP_LVGLDASHBOARD_SRC_WIDGETS_H_ */
