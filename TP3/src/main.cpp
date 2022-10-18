#include <Arduino.h>
//#include<Timer.h>
#include "configBIN.h"

// hw_timer_t *My_timer = NULL;
// hw_timer_t *My_timer2 = NULL;
hw_timer_t *Timer_Led_Clignote = NULL;

volatile int count = MAX_LOW_LED;
volatile int count_Second = 5;
volatile int count_Half_Second = 3;
volatile int CONT_BTN_PRESSED = 0;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
//---------------------------------------------------//
// void IRAM_ATTR onTimer1()
// {
//   digitalWrite(LED1, !digitalRead(LED1));
//   // delay(1000);
//   // digitalWrite(LED1, LOW);
// }
// void IRAM_ATTR onTimer2()
// {
//   count--;
//   if (count == 0)
//   {
//     digitalWrite(LED2, ON);
//     count = MAX_LOW_LED;
//   }
//   else
//   {
//     digitalWrite(LED2, OFF);
//   }
// }
//-------------------------------------------------------------------//
void clignote_1s()
{
  count_Second--;
  if (count_Second == 0)
  {
    digitalWrite(LED1, ON);
    count_Second = 3;
  }
  else
  {
    digitalWrite(LED1, OFF);
  }
}
//-----------------------------------//
void clignote_Half_sec()
{
  count_Half_Second--;
  if (count_Half_Second == 0)
  {
    digitalWrite(LED1, ON);
    count_Half_Second = 2;
  }
  else
  {
    digitalWrite(LED1, OFF);
  }
}
//-----------------------------------//
void IRAM_ATTR onTimer3()
{
  if (digitalRead(BUTTON_1) == ON)
  {
    CONT_BTN_PRESSED++;
    if (CONT_BTN_PRESSED == 4)
      CONT_BTN_PRESSED = 1;
  }
  switch (CONT_BTN_PRESSED)
  {

  case 1:
    clignote_1s();
    break;
  case 2:
    clignote_Half_sec();
    break;
  case 3:
    digitalWrite(LED1, OFF);
    digitalWrite(LED2, OFF);
    CONT_BTN_PRESSED = 0;
    break;
  default:
    digitalWrite(LED1, OFF);
    digitalWrite(LED2, OFF);
  }
}

//---------------------------------------------------//
void setup()
{
  pinMode(BUTTON_1, INPUT_PULLDOWN);
  pinMode(BUTTON_2, INPUT_PULLDOWN);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  Serial.begin(115200);
  // My_timer = timerBegin(0, 80, true);
  // timerAttachInterrupt(My_timer, &onTimer1, true);
  // timerAlarmWrite(My_timer, SECOND, true);
  // timerAlarmEnable(My_timer); // Just Enable Timer

  // My_timer2 = timerBegin(1, 80, true);
  // timerAttachInterrupt(My_timer2, &onTimer2, true);
  // timerAlarmWrite(My_timer2, HALF_SECOND, true);
  // timerAlarmEnable(My_timer2); // Just Enable Timer
  //--------------------------------------------------------//
  Timer_Led_Clignote = timerBegin(0, 80, true);
  timerAttachInterrupt(Timer_Led_Clignote, &onTimer3, true);
  timerAlarmWrite(Timer_Led_Clignote, QUARD_SECOND, true);
  timerAlarmEnable(Timer_Led_Clignote); // Just Enable Timer

  Serial.println("Hello Salah Eddinne Elbakkerri");
  
}

void loop()
{
  Serial.println(CONT_BTN_PRESSED);
  delay(500);
}