#include "StdTypes.h"
#include "DIO_Interface.h"
#include "MemyMap.h"
#include "Utils.h"
#include "Button_Interface.h"
#include "Segment_Interface.h"
#include "Stop_Watch.h"
#define  F_CPU 8000000
#include <util/delay.h>

unsigned char time1 = 0;
unsigned char time2 = 0;
unsigned char TIE = 0;
unsigned char flag = 0;


void MAIN_PROJECT_STOPWATCH(){
	TIE = time2*10 + time1;
	while(1){
		SEG_Display(TIE);
		DIO_WritePin(Buzzer,LOW);
		if (!Button_IsPressed(Button_DOWN)){
			while(!Button_IsPressed(Button_DOWN));
			flag = 1;
			Set_Down();
		}else if (!Button_IsPressed(Button_UP)){
			while(!Button_IsPressed(Button_UP));
			flag = 1;
			Set_Up();
		}else if (!Button_IsPressed(Button_MODE)){
			while(!Button_IsPressed(Button_MODE));
			Active_MODE();
		}
	}
}
void  Active_MODE(void){
	if (flag == 1)
	{
		while(1){
			for(u8 i = 0 ; i < 100 ; i++){
				SEG_Display(TIE);
				if (!Button_IsPressed(Button_MODE)){
					SEG_Display(0);
					break;
				}
			}
			TIE --;
			if(TIE == 0) break;
		}
		TIE = 0 ;
		time1 = 0;
		time2 = 0;
		DIO_WritePin(PINB3,HIGH);
		flag = 0;
		_delay_ms(800);
	}
}
void  Set_Up(void){
	while(!Button_IsPressed(Button_UP)){}
	if(time1 == 9){
		time1 = 0;
	}else{
		time1 = time1 + 1;
	}
	TIE = time2 * 10 + time1;
	SEG_Display(TIE);
}
void  Set_Down(void){
	while(!Button_IsPressed(Button_DOWN)){}
	if(time2 == 9){
		time2 = 0;
	}else{
		time2 = time2+1;
	}
	TIE = time2 *10 + time1;
	SEG_Display(TIE);
}


