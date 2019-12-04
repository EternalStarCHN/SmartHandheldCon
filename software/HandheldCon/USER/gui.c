#include "font.h"
#include "gui.h"
#include "spi.h"
#include <stdio.h>
//��ILI93xx����������ΪGBR��ʽ��������д���ʱ��ΪRGB��ʽ��
//ͨ���ú���ת��
//c:GBR��ʽ����ɫֵ
//����ֵ��RGB��ʽ����ɫֵ
uint16_t Adc_table[2048];
float FFT_table[2048];
int LastX_Wave=0,LastY_Wave=70;
int LastX_FFT=20,LastY_FFT=200;
uint16_t LCD_BGR2RGB(uint16_t c)
{
  uint16_t r,g,b,rgb;   
  b=(c>>0)&0x1f;
  g=(c>>5)&0x3f;
  r=(c>>11)&0x1f;	 
  rgb=(b<<11)+(g<<5)+(r<<0);		 
  return(rgb);

}

void Gui_Circle(uint16_t X,uint16_t Y,uint16_t R,uint16_t fc) 
{//Bresenham�㷨 
    uint16_t a,b; 
    int32_t c; 
    a=0; 
    b=R; 
    c=3-2*R; 
    while (a<b) 
    { 
        Gui_DrawPoint(X+a,Y+b,fc);     //        7 
        Gui_DrawPoint(X-a,Y+b,fc);     //        6 
        Gui_DrawPoint(X+a,Y-b,fc);     //        2 
        Gui_DrawPoint(X-a,Y-b,fc);     //        3 
        Gui_DrawPoint(X+b,Y+a,fc);     //        8 
        Gui_DrawPoint(X-b,Y+a,fc);     //        5 
        Gui_DrawPoint(X+b,Y-a,fc);     //        1 
        Gui_DrawPoint(X-b,Y-a,fc);     //        4 

        if(c<0) c=c+4*a+6; 
        else 
        { 
            c=c+4*(a-b)+10; 
            b-=1; 
        } 
       a+=1; 
    } 
    if (a==b) 
    { 
        Gui_DrawPoint(X+a,Y+b,fc); 
        Gui_DrawPoint(X+a,Y+b,fc); 
        Gui_DrawPoint(X+a,Y-b,fc); 
        Gui_DrawPoint(X-a,Y-b,fc); 
        Gui_DrawPoint(X+b,Y+a,fc); 
        Gui_DrawPoint(X-b,Y+a,fc); 
        Gui_DrawPoint(X+b,Y-a,fc); 
        Gui_DrawPoint(X-b,Y-a,fc); 
    } 
	
} 
//���ߺ�����ʹ��Bresenham �����㷨
void Gui_DrawLine(uint16_t x0, uint16_t y0,uint16_t x1, uint16_t y1,uint16_t Color)   
{
int32_t dx,         // difference in x's
    dy,             // difference in y's
    dx2,            // dx,dy * 2
    dy2, 
    x_inc,          // amount in pixel space to move during drawing
    y_inc,          // amount in pixel space to move during drawing
    error,          // the discriminant i.e. error i.e. decision variable
    index;          // used for looping	


	Lcd_SetXY(x0,y0);
	dx = x1-x0;				//����x����
	dy = y1-y0;				//����y����

	if (dx>=0)
	{
		x_inc = 1;
	}
	else
	{
		x_inc = -1;
		dx    = -dx;  
	} 
	
	if (dy>=0)
	{
		y_inc = 1;
	} 
	else
	{
		y_inc = -1;
		dy    = -dy; 
	} 

	dx2 = dx << 1;
	dy2 = dy << 1;
	//x�������y���룬��ôÿ��x����ֻ��һ���㣬ÿ��y���������ɸ���
	//���ߵĵ�������x���룬��x���������
	if (dx > dy)
	{
		// initialize error term
		error = dy2 - dx; 

		// draw the line
		for (index=0; index <= dx; index++)//Ҫ���ĵ������ᳬ��x����
		{
			//����
			Gui_DrawPoint(x0,y0,Color);
			
			// test if error has overflowed
			if (error >= 0) //�Ƿ���Ҫ����y����ֵ
			{
				error-=dx2;

				// move to next line
				y0+=y_inc;//����y����ֵ
			} // end if error overflowed

			// adjust the error term
			error+=dy2;

			// move to the next pixel
			x0+=x_inc;//x����ֵÿ�λ���󶼵���1
		} // end for
	} // end if |slope| <= 1
	//y�����x�ᣬ��ÿ��y����ֻ��һ���㣬x�����ɸ���
	//��y��Ϊ��������
	else
	{
		// initialize error term
		error = dx2 - dy; 

		// draw the line
		for (index=0; index <= dy; index++)
		{
			// set the pixel
			Gui_DrawPoint(x0,y0,Color);

			// test if error overflowed
			if (error >= 0)
			{
				error-=dy2;

				// move to next line
				x0+=x_inc;
			} // end if error overflowed

			// adjust the error term
			error+=dx2;

			// move to the next pixel
			y0+=y_inc;
		} // end for
	} // end else |slope| > 1
}



