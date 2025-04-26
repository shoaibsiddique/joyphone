#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <avr/io.h>
#include <avr/interrupt.h> 

#include "initializeIOs.h"
#include "serialRoutine.h"
#include "myRtc.h"

bool enableRinging_theBell_R1 = false;
bool enableRinging_theBell_R2 = false;
bool enableRinging_theBell_R3 = false;
bool enableRinging_theBell_R4 = false;


bool reminder1_alarmed = false;
bool reminder2_alarmed = false;
bool reminder3_alarmed = false;
bool reminder4_alarmed = false;
bool reminder_alarmed = false;



char Day_reminder1[7];
char Day_reminder2[7];
char Day_reminder3[7];
char Day_reminder4[7];

char Day_reminder1_eeprom[7];
char Day_reminder2_eeprom[7];
char Day_reminder3_eeprom[7];
char Day_reminder4_eeprom[7];

char Hour_reminder1;
char Hour_reminder2;
char Hour_reminder3;
char Hour_reminder4;

char Hour_reminder1_eeprom;
char Hour_reminder2_eeprom;
char Hour_reminder3_eeprom;
char Hour_reminder4_eeprom;

char Min_reminder1;
char Min_reminder2;
char Min_reminder3;
char Min_reminder4;

char Min_reminder1_eeprom;
char Min_reminder2_eeprom;
char Min_reminder3_eeprom;
char Min_reminder4_eeprom;

char VolumeSetValue;
char VolumeCommandValue;

bool dialTonePlayed = false;


void setup() {
  // put your setup code here, to run once:
  initializeIOpins();
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  

	Wire.begin();
	fetch_EEPROM();
	
	setDiallerSpeaker_IOs();
	ringBell_setup();
	//Serial.println("I am Rady");
	
	

}

void loop() {
  get_1sec_RTC();
  dialler_ringer_loop();

  enableRinging_Bell();
	
if(enableRinging_theBell_R1 == true || enableRinging_theBell_R2 == true || enableRinging_theBell_R3 == true || enableRinging_theBell_R4 == true){
	enableBell();
}else{
	disableBell();
}
bellRing_loop();
clearAlarmed_flags();
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  if(Serial.available()){
      Rx_buffer_tmp[rx_ctr] = Serial.read();
      if(Rx_buffer_tmp[0]==0x2A){     
        if(rx_ctr>=2){ // Check if 3 bytes of command packet is received.
          for(int count=0; count<=2; count++){
            Rx_buffer[count] = Rx_buffer_tmp[count];
          }
          memset(Rx_buffer_tmp, 0x00, 13);
          RX_Flag = 0xFF;
          rx_ctr=255;
        }
        rx_ctr++; 
      }else
      if(Rx_buffer_tmp[0] == 0x5A){
        if(Rx_buffer_tmp[2] == 0x8F){
          if(rx_ctr>=12){ // Check if 13 bytes of RTC setting packet is received.
          for(int count1=0; count1<=12; count1++){
            Rx_buffer[count1] = Rx_buffer_tmp[count1];
            
          }
          memset(Rx_buffer_tmp, 0x00, 13);
          RX_Flag = 0xAF;
          rx_ctr=255;
          }
        }
        rx_ctr++; 
      }else
		  if(Rx_buffer_tmp[0] == 0x6B){ // receiving the alarm save eeprom packet
			
			
			  if(Rx_buffer_tmp[6] == 0xFD){
				  
				  if(rx_ctr>=6){ // Check if 7 bytes of RTC setting packet is received.
							reminder_Set_reply = true;
					      for(int count2=0; count2<=6; count2++){
							Rx_buffer[count2] = Rx_buffer_tmp[count2];
							mySoftwareSerial.write(Rx_buffer[count2]);
							
						  }
						  memset(Rx_buffer_tmp, 0x00, 7);
						  rx_ctr=255;
				  }
			  }	
			  rx_ctr++; 
		  }else
			  
		        if(Rx_buffer_tmp[0]==0x1A){  digitalWrite(13, 1);   
        if(rx_ctr>=2){ // Check if 3 bytes of command packet is received.
          for(int count=0; count<=2; count++){
            Rx_buffer[count] = Rx_buffer_tmp[count];
          }
          memset(Rx_buffer_tmp, 0x00, 13);
          RX_Flag = 0x1A;
          rx_ctr=255;
        }
        rx_ctr++; 
      }
	  
		  
		  
		  
		  
      else{
          memset(Rx_buffer_tmp, 0x00, 13);
          //rx_ctr = 0;
      }
   }

     if(RX_Flag == 0xFF){
      RX_Flag = 0x00;
      //rx_ctr = 0;
      replyFlag = false;
     }else
     
     if(RX_Flag == 0xAF){
      //rx_ctr = 0;
      RX_Flag = 0x00;
      replyFlag = false;
     }else
		 
	 /*if(RX_Flag == 0x9A){
		RX_Flag = 0x00; 
		VolumeCommandValue = Rx_buffer[1];
		 setVolume();
	 }*/
	/*
	 if(RX_Flag == 0x1A){
		 RX_Flag = 0x00;
		 setReminder1();
	 }else
	 if(RX_Flag == 0x2A){
		 RX_Flag = 0x00;
		 setReminder2();
	 }else
	 if(RX_Flag == 0x3A){
		 RX_Flag = 0x00;
		 setReminder3();
	 }else
	 if(RX_Flag == 0x4A){
		 RX_Flag = 0x00;
		 setReminder4();
	 }
	 */
	 

      if(Rx_buffer[0] == 0x2A && Rx_buffer[1] == 0x01 && Rx_buffer[2] == 0xEF){
      getRTCvalues();
      checksum = yearLowByte + month_ + date_ + dOW_ + hour_ + second_; 
      if(replyFlag == false){
        delay(10); 
        Serial.write(sop1);
        Serial.write(sop2);
        Serial.write(sop3);
        Serial.write(date_);
        Serial.write(month_);
        Serial.write(yearLowByte);
        Serial.write(yearHighByte);
        Serial.write(hour_);
        Serial.write(minute_);
        Serial.write(second_);
        Serial.write(dOW_);
        Serial.write(checksum);
        Serial.write(eop1);
        Serial.write(eop2);
        replyFlag = true;
      }
     }else
    if(Rx_buffer[0] == 0x5A && Rx_buffer[1] == 0x6D && Rx_buffer[2] == 0x8F){
      if(Rx_buffer[11] == 0xAA && Rx_buffer[12] == 0xE6){

      set_date = Rx_buffer[3];
      set_month = Rx_buffer[4];
      set_hour = Rx_buffer[6];
      set_minute = Rx_buffer[7];
      set_secs = Rx_buffer[8];
      set_doW = Rx_buffer[9];
      delay(10);
      setRTCvalues();
      delay(10);

      
      if(replyFlag == false){
        Serial.write(0x5A);
        Serial.write(0x3C);
        Serial.write(0xE5);
        //debug_recvd_setRTC_Values();
        replyFlag = true;
      }
     }
    }else
		if(Rx_buffer[0] == 0x6B && Rx_buffer[1] == 0x1A && Rx_buffer[5] == 0xEE && Rx_buffer[6] == 0xFD){
			
			for(int i=7; i>=0; i--){
				Day_reminder1[i] = (Rx_buffer[2] >> i) & 0x01;
			}
			Hour_reminder1 = Rx_buffer[3];
			Min_reminder1 = Rx_buffer[4];

			if(reminder_Set_reply ==true){
			setReminder1_EEPROM();
			Serial.write(0x7F);
			Serial.write(0x1B);
			Serial.write(0xDC);
			reminder_Set_reply = false;
			}
		}else
		if(Rx_buffer[0] == 0x6B && Rx_buffer[1] == 0x2A && Rx_buffer[5] == 0xEE && Rx_buffer[6] == 0xFD){
			
			for(int i=7; i>=0; i--){
				Day_reminder2[i] = (Rx_buffer[2] >> i) & 0x01;
			}
			Hour_reminder2 = Rx_buffer[3];
			Min_reminder2 = Rx_buffer[4];

			if(reminder_Set_reply ==true){
			setReminder2_EEPROM();
			Serial.write(0x7F);
			Serial.write(0x2B);
			Serial.write(0xDC);
			reminder_Set_reply = false;
			}	
			
		}else
		if(Rx_buffer[0] == 0x6B && Rx_buffer[1] == 0x3A && Rx_buffer[5] == 0xEE && Rx_buffer[6] == 0xFD){
			
			for(int i=7; i>=0; i--){
				Day_reminder3[i] = (Rx_buffer[2] >> i) & 0x01;
			}
			Hour_reminder3 = Rx_buffer[3];
			Min_reminder3 = Rx_buffer[4];

			if(reminder_Set_reply ==true){
			setReminder3_EEPROM();
			Serial.write(0x7F);
			Serial.write(0x3B);
			Serial.write(0xDC);
			reminder_Set_reply = false;
			}
			
		}else
		if(Rx_buffer[0] == 0x6B && Rx_buffer[1] == 0x4A && Rx_buffer[5] == 0xEE && Rx_buffer[6] == 0xFD){
			
			for(int i=7; i>=0; i--){
				Day_reminder4[i] = (Rx_buffer[2] >> i) & 0x01;
			}
			Hour_reminder4 = Rx_buffer[3];
			Min_reminder4 = Rx_buffer[4];

			if(reminder_Set_reply ==true){
			setReminder4_EEPROM();
			Serial.write(0x7F);
			Serial.write(0x4B);
			Serial.write(0xDC);
			reminder_Set_reply = false;
			}
		}
		
		
		if(Rx_buffer[0] == 0x1A && Rx_buffer[2] == 0xEF && RX_Flag == 0x1A){
		 RX_Flag = 0x00;
		VolumeCommandValue = Rx_buffer[1];
		 setVolume();
			
		}


    
  }//end of Loop
