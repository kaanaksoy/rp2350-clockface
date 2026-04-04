/*
 * StyledButton.h
 *
 * This class is responsible for displaying a styled button.
 * Author: Kaan Aksoy
 */

#ifndef EXP_LVGLDASHBOARD_SRC_WIDGETS_STYLED_BUTTON_H_
#define EXP_LVGLDASHBOARD_SRC_WIDGETS_STYLED_BUTTON_H_

#include "src/core/lv_obj.h"

enum StyledButtonType { BUTTON_PRIMARY = 0, BUTTON_NEUTRAL = 1 };

struct StyledButtonConfig {
  const char *text;
  lv_coord_t width;
  lv_coord_t height;
  lv_event_cb_t on_click;
  StyledButtonType type;
  void *user_data;
};
namespace StyledButton {
lv_obj_t *create(lv_obj_t *parent, const StyledButtonConfig &cfg);
}

#endif /* EXP_LVGLDASHBOARD_SRC_WIDGETS_STYLED_BUTTON_H_ */
