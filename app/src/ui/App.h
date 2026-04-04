/*
 * App.h
 *
 * This class is responsible for the main application.
 * Author: Kaan Aksoy
 */

#ifndef EXP_LVGLDASHBOARD_SRC_APP_H_
#define EXP_LVGLDASHBOARD_SRC_APP_H_

#include "ClockScreen.h"
#include "ConfigScreen.h"
#include "src/core/lv_obj.h"

class App {
public:
  App();
  virtual ~App();

  void init();

  void run();

private:
  void init_tileview();
  lv_obj_t *tv;
  ClockScreen clock_screen;
  ConfigScreen config_screen;
};

#endif /* EXP_LVGLDASHBOARD_SRC_APP_H_ */
