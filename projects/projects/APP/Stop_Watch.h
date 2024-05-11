#ifndef STOP_WATCH_H_
#define STOP_WATCH_H_

#define START_Time 30
#define Buzzer PINB3

#define Button_UP     PINB0
#define Button_DOWN   PINB1
#define Button_MODE   PINB2


//CALL FUNCTION MAIN_PRO 
void MAIN_PROJECT_STOPWATCH();
void  Active_MODE(void);
void  Set_Up(void);
void  Set_Down(void);

#endif /* STOP_WITCH_H_ */