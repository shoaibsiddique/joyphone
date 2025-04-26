#include <EEPROM.h>

#define Reminder1_day1 11 //Reminder 1 - Monday
#define Reminder1_day2 12 //Reminder 1 - Tuesday
#define Reminder1_day3 13 //Reminder 1 - Wednesday
#define Reminder1_day4 14 //Reminder 1 - Thursday
#define Reminder1_day5 15 //Reminder 1 - Friday
#define Reminder1_day6 16 //Reminder 1 - Saturday
#define Reminder1_day7 17 //Reminder 1 - Sunday

#define Reminder1_Hour 18 // Reminder 1 - Hour of Alarm
#define Reminder1_Min 19 // Reminder 1 - Mins of Alarm



#define Reminder2_day1 21 //Reminder 2 - Monday
#define Reminder2_day2 22 //Reminder 2 - Tuesday
#define Reminder2_day3 23 //Reminder 2 - Wednesday
#define Reminder2_day4 24 //Reminder 2 - Thursday
#define Reminder2_day5 25 //Reminder 2 - Friday
#define Reminder2_day6 26 //Reminder 2 - Saturday
#define Reminder2_day7 27 //Reminder 2 - Sunday

#define Reminder2_Hour 28 // Reminder 2 - Hour of Alarm
#define Reminder2_Min 29 // Reminder 2 - Mins of Alarm



#define Reminder3_day1 31 //Reminder 3 - Monday
#define Reminder3_day2 32 //Reminder 3 - Tuesday
#define Reminder3_day3 33 //Reminder 3 - Wednesday
#define Reminder3_day4 34 //Reminder 3 - Thursday
#define Reminder3_day5 35 //Reminder 3 - Friday
#define Reminder3_day6 36 //Reminder 3 - Saturday
#define Reminder3_day7 37 //Reminder 3 - Sunday

#define Reminder3_Hour 38 // Reminder 3 - Hour of Alarm
#define Reminder3_Min 39 // Reminder 3 - Mins of Alarm



#define Reminder4_day1 41 //Reminder 4 - Monday
#define Reminder4_day2 42 //Reminder 4 - Tuesday
#define Reminder4_day3 43 //Reminder 4 - Wednesday
#define Reminder4_day4 44 //Reminder 4 - Thursday
#define Reminder4_day5 45 //Reminder 4 - Friday
#define Reminder4_day6 46 //Reminder 4 - Saturday
#define Reminder4_day7 47 //Reminder 4 - Sunday

#define Reminder4_Hour 48 // Reminder 4 - Hour of Alarm
#define Reminder4_Min 49 // Reminder 4 - Mins of Alarm

#define Volume_Address 2


void setReminder1_EEPROM(){
	if(Day_reminder1[6] == 1){
		EEPROM.write(Reminder1_day1, 1);
	}else
	{
		EEPROM.write(Reminder1_day1, 0);
	}
	
	if(Day_reminder1[5] == 1){
		EEPROM.write(Reminder1_day2, 2);
	}else
	{
		EEPROM.write(Reminder1_day2, 0);
	}
	
	if(Day_reminder1[4] == 1){
		EEPROM.write(Reminder1_day3, 3);
	}else
	{
		EEPROM.write(Reminder1_day3, 0);
	}
	
	if(Day_reminder1[3] == 1){
		EEPROM.write(Reminder1_day4, 4);
	}else
	{
		EEPROM.write(Reminder1_day4, 0);
	}

	if(Day_reminder1[2] == 1){
		EEPROM.write(Reminder1_day5, 5);
	}else
	{
		EEPROM.write(Reminder1_day5, 0);
	}
	
	if(Day_reminder1[1] == 1){
		EEPROM.write(Reminder1_day6, 6);
	}else
	{
		EEPROM.write(Reminder1_day6, 0);
	}
	
	if(Day_reminder1[0] == 1){
		EEPROM.write(Reminder1_day7, 7);
	}else
	{
		EEPROM.write(Reminder1_day7, 0);
	}
	
	EEPROM.write(Reminder1_Hour, Hour_reminder1);
	EEPROM.write(Reminder1_Min, Min_reminder1);
	/*
	
	if(reminder_Set_reply ==true){
			mySoftwareSerial.write(EEPROM.read(Reminder1_day7));
			mySoftwareSerial.write(EEPROM.read(Reminder1_day6));
			mySoftwareSerial.write(EEPROM.read(Reminder1_day5));
			mySoftwareSerial.write(EEPROM.read(Reminder1_day4));
			mySoftwareSerial.write(EEPROM.read(Reminder1_day3));
			mySoftwareSerial.write(EEPROM.read(Reminder1_day2));
			mySoftwareSerial.write(EEPROM.read(Reminder1_day1));
			
			mySoftwareSerial.write(EEPROM.read(Reminder1_Hour));
			mySoftwareSerial.write(EEPROM.read(Reminder1_Min));
			
}*/
}



void setReminder2_EEPROM(){
	if(Day_reminder2[6] == 1){
		EEPROM.write(Reminder2_day1, 1);
	}else
	{
		EEPROM.write(Reminder2_day1, 0);
	}
	
	if(Day_reminder2[5] == 1){
		EEPROM.write(Reminder2_day2, 2);
	}else
	{
		EEPROM.write(Reminder2_day2, 0);
	}
	
	if(Day_reminder2[4] == 1){
		EEPROM.write(Reminder2_day3, 3);
	}else
	{
		EEPROM.write(Reminder2_day3, 0);
	}
	
	if(Day_reminder2[3] == 1){
		EEPROM.write(Reminder2_day4, 4);
	}else
	{
		EEPROM.write(Reminder2_day4, 0);
	}

	if(Day_reminder2[2] == 1){
		EEPROM.write(Reminder2_day5, 5);
	}else
	{
		EEPROM.write(Reminder2_day5, 0);
	}
	
	if(Day_reminder2[1] == 1){
		EEPROM.write(Reminder2_day6, 6);
	}else
	{
		EEPROM.write(Reminder2_day6, 0);
	}
	
	if(Day_reminder2[0] == 1){
		EEPROM.write(Reminder2_day7, 7);
	}else
	{
		EEPROM.write(Reminder2_day7, 0);
	}
	
	EEPROM.write(Reminder2_Hour, Hour_reminder2);
	EEPROM.write(Reminder2_Min, Min_reminder2);
	
	/*
	if(reminder_Set_reply ==true){
			mySoftwareSerial.write(EEPROM.read(Reminder2_day7));
			mySoftwareSerial.write(EEPROM.read(Reminder2_day6));
			mySoftwareSerial.write(EEPROM.read(Reminder2_day5));
			mySoftwareSerial.write(EEPROM.read(Reminder2_day4));
			mySoftwareSerial.write(EEPROM.read(Reminder2_day3));
			mySoftwareSerial.write(EEPROM.read(Reminder2_day2));
			mySoftwareSerial.write(EEPROM.read(Reminder2_day1));
			
			mySoftwareSerial.write(EEPROM.read(Reminder2_Hour));
			mySoftwareSerial.write(EEPROM.read(Reminder2_Min));
			
}*/
}




void setReminder3_EEPROM(){
	if(Day_reminder3[6] == 1){
		EEPROM.write(Reminder3_day1, 1);
	}else
	{
		EEPROM.write(Reminder3_day1, 0);
	}
	
	if(Day_reminder3[5] == 1){
		EEPROM.write(Reminder3_day2, 2);
	}else
	{
		EEPROM.write(Reminder3_day2, 0);
	}
	
	if(Day_reminder3[4] == 1){
		EEPROM.write(Reminder3_day3, 3);
	}else
	{
		EEPROM.write(Reminder3_day3, 0);
	}
	
	if(Day_reminder3[3] == 1){
		EEPROM.write(Reminder3_day4, 4);
	}else
	{
		EEPROM.write(Reminder3_day4, 0);
	}

	if(Day_reminder3[2] == 1){
		EEPROM.write(Reminder3_day5, 5);
	}else
	{
		EEPROM.write(Reminder3_day5, 0);
	}
	
	if(Day_reminder3[1] == 1){
		EEPROM.write(Reminder3_day6, 6);
	}else
	{
		EEPROM.write(Reminder3_day6, 0);
	}
	
	if(Day_reminder3[0] == 1){
		EEPROM.write(Reminder3_day7, 7);
	}else
	{
		EEPROM.write(Reminder3_day7, 0);
	}
	
	EEPROM.write(Reminder3_Hour, Hour_reminder3);
	EEPROM.write(Reminder3_Min, Min_reminder3);
	/*
	
	if(reminder_Set_reply ==true){
			mySoftwareSerial.write(EEPROM.read(Reminder3_day7));
			mySoftwareSerial.write(EEPROM.read(Reminder3_day6));
			mySoftwareSerial.write(EEPROM.read(Reminder3_day5));
			mySoftwareSerial.write(EEPROM.read(Reminder3_day4));
			mySoftwareSerial.write(EEPROM.read(Reminder3_day3));
			mySoftwareSerial.write(EEPROM.read(Reminder3_day2));
			mySoftwareSerial.write(EEPROM.read(Reminder3_day1));
			
			mySoftwareSerial.write(EEPROM.read(Reminder3_Hour));
			mySoftwareSerial.write(EEPROM.read(Reminder3_Min));
			
}*/
}




void setReminder4_EEPROM(){
	if(Day_reminder4[6] == 1){
		EEPROM.write(Reminder4_day1, 1);
	}else
	{
		EEPROM.write(Reminder4_day1, 0);
	}
	
	if(Day_reminder4[5] == 1){
		EEPROM.write(Reminder4_day2, 2);
	}else
	{
		EEPROM.write(Reminder4_day2, 0);
	}
	
	if(Day_reminder4[4] == 1){
		EEPROM.write(Reminder4_day3, 3);
	}else
	{
		EEPROM.write(Reminder4_day3, 0);
	}
	
	if(Day_reminder4[3] == 1){
		EEPROM.write(Reminder4_day4, 4);
	}else
	{
		EEPROM.write(Reminder4_day4, 0);
	}

	if(Day_reminder4[2] == 1){
		EEPROM.write(Reminder4_day5, 5);
	}else
	{
		EEPROM.write(Reminder4_day5, 0);
	}
	
	if(Day_reminder4[1] == 1){
		EEPROM.write(Reminder4_day6, 6);
	}else
	{
		EEPROM.write(Reminder4_day6, 0);
	}
	
	if(Day_reminder4[0] == 1){
		EEPROM.write(Reminder4_day7, 7);
	}else
	{
		EEPROM.write(Reminder4_day7, 0);
	}
	
	EEPROM.write(Reminder4_Hour, Hour_reminder4);
	EEPROM.write(Reminder4_Min, Min_reminder4);
	
	/*
	if(reminder_Set_reply ==true){
			mySoftwareSerial.write(EEPROM.read(Reminder4_day7));
			mySoftwareSerial.write(EEPROM.read(Reminder4_day6));
			mySoftwareSerial.write(EEPROM.read(Reminder4_day5));
			mySoftwareSerial.write(EEPROM.read(Reminder4_day4));
			mySoftwareSerial.write(EEPROM.read(Reminder4_day3));
			mySoftwareSerial.write(EEPROM.read(Reminder4_day2));
			mySoftwareSerial.write(EEPROM.read(Reminder4_day1));
			
			mySoftwareSerial.write(EEPROM.read(Reminder4_Hour));
			mySoftwareSerial.write(EEPROM.read(Reminder4_Min));
			
}*/
}



