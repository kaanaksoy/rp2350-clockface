/*
 * StyledButton.cpp
 *
 * This class is responsible for displaying a styled button.
 * Author: Kaan Aksoy
 */

#include "StyledButton.h"
#include "src/core/lv_event.h"
#include "src/core/lv_obj.h"
#include "src/core/lv_obj_pos.h"
#include "src/core/lv_obj_style.h"
#include "src/misc/lv_color.h"
#include "src/misc/lv_style.h"
#include "src/font/lv_font.h"
#include "src/widgets/lv_btn.h"
#include "src/widgets/lv_label.h"

LV_FONT_DECLARE(din_cond_medium_regular_20)

/*
 * Dark theme tokens sourced from figma_styles.json
 *
 * Elevation 2 - Raised has 3 drop-shadows. LVGL supports one shadow per
 * object, so we stack two rects behind the button face, each carrying one
 * of the dark shadows. The button face carries the white highlight shadow.
 *
 * Layer order (bottom → top):
 *   shadow_outer  — 0px 3px 6px  rgba(0,0,0,0.45)
 *   shadow_mid    — 0px 2px 3px  rgba(0,0,0,0.6)
 *   button face   — 0px 1px 1px  rgba(255,255,255,0.12)  (white highlight)
 */

// ── Neutral gradient tokens (Dark) ──────────────────────────────────────
static constexpr uint32_t NEUTRAL_RAISED_START = 0x3c3935;
static constexpr uint32_t NEUTRAL_RAISED_END = 0x2e2c29;
static constexpr uint32_t NEUTRAL_PRESSED_START = 0x2e2c29;
static constexpr uint32_t NEUTRAL_PRESSED_END = 0x3c3935;
static constexpr uint32_t NEUTRAL_TEXT = 0xEAE7E2;

// ── Primary (Accent) gradient tokens (Dark) ─────────────────────────────
static constexpr uint32_t PRIMARY_RAISED_START = 0xa9141a;
static constexpr uint32_t PRIMARY_RAISED_END = 0xd81e25;
static constexpr uint32_t PRIMARY_PRESSED_START = 0xd81e25;
static constexpr uint32_t PRIMARY_PRESSED_END = 0xa9141a;
static constexpr uint32_t PRIMARY_TEXT = 0xE7E2D8;

// ── Shared tokens ───────────────────────────────────────────────────────
static constexpr uint32_t STROKE_COLOR = 0xFFFFFF;
static constexpr lv_opa_t STROKE_OPA = 31;
static constexpr lv_coord_t STROKE_W = 1;
static constexpr lv_coord_t CTRL_RADIUS = 8;
static constexpr lv_coord_t PAD_H = 16;
static constexpr lv_coord_t PAD_V = 12;
static constexpr lv_coord_t SHADOW_MARGIN = 12;

// ── Styles ──────────────────────────────────────────────────────────────
// Shadow rects (shared across variants — bg set inline per type)
static lv_style_t style_shadow_outer;
static lv_style_t style_shadow_mid;

// Neutral face
static lv_style_t style_neutral_face_default;
static lv_style_t style_neutral_face_pressed;

// Primary face
static lv_style_t style_primary_face_default;
static lv_style_t style_primary_face_pressed;

static bool styles_initialized = false;

static void init_face_style(lv_style_t *style, uint32_t grad_start,
                            uint32_t grad_end, uint32_t text_color) {
  lv_style_init(style);
  lv_style_set_radius(style, CTRL_RADIUS);
  lv_style_set_bg_opa(style, LV_OPA_COVER);
  lv_style_set_bg_color(style, lv_color_hex(grad_start));
  lv_style_set_bg_grad_color(style, lv_color_hex(grad_end));
  lv_style_set_bg_grad_dir(style, LV_GRAD_DIR_VER);
  lv_style_set_border_color(style, lv_color_hex(STROKE_COLOR));
  lv_style_set_border_opa(style, STROKE_OPA);
  lv_style_set_border_width(style, STROKE_W);
  lv_style_set_shadow_color(style, lv_color_hex(0xFFFFFF));
  lv_style_set_shadow_opa(style, 31);
  lv_style_set_shadow_width(style, 1);
  lv_style_set_shadow_ofs_y(style, 1);
  lv_style_set_shadow_spread(style, 0);
  lv_style_set_pad_hor(style, PAD_H);
  lv_style_set_pad_ver(style, PAD_V);
  lv_style_set_text_color(style, lv_color_hex(text_color));
  lv_style_set_text_font(style, &din_cond_medium_regular_20);
}

static void init_pressed_style(lv_style_t *style, uint32_t grad_start,
                               uint32_t grad_end) {
  lv_style_init(style);
  lv_style_set_bg_color(style, lv_color_hex(grad_start));
  lv_style_set_bg_grad_color(style, lv_color_hex(grad_end));
  lv_style_set_shadow_opa(style, LV_OPA_TRANSP);
}

