/*
 * ConfigScreen.h
 *
 * This class is responsible for displaying the config screen.
 * Author: Kaan Aksoy
 */

#ifndef EXP_LVGLDASHBOARD_SRC_CONFIGSCREEN_H_
#define EXP_LVGLDASHBOARD_SRC_CONFIGSCREEN_H_

#define CONFIG_URL_MAX_LENGTH 256

#include "src/core/lv_obj.h"
#include <cstdint>

class ConfigScreen {
public:
  ConfigScreen();
  virtual ~ConfigScreen();

  void init(lv_obj_t *parent);

  void set_config_url(const char *url, size_t len);

private:
  lv_obj_t *parent = nullptr;

  lv_obj_t *qr_code = nullptr;

  char config_url[CONFIG_URL_MAX_LENGTH] = {};
  size_t config_url_len = 0;

  void init_bg();

  void init_config_qr_code();

  void init_refresh_button();
};

#endif /* EXP_LVGLDASHBOARD_SRC_CONFIGSCREEN_H_ */