void fetch_EEPROM(){
	
	Day_reminder1_eeprom[0] = EEPROM.read(Reminder1_day7);
	Day_reminder1_eeprom[1] = EEPROM.read(Reminder1_day6);
	Day_reminder1_eeprom[2] = EEPROM.read(Reminder1_day5);
	Day_reminder1_eeprom[3] = EEPROM.read(Reminder1_day4);
	Day_reminder1_eeprom[4] = EEPROM.read(Reminder1_day3);
	Day_reminder1_eeprom[5] = EEPROM.read(Reminder1_day2);
	Day_reminder1_eeprom[6] = EEPROM.read(Reminder1_day1);
	Hour_reminder1_eeprom =   EEPROM.read(Reminder1_Hour);
	Min_reminder1_eeprom = EEPROM.read(Reminder1_Min);
	/*
	mySoftwareSerial.write(Day_reminder1_eeprom[0]);
	mySoftwareSerial.write(Day_reminder1_eeprom[1]);
	mySoftwareSerial.write(Day_reminder1_eeprom[2]);
	mySoftwareSerial.write(Day_reminder1_eeprom[3]);
	mySoftwareSerial.write(Day_reminder1_eeprom[4]);
	mySoftwareSerial.write(Day_reminder1_eeprom[5]);
	mySoftwareSerial.write(Day_reminder1_eeprom[6]);
	mySoftwareSerial.write(Day_reminder1_eeprom[7]);
	mySoftwareSerial.write(Hour_reminder1_eeprom);
	mySoftwareSerial.write(Min_reminder1_eeprom);
	mySoftwareSerial.write(0xAA);
	mySoftwareSerial.write(0xBB);
	*/

	Day_reminder2_eeprom[0] = EEPROM.read(Reminder2_day7);
	Day_reminder2_eeprom[1] = EEPROM.read(Reminder2_day6);
	Day_reminder2_eeprom[2] = EEPROM.read(Reminder2_day5);
	Day_reminder2_eeprom[3] = EEPROM.read(Reminder2_day4);
	Day_reminder2_eeprom[4] = EEPROM.read(Reminder2_day3);
	Day_reminder2_eeprom[5] = EEPROM.read(Reminder2_day2);
	Day_reminder2_eeprom[6] = EEPROM.read(Reminder2_day1);
	Hour_reminder2_eeprom =   EEPROM.read(Reminder2_Hour);
	Min_reminder2_eeprom = EEPROM.read(Reminder2_Min);	
	/*
	mySoftwareSerial.write(Day_reminder2_eeprom[0]);
	mySoftwareSerial.write(Day_reminder2_eeprom[1]);
	mySoftwareSerial.write(Day_reminder2_eeprom[2]);
	mySoftwareSerial.write(Day_reminder2_eeprom[3]);
	mySoftwareSerial.write(Day_reminder2_eeprom[4]);
	mySoftwareSerial.write(Day_reminder2_eeprom[5]);
	mySoftwareSerial.write(Day_reminder2_eeprom[6]);
	mySoftwareSerial.write(Day_reminder2_eeprom[7]);
	mySoftwareSerial.write(Hour_reminder2_eeprom);
	mySoftwareSerial.write(Min_reminder2_eeprom);
	mySoftwareSerial.write(0xCC);
	mySoftwareSerial.write(0xDD);
	*/
	
	
	Day_reminder3_eeprom[0] = EEPROM.read(Reminder3_day7);
	Day_reminder3_eeprom[1] = EEPROM.read(Reminder3_day6);
	Day_reminder3_eeprom[2] = EEPROM.read(Reminder3_day5);
	Day_reminder3_eeprom[3] = EEPROM.read(Reminder3_day4);
	Day_reminder3_eeprom[4] = EEPROM.read(Reminder3_day3);
	Day_reminder3_eeprom[5] = EEPROM.read(Reminder3_day2);
	Day_reminder3_eeprom[6] = EEPROM.read(Reminder3_day1);
	Hour_reminder3_eeprom =   EEPROM.read(Reminder3_Hour);
	Min_reminder3_eeprom = EEPROM.read(Reminder3_Min);
	/*
	mySoftwareSerial.write(Day_reminder3_eeprom[0]);
	mySoftwareSerial.write(Day_reminder3_eeprom[1]);
	mySoftwareSerial.write(Day_reminder3_eeprom[2]);
	mySoftwareSerial.write(Day_reminder3_eeprom[3]);
	mySoftwareSerial.write(Day_reminder3_eeprom[4]);
	mySoftwareSerial.write(Day_reminder3_eeprom[5]);
	mySoftwareSerial.write(Day_reminder3_eeprom[6]);
	mySoftwareSerial.write(Day_reminder3_eeprom[7]);
	mySoftwareSerial.write(Hour_reminder3_eeprom);
	mySoftwareSerial.write(Min_reminder3_eeprom);
	mySoftwareSerial.write(0xEE);
	mySoftwareSerial.write(0xFF);
	*/
	
	Day_reminder4_eeprom[0] = EEPROM.read(Reminder4_day7);
	Day_reminder4_eeprom[1] = EEPROM.read(Reminder4_day6);
	Day_reminder4_eeprom[2] = EEPROM.read(Reminder4_day5);
	Day_reminder4_eeprom[3] = EEPROM.read(Reminder4_day4);
	Day_reminder4_eeprom[4] = EEPROM.read(Reminder4_day3);
	Day_reminder4_eeprom[5] = EEPROM.read(Reminder4_day2);
	Day_reminder4_eeprom[6] = EEPROM.read(Reminder4_day1);
	Hour_reminder4_eeprom =   EEPROM.read(Reminder4_Hour);
	Min_reminder4_eeprom = EEPROM.read(Reminder4_Min);
	
	VolumeSetValue = EEPROM.read(Volume_Address);
	/*
	mySoftwareSerial.write(Day_reminder4_eeprom[0]);
	mySoftwareSerial.write(Day_reminder4_eeprom[1]);
	mySoftwareSerial.write(Day_reminder4_eeprom[2]);
	mySoftwareSerial.write(Day_reminder4_eeprom[3]);
	mySoftwareSerial.write(Day_reminder4_eeprom[4]);
	mySoftwareSerial.write(Day_reminder4_eeprom[5]);
	mySoftwareSerial.write(Day_reminder4_eeprom[6]);
	mySoftwareSerial.write(Day_reminder4_eeprom[7]);
	mySoftwareSerial.write(Hour_reminder4_eeprom);
	mySoftwareSerial.write(Min_reminder4_eeprom);
	mySoftwareSerial.write(0x1A);
	mySoftwareSerial.write(0x2A);
	*/
	
	//Serial.println("EEPROM Initialized");
}


void fetchVolumeValue(){
	VolumeSetValue = EEPROM.read(Volume_Address);
	
}

void setVolume(){
	EEPROM.write(Volume_Address, VolumeCommandValue);
	myDFPlayer.volume(VolumeCommandValue); 
	delay(50);
	DialTone();
}
