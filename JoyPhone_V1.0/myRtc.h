#include <Wire.h>
#include <DS3231.h>

//RTC Varialbes Declaration:
unsigned char sop1 = 0x7A;
unsigned char sop2 = 0xE1;
unsigned char sop3 = 0x6B;
short year_ = 0x00;
unsigned char yearHighByte;
unsigned char yearLowByte;
unsigned char month_ = 0x00;
unsigned char date_ = 0x00;
unsigned char dOW_ = 0x00;
unsigned char hour_ = 0x00;
unsigned char minute_ =0x00;
unsigned char second_ =0x00;
unsigned char checksum = 0x00;
unsigned char eop1 = 0xEA;
unsigned char eop2 = 0xF6;

int set_year = 0;
int set_month = 0;
int set_date = 0;
int set_hour = 0;
int set_minute =0;
int set_secs = 0;
int set_doW = 0;


DS3231 Clock;
RTClib myRTC;



void displayRTC(){
    delay(1000);
    DateTime now = myRTC.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
}

void getRTCvalues(){
  DateTime now = myRTC.now();
  year_ = now.year();
  yearLowByte = year_;
  yearHighByte = year_ >> 8;
  month_ = now.month();
  date_ = now.day();
  hour_ = now.hour();
  minute_ = now.minute();
  second_ = now.second();
  dOW_ = Clock.getDoW();

}

void setRTCvalues(){
  
  // Start the I2C interface
  //Wire.begin();
  delay(200);
  Clock.setClockMode(false); // set to 24hour mode
  Clock.setSecond(set_secs);//Set the second
  Clock.setMinute(set_minute);//Set the minute
  Clock.setHour(set_hour); //Set the hour
  Clock.setDoW(set_doW); //Set the day of the week
  Clock.setDate(set_date); //Set the date of the month
  Clock.setMonth(set_month); //Set the month of the year
  Clock.setYear(22); //Set the year (Last two digits of the year)
}




void debug_recvd_setRTC_Values(){
      Serial.print("Date is:");
      Serial.println(set_date);
      
      Serial.print("Month is:");
      Serial.println(set_month);
      
      Serial.print("Hour is:");
      Serial.println(set_hour);
      
      Serial.print("Minute is:");
      Serial.println(set_minute);
      
      Serial.print("Secs is:");
      Serial.println(set_secs);
      
      Serial.print("DoW is:");
      Serial.println(set_doW);
}
