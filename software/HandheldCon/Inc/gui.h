#ifndef __GUI_H
#define __GUI_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "arm_math.h"
	 
uint16_t LCD_BGR2RGB(uint16_t c);
void Gui_Circle(uint16_t X,uint16_t Y,uint16_t R,uint16_t fc);
void Gui_DrawLine(uint16_t x0, uint16_t y0,uint16_t x1, uint16_t y1,uint16_t Color);
void Gui_box(uint16_t x, uint16_t y, uint16_t w, uint16_t h,uint16_t bc);
void Gui_box2(uint16_t x,uint16_t y,uint16_t w,uint16_t h, uint8_t mode);
void DisplayButtonDown(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void DisplayButtonUp(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void Gui_DrawFont_GBK16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s);
void Gui_DrawFont_GBK24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s);
void Gui_DrawFont_Num32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint16_t num);	 
void LCD_OUTPUT_Float(uint16_t LineX, uint16_t LineY, char *string,float32_t string_to_display);
void LCD_DrawSqure(uint16_t x,uint16_t y,uint16_t whith,uint16_t length,uint16_t color);
void LCD_DrawSqure1(uint16_t x,uint16_t y,uint16_t width,uint16_t length,uint16_t border_color,uint16_t internal_color);
void LCD_DrawFullCircle(uint16_t Xpos,uint16_t Ypos,uint16_t Radius,uint16_t color);
#ifdef __cplusplus
}
#endif
#endif /*__GUI_H */



