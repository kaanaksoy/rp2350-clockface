/*
 * CommandsScreen.h
 *
 * This class is responsible for displaying the commands screen.
 * Author: Kaan Aksoy
 */

#ifndef EXP_LVGLDASHBOARD_SRC_COMMANDSSCREEN_H_
#define EXP_LVGLDASHBOARD_SRC_COMMANDSSCREEN_H_

#include "src/core/lv_obj.h"
class CommandsScreen {

public:
  CommandsScreen();
  virtual ~CommandsScreen();

  void init(lv_obj_t *parent);

private:
  lv_obj_t *parent = nullptr;

  void init_bg();
  void init_buttons();
};

#endif /* EXP_LVGLDASHBOARD_SRC_COMMANDSSCREEN_H_   */
