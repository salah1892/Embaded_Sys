#include <Arduino.h>
#include "configBIN.h"

hw_timer_t *My_timer = NULL;
hw_timer_t *My_timer2 = NULL;

void IRAM_ATTR onTimer1(){
digitalWrite(LED1, !digitalRead(LED1));
}
void IRAM_ATTR onTimer2(){
digitalWrite(LED2, !digitalRead(LED2));
}
void setup()
{
  pinMode(BUTTON_1, INPUT_PULLDOWN);
  pinMode(BUTTON_2, INPUT_PULLDOWN);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);

My_timer = timerBegin(0, 80, true);  
timerAttachInterrupt(My_timer, &onTimer1, true);
timerAlarmWrite(My_timer, 1000000, true);
timerAlarmEnable(My_timer); //Just Enable

My_timer2 = timerBegin(1, 80, true);
timerAttachInterrupt(My_timer2, &onTimer2, true);
timerAlarmWrite(My_timer2, 1000000, true);
timerAlarmEnable(My_timer2); //Just Enable
}

void loop()
{
  
}