void Gui_box(uint16_t x, uint16_t y, uint16_t w, uint16_t h,uint16_t bc)
{
	Gui_DrawLine(x,y,x+w,y,0xEF7D);
	Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0x2965);
	Gui_DrawLine(x,y+h,x+w,y+h,0x2965);
	Gui_DrawLine(x,y,x,y+h,0xEF7D);
  Gui_DrawLine(x+1,y+1,x+1+w-2,y+1+h-2,bc);
}
void Gui_box2(uint16_t x,uint16_t y,uint16_t w,uint16_t h, uint8_t mode)
{
	if (mode==0)	{
		Gui_DrawLine(x,y,x+w,y,0xEF7D);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0x2965);
		Gui_DrawLine(x,y+h,x+w,y+h,0x2965);
		Gui_DrawLine(x,y,x,y+h,0xEF7D);
		}
	if (mode==1)	{
		Gui_DrawLine(x,y,x+w,y,0x2965);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0xEF7D);
		Gui_DrawLine(x,y+h,x+w,y+h,0xEF7D);
		Gui_DrawLine(x,y,x,y+h,0x2965);
	}
	if (mode==2)	{
		Gui_DrawLine(x,y,x+w,y,0xffff);
		Gui_DrawLine(x+w-1,y+1,x+w-1,y+1+h,0xffff);
		Gui_DrawLine(x,y+h,x+w,y+h,0xffff);
		Gui_DrawLine(x,y,x,y+h,0xffff);
	}
}


/**************************************************************************************
��������: ����Ļ��ʾһ͹��İ�ť��
��    ��: u16 x1,y1,x2,y2 ��ť�����ϽǺ����½�����
��    ��: ��
**************************************************************************************/
void DisplayButtonDown(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	Gui_DrawLine(x1,  y1,  x2,y1, GRAY2);  	//H
	Gui_DrawLine(x1+1,y1+1,x2,y1+1, GRAY1); //H
	Gui_DrawLine(x1,  y1,  x1,y2, GRAY2);  	//V
	Gui_DrawLine(x1+1,y1+1,x1+1,y2, GRAY1); //V
	Gui_DrawLine(x1,  y2,  x2,y2, WHITE);  	//H
	Gui_DrawLine(x2,  y1,  x2,y2, WHITE);  	//V
}

/**************************************************************************************
��������: ����Ļ��ʾһ���µİ�ť��
��    ��: u16 x1,y1,x2,y2 ��ť�����ϽǺ����½�����
��    ��: ��
**************************************************************************************/
void DisplayButtonUp(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2)
{
	Gui_DrawLine(x1,  y1,  x2,y1, WHITE); 	//H
	Gui_DrawLine(x1,  y1,  x1,y2, WHITE); 	//V
	Gui_DrawLine(x1+1,y2-1,x2,y2-1, GRAY1); //H
	Gui_DrawLine(x1,  y2,  x2,y2, GRAY2);  	//H
	Gui_DrawLine(x2-1,y1+1,x2-1,y2, GRAY1); //V
  Gui_DrawLine(x2  ,y1  ,x2,y2, GRAY2); 	//V
}


void Gui_DrawFont_GBK16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s)
{
	uint8_t i,j;
	uint16_t k,x0;
	x0=x;

	while(*s) 
	{	
		if((*s) < 128) 
		{
			k=*s;
			if (k==13) 
			{
				x=x0;
				y+=16;
			}
			else 
			{
				if (k>32) k-=32; else k=0;
	
			    for(i=0;i<16;i++)
				for(j=0;j<8;j++) 
					{
				    	if(asc16[k*16+i]&(0x80>>j))	Gui_DrawPoint(x+j,y+i,fc);
						else 
						{
							if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
						}
					}
				x+=8;
			}
			s++;
		}
			
		else 
		{
		

			for (k=0;k<hz16_num;k++) 
			{
			  if ((hz16[k].Index[0]==*(s))&&(hz16[k].Index[1]==*(s+1)))
			  { 
				    for(i=0;i<16;i++)
				    {
						for(j=0;j<8;j++) 
							{
						    	if(hz16[k].Msk[i*2]&(0x80>>j))	Gui_DrawPoint(x+j,y+i,fc);
								else {
									if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
								}
							}
						for(j=0;j<8;j++) 
							{
						    	if(hz16[k].Msk[i*2+1]&(0x80>>j))	Gui_DrawPoint(x+j+8,y+i,fc);
								else 
								{
									if (fc!=bc) Gui_DrawPoint(x+j+8,y+i,bc);
								}
							}
				    }
				}
			  }
			s+=2;x+=16;
		} 
		
	}
}