static void ensure_styles() {
  if (styles_initialized)
    return;
  styles_initialized = true;

  // --- Outer shadow: 0px 3px 6px rgba(0,0,0,0.45) ---
  lv_style_init(&style_shadow_outer);
  lv_style_set_radius(&style_shadow_outer, CTRL_RADIUS);
  lv_style_set_bg_opa(&style_shadow_outer, LV_OPA_COVER);
  lv_style_set_border_width(&style_shadow_outer, 0);
  lv_style_set_shadow_color(&style_shadow_outer, lv_color_hex(0x000000));
  lv_style_set_shadow_opa(&style_shadow_outer, 115);
  lv_style_set_shadow_width(&style_shadow_outer, 6);
  lv_style_set_shadow_ofs_y(&style_shadow_outer, 3);
  lv_style_set_shadow_spread(&style_shadow_outer, 0);

  // --- Mid shadow: 0px 2px 3px rgba(0,0,0,0.6) ---
  lv_style_init(&style_shadow_mid);
  lv_style_set_radius(&style_shadow_mid, CTRL_RADIUS);
  lv_style_set_bg_opa(&style_shadow_mid, LV_OPA_COVER);
  lv_style_set_border_width(&style_shadow_mid, 0);
  lv_style_set_shadow_color(&style_shadow_mid, lv_color_hex(0x000000));
  lv_style_set_shadow_opa(&style_shadow_mid, 153);
  lv_style_set_shadow_width(&style_shadow_mid, 3);
  lv_style_set_shadow_ofs_y(&style_shadow_mid, 2);
  lv_style_set_shadow_spread(&style_shadow_mid, 0);

  // --- Neutral face ---
  init_face_style(&style_neutral_face_default, NEUTRAL_RAISED_START,
                  NEUTRAL_RAISED_END, NEUTRAL_TEXT);
  init_pressed_style(&style_neutral_face_pressed, NEUTRAL_PRESSED_START,
                     NEUTRAL_PRESSED_END);

  // --- Primary face ---
  init_face_style(&style_primary_face_default, PRIMARY_RAISED_START,
                  PRIMARY_RAISED_END, PRIMARY_TEXT);
  init_pressed_style(&style_primary_face_pressed, PRIMARY_PRESSED_START,
                     PRIMARY_PRESSED_END);
}

static void btn_state_event_cb(lv_event_t *e) {
  lv_obj_t *btn = lv_event_get_target(e);
  lv_obj_t *container = lv_obj_get_parent(btn);
  lv_obj_t *shadow_outer = lv_obj_get_child(container, 0);
  lv_obj_t *shadow_mid = lv_obj_get_child(container, 1);

  lv_event_code_t code = lv_event_get_code(e);
  if (code == LV_EVENT_PRESSED) {
    lv_obj_add_flag(shadow_outer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(shadow_mid, LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_clear_flag(shadow_outer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(shadow_mid, LV_OBJ_FLAG_HIDDEN);
  }
}

static void apply_shadow_rect_bg(lv_obj_t *obj, uint32_t grad_start,
                                 uint32_t grad_end) {
  lv_obj_set_style_bg_color(obj, lv_color_hex(grad_start), 0);
  lv_obj_set_style_bg_grad_color(obj, lv_color_hex(grad_end), 0);
  lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, 0);
}

lv_obj_t *StyledButton::create(lv_obj_t *parent,
                               const StyledButtonConfig &cfg) {
  ensure_styles();

  bool is_primary = cfg.type == BUTTON_PRIMARY;
  uint32_t grad_start =
      is_primary ? PRIMARY_RAISED_START : NEUTRAL_RAISED_START;
  uint32_t grad_end = is_primary ? PRIMARY_RAISED_END : NEUTRAL_RAISED_END;

  lv_coord_t btn_w = cfg.width;
  lv_coord_t btn_h = cfg.height;

  lv_obj_t *container = lv_obj_create(parent);
  lv_obj_remove_style_all(container);
  lv_obj_set_size(container, btn_w + SHADOW_MARGIN * 2,
                  btn_h + SHADOW_MARGIN * 2);
  lv_obj_clear_flag(container, LV_OBJ_FLAG_SCROLLABLE);

  lv_obj_t *shadow_outer = lv_obj_create(container);
  lv_obj_remove_style_all(shadow_outer);
  lv_obj_add_style(shadow_outer, &style_shadow_outer, 0);
  apply_shadow_rect_bg(shadow_outer, grad_start, grad_end);
  lv_obj_set_size(shadow_outer, btn_w, btn_h);
  lv_obj_center(shadow_outer);
  lv_obj_clear_flag(shadow_outer, LV_OBJ_FLAG_CLICKABLE);

  lv_obj_t *shadow_mid = lv_obj_create(container);
  lv_obj_remove_style_all(shadow_mid);
  lv_obj_add_style(shadow_mid, &style_shadow_mid, 0);
  apply_shadow_rect_bg(shadow_mid, grad_start, grad_end);
  lv_obj_set_size(shadow_mid, btn_w, btn_h);
  lv_obj_center(shadow_mid);
  lv_obj_clear_flag(shadow_mid, LV_OBJ_FLAG_CLICKABLE);

  lv_obj_t *btn = lv_btn_create(container);
  lv_obj_remove_style_all(btn);
  if (is_primary) {
    lv_obj_add_style(btn, &style_primary_face_default, LV_STATE_DEFAULT);
    lv_obj_add_style(btn, &style_primary_face_pressed, LV_STATE_PRESSED);
  } else {
    lv_obj_add_style(btn, &style_neutral_face_default, LV_STATE_DEFAULT);
    lv_obj_add_style(btn, &style_neutral_face_pressed, LV_STATE_PRESSED);
  }
  lv_obj_set_size(btn, btn_w, btn_h);
  lv_obj_center(btn);

  lv_obj_t *label = lv_label_create(btn);
  lv_label_set_text(label, cfg.text);
  lv_obj_center(label);

  lv_obj_add_event_cb(btn, btn_state_event_cb, LV_EVENT_PRESSED, NULL);
  lv_obj_add_event_cb(btn, btn_state_event_cb, LV_EVENT_RELEASED, NULL);
  lv_obj_add_event_cb(btn, btn_state_event_cb, LV_EVENT_PRESS_LOST, NULL);

  if (cfg.on_click) {
    lv_obj_add_event_cb(btn, cfg.on_click, LV_EVENT_CLICKED, cfg.user_data);
  }

  return container;
}
