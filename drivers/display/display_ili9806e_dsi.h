/*
 * Copyright (c) 2024 Renesas Electronics Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_DRIVERS_DISPLAY_ILITEK_ILI9806E_H_
#define ZEPHYR_DRIVERS_DISPLAY_ILITEK_ILI9806E_H_

#define LCD_TIMINGS_NODE DT_CHILD(DT_NODELABEL(zephyr_lcdif), display_timings)

#define LCD_HTIMMING_SYNC        DT_PROP(LCD_TIMINGS_NODE, hsync_len)
#define LCD_HTIMMING_BACK_PORCH  DT_PROP(LCD_TIMINGS_NODE, hback_porch)
#define LCD_HTIMMING_FRONT_PORCH DT_PROP(LCD_TIMINGS_NODE, hfront_porch)
#define LCD_HACTIVE_LINE         DT_PROP(DT_NODELABEL(zephyr_lcdif), width)
#define LCD_HTIMMING_TOTAL_CYC                                                                     \
	LCD_HACTIVE_LINE + LCD_HTIMMING_BACK_PORCH + LCD_HTIMMING_FRONT_PORCH + LCD_HTIMMING_SYNC

#define LCD_VTIMMING_SYNC        DT_PROP(LCD_TIMINGS_NODE, vsync_len)
#define LCD_VTIMMING_BACK_PORCH  DT_PROP(LCD_TIMINGS_NODE, vback_porch)
#define LCD_VTIMMING_FRONT_PORCH DT_PROP(LCD_TIMINGS_NODE, vfront_porch)
#define LCD_VACTIVE_LINE         DT_PROP(DT_NODELABEL(zephyr_lcdif), height)
#define LCD_VTIMMING_TOTAL_CYC                                                                     \
	LCD_VACTIVE_LINE + LCD_VTIMMING_BACK_PORCH + LCD_VTIMMING_FRONT_PORCH + LCD_VTIMMING_SYNC

#define ILITEK_ILI9806E_HSYNC LCD_HTIMMING_SYNC
#define ILITEK_ILI9806E_HBP   LCD_HTIMMING_BACK_PORCH - LCD_HTIMMING_SYNC
#define ILITEK_ILI9806E_HFP                                                                        \
	LCD_HTIMMING_TOTAL_CYC - LCD_HACTIVE_LINE - LCD_HTIMMING_BACK_PORCH - LCD_HTIMMING_SYNC

#define ILITEK_ILI9806E_VSYNC LCD_VTIMMING_SYNC
#define ILITEK_ILI9806E_VBP   LCD_VTIMMING_BACK_PORCH - LCD_VTIMMING_SYNC
#define ILITEK_ILI9806E_VFP                                                                        \
	LCD_VTIMMING_TOTAL_CYC - LCD_VACTIVE_LINE - LCD_VTIMMING_BACK_PORCH - LCD_VTIMMING_SYNC

#endif /* ZEPHYR_DRIVERS_DISPLAY_ILITEK_ILI9806E_H_ */
