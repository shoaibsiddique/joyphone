



void enableRinging_Bell(){

	
//Enable Alarm for Reminder-1
if( (dOW_ == Day_reminder1_eeprom[0] || dOW_ == Day_reminder1_eeprom[1] || dOW_ == Day_reminder1_eeprom[2] || dOW_ == Day_reminder1_eeprom[3] || dOW_ == Day_reminder1_eeprom[4]
		|| dOW_ == Day_reminder1_eeprom[5] || dOW_ == Day_reminder1_eeprom[6]) && hour_ == Hour_reminder1_eeprom && minute_ == Min_reminder1_eeprom
		&& reminder1_alarmed == false)
		{
			enableRinging_theBell_R1 = true;

		}else{
			enableRinging_theBell_R1 = false;
		}

//Enable Alarm for Reminder-2
if( (dOW_ == Day_reminder2_eeprom[0] || dOW_ == Day_reminder2_eeprom[1] || dOW_ == Day_reminder2_eeprom[2] || dOW_ == Day_reminder2_eeprom[3] || dOW_ == Day_reminder2_eeprom[4]
		|| dOW_ == Day_reminder2_eeprom[5] || dOW_ == Day_reminder2_eeprom[6]) && hour_ == Hour_reminder2_eeprom && minute_ == Min_reminder2_eeprom
		&& reminder2_alarmed == false)
		{
			enableRinging_theBell_R2 = true;
		}else{
			enableRinging_theBell_R2 = false;
		}
		
//Enable Alarm for Reminder-3
if( (dOW_ == Day_reminder3_eeprom[0] || dOW_ == Day_reminder3_eeprom[1] || dOW_ == Day_reminder3_eeprom[2]|| dOW_ == Day_reminder3_eeprom[3] || dOW_ == Day_reminder3_eeprom[4]
		|| dOW_ == Day_reminder3_eeprom[5] || dOW_ == Day_reminder3_eeprom[6]) && hour_ == Hour_reminder3_eeprom && minute_ == Min_reminder3_eeprom
		&& reminder3_alarmed == false)
		{
			enableRinging_theBell_R3 = true;
		}else{
			enableRinging_theBell_R3 = false;
		}

//Enable Alarm for Reminder-4
if( (dOW_ == Day_reminder4_eeprom[0] || dOW_ == Day_reminder4_eeprom[1] || dOW_ == Day_reminder4_eeprom[2] || dOW_ == Day_reminder4_eeprom[3] || dOW_ == Day_reminder4_eeprom[4]
		|| dOW_ == Day_reminder4_eeprom[5] || dOW_ == Day_reminder4_eeprom[6]) && hour_ == Hour_reminder4_eeprom && minute_ == Min_reminder4_eeprom
		&& reminder4_alarmed == false)
		{
			enableRinging_theBell_R4 = true;
		}else{
			enableRinging_theBell_R4 = false;
		}
	
	
}

void clearAlarmed_flags(){
	if(reminder1_alarmed==true && Min_reminder1_eeprom == Min_reminder1_eeprom+1){
		reminder1_alarmed = false;
	}
	
	if(reminder2_alarmed==true && Min_reminder2_eeprom == Min_reminder2_eeprom+1){
		reminder2_alarmed = false;
	}
	
	if(reminder3_alarmed==true && Min_reminder3_eeprom == Min_reminder3_eeprom+1){
		reminder3_alarmed = false;
	}
	
	if(reminder4_alarmed==true && Min_reminder4_eeprom == Min_reminder4_eeprom+1){
		reminder4_alarmed = false;
	}
	
}