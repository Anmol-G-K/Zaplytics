#ifndef SSD1306_H
#define SSD1306_H

#include "main.h"
#include <stdint.h>
#include <string.h>

/* ── Configuration ─────────────────────────────────────────────────── */
#define SSD1306_I2C_ADDR    (0x3C << 1)   /* 0x78 on wire; use 0x3D<<1 if SA0=1 */
#define SSD1306_WIDTH       128
#define SSD1306_HEIGHT      64

/* ── Public API ────────────────────────────────────────────────────── */
void     SSD1306_Init(I2C_HandleTypeDef *hi2c);
void     SSD1306_Clear(void);
void     SSD1306_Fill(uint8_t pattern);
void     SSD1306_DrawPixel(uint8_t x, uint8_t y, uint8_t color);
void     SSD1306_WriteString(uint8_t x, uint8_t page, const char *str);
void     SSD1306_UpdateScreen(void);         /* DMA flush */
uint8_t  SSD1306_IsReady(void);              /* non-blocking transfer check */

/* Called from HAL_I2C_MasterTxCpltCallback in main.c */
void     SSD1306_TxCpltCallback(I2C_HandleTypeDef *hi2c);

#endif /* SSD1306_H */
