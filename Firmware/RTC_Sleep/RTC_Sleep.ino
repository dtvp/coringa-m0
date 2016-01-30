/*
  RTC com sleep e callback

  Baseado em:
  http://arduino.cc/en/Tutorial/SimpleRTC

*/

#include <RTCZero.h>

/* Create an rtc object */
RTCZero rtc;

/* Change these values to set the current initial time */
const byte seconds = 0;
const byte minutes = 0;
const byte hours = 10;

/* Change these values to set the current initial date */
const byte day = 30;
const byte month = 1;
const byte year = 16;

const int epochNow = 1454158858;
// See www.epochconverter.com

void setup()
{
  pinMode(13, OUTPUT);
  SerialUSB.begin(115200);
  
  rtc.begin(); // initialize RTC
  
  // Set the time
  rtc.setHours(hours);
  rtc.setMinutes(minutes);
  rtc.setSeconds(seconds);
  //rtc.setTime(hours, minutes, seconds);
  
  // Set the date
  rtc.setDay(day);
  rtc.setMonth(month);
  rtc.setYear(year);
  //rtc.setDate(day, month, year);

  rtc.setEpoch(epochNow);

  rtc.setAlarmTime(10, 00, 10);
  rtc.enableAlarm(rtc.MATCH_SS);  //Acorda a cada minuto no segundo 10

  rtc.attachInterrupt(alarmMatch);

  while( !SerialUSB );
  SerialUSB.println("Sweet dreams...");
  rtc.standbyMode();
}

void loop()
{
  SerialUSB.println("Sweet dreams...");
  rtc.standbyMode();
}

void alarmMatch()
{
  digitalWrite(13, HIGH);
  SerialUSB.println("Awake!");

  // Print date...
  SerialUSB.print(rtc.getDay());
  SerialUSB.print("/");
  SerialUSB.print(rtc.getMonth());
  SerialUSB.print("/");
  SerialUSB.print(rtc.getYear());
  SerialUSB.print("\t");
  
  // ...and time
  SerialUSB.print(rtc.getHours());
  SerialUSB.print(":");
  SerialUSB.print(rtc.getMinutes());
  SerialUSB.print(":");
  SerialUSB.print(rtc.getSeconds());
 
  SerialUSB.println();
  digitalWrite(13, LOW);
}
