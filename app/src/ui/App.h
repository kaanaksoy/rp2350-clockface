/*
 * App.h
 *
 * This class is responsible for the main application.
 * Author: Kaan Aksoy
 */

#ifndef EXP_LVGLDASHBOARD_SRC_APP_H_
#define EXP_LVGLDASHBOARD_SRC_APP_H_

#include "src/core/lv_obj.h"

class App {
public:
  App();
  virtual ~App();

  void init();

  void run();

private:
  void init_clock_screen();

  void init_tileview();
  lv_obj_t *tv;
};

#endif /* EXP_LVGLDASHBOARD_SRC_APP_H_ */
