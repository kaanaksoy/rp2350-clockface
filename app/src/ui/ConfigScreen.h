/*
 * ConfigScreen.h
 *
 * This class is responsible for displaying the config screen.
 * Author: Kaan Aksoy
 */

#ifndef EXP_LVGLDASHBOARD_SRC_CONFIGSCREEN_H_
#define EXP_LVGLDASHBOARD_SRC_CONFIGSCREEN_H_

#include "lvgl.h"
#include "src/core/lv_obj.h"
#include <cstdint>

class ConfigScreen {
public:
  ConfigScreen();
  virtual ~ConfigScreen();

  void init(lv_obj_t *parent);

  void set_config_url();

private:
  lv_obj_t *parent = nullptr;

  void init_config_qr_code();

  void init_refresh_button();
};

#endif /* EXP_LVGLDASHBOARD_SRC_CONFIGSCREEN_H_ */