void Gui_DrawFont_GBK24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s)
{
	uint8_t i,j;
	uint16_t k;

	while(*s) 
	{
		if( *s < 0x80 ) 
		{
			k=*s;
			if (k>32) k-=32; else k=0;

		    for(i=0;i<16;i++)
			for(j=0;j<8;j++) 
				{
			    	if(asc16[k*16+i]&(0x80>>j))	
					Gui_DrawPoint(x+j,y+i,fc);
					else 
					{
						if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
					}
				}
			s++;x+=8;
		}
		else 
		{

			for (k=0;k<hz24_num;k++) 
			{
			  if ((hz24[k].Index[0]==*(s))&&(hz24[k].Index[1]==*(s+1)))
			  { 
				    for(i=0;i<24;i++)
				    {
						for(j=0;j<8;j++) 
							{
						    	if(hz24[k].Msk[i*3]&(0x80>>j))
								Gui_DrawPoint(x+j,y+i,fc);
								else 
								{
									if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
								}
							}
						for(j=0;j<8;j++) 
							{
						    	if(hz24[k].Msk[i*3+1]&(0x80>>j))	Gui_DrawPoint(x+j+8,y+i,fc);
								else {
									if (fc!=bc) Gui_DrawPoint(x+j+8,y+i,bc);
								}
							}
						for(j=0;j<8;j++) 
							{
						    	if(hz24[k].Msk[i*3+2]&(0x80>>j))	
								Gui_DrawPoint(x+j+16,y+i,fc);
								else 
								{
									if (fc!=bc) Gui_DrawPoint(x+j+16,y+i,bc);
								}
							}
				    }
			  }
			}
			s+=2;x+=24;
		}
	}
}
void Gui_DrawFont_Num32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint16_t num)
{
	uint8_t i,j,k,c;
	//lcd_text_any(x+94+i*42,y+34,32,32,0x7E8,0x0,sz32,knum[i]);
	//	w=w/8;

    for(i=0;i<32;i++)
	{
		for(j=0;j<4;j++) 
		{
			c=*(sz32+num*32*4+i*4+j);
			for (k=0;k<8;k++)	
			{
	
		    	if(c&(0x80>>k))	Gui_DrawPoint(x+j*8+k,y+i,fc);
				else {
					if (fc!=bc) Gui_DrawPoint(x+j*8+k,y+i,bc);
				}
			}
		}
	}
}

void LCD_OUTPUT_Float(uint16_t LineX, uint16_t LineY, char *string,float32_t string_to_display)
{
  uint8_t tmp[64];
  sprintf((char*)tmp, "%s:%f",string, string_to_display);
	Gui_DrawFont_GBK16(LineX, LineY, BLACK, WHITE, tmp);
}

void LCD_OUTPUT_Wave(void)
{
//		User_AdcStartBlokingMode(Adc_table,2048);
		for(uint16_t counter = 0;counter < 2048;counter ++)
		{
			//printf("%f\r\n",(109*(3.3*Adc_table[counter]/4095)-100));
			if(counter<2040)
			{
			if(counter%12==0)
			{
				int temp;
				temp=counter/6;
				Gui_DrawLine(LastX_Wave,LastY_Wave,temp,(int)(80*(3.3*Adc_table[counter]/4095)+70) ,RED);
				LastX_Wave=temp;
				LastY_Wave=(80*(3.3*Adc_table[counter]/4095)+70);
				HAL_Delay(10);
			}
			}
			else
			{
				//HAL_Delay(1000);
				LastX_Wave=0;
				LastY_Wave=70;
				Lcd_Clear(WHITE);
				
			}
		}
}
void LCD_OUTPUT_FFT(void)
{
	
//	User_FastRfft2048BlokingMode(FFT_table);
	//User_AdcStartBlokingMode(Adc_table,2048);
	for(uint16_t counter = 1;counter < 1024;counter ++)
	{
			if(counter<1020)
			{
			if(counter%4==0)
			{
				int temp;
				temp=20+(counter/4);
				Gui_DrawLine(LastX_FFT,LastY_FFT,temp,200-((int)((FFT_table[counter])/2)) ,BLACK);
				LastX_FFT=temp;
				LastY_FFT=200-((FFT_table[counter])/35);
				HAL_Delay(10);
			}
			}
			else
			{
				HAL_Delay(1000);
				LastX_FFT=20;
				LastY_FFT=200;
				Lcd_Clear(WHITE);
				
			}
	}
}

