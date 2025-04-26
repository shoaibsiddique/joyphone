
//TeleJuke States
#define PhoneIsPlaced 1
#define PhoneIsPicked 2
#define DiallingNumber 9

DFRobotDFPlayerMini myDFPlayer;

int playTrackNo = 0;
int playEnable ;
boolean playEnableLastState;
boolean playEnablePresentState;

// Defining variables for Phone Dialler ---> (START)	
#define PULSE_PIN 7
#define mp3PlayerIsBusyPin 2

int lastPulse;
int pulseCount;
int DialPadValue;
unsigned long timing;
int readDigit;
int state =0;
boolean phoneOffHook;
boolean phoneIsBusy = false;

#define MIN_PULSE_TIME  60 //60
#define MAX_PULSE_TIME 140 //140
#define DIGIT_GAP_TIME 200
#define ON_HOOK_TIME   500


#define Alarm_pick_delay 2000
// Defining variables for Phone Dialler <--- (END)

const int phoneHolder = A0; 
float phoneHolderSensor = 0;        // value read from the phoneHolder


void setDiallerSpeaker_IOs(){
	
  pinMode (PULSE_PIN, INPUT);
  timing = millis();
  pinMode(mp3PlayerIsBusyPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(mp3PlayerIsBusyPin), isMP3Playing, CHANGE);//To check if phone is placed or picked
  
  readDigit = -1;
  phoneOffHook = false;
  playEnable = 2;
  playEnableLastState= false;
  playEnablePresentState = false;
  pulseCount = 0;
  DialPadValue = 20;
  /*Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  */
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    /*Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));*/
    while(true);
  }
  /*Serial.println(F("DFPlayer Mini online."));*/
    Wire.begin();
    delay(500);
	
	
  //myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  myDFPlayer.volume(VolumeSetValue);  //Set volume value. From 0 to 30

  //myDFPlayer.playFolder(6, 1);


}



void readDiallerValue(){
  unsigned long newtime = millis();
  int pulse = digitalRead (PULSE_PIN);
  //Serial.println(pulse);
  

  if ((lastPulse == HIGH) && (pulse == LOW)) {
    // We have a falling edge.
    // So is it a pulse, or going off-hook, or even a "bounce"?
    //
    // We can use the time since the last rising edge
    // to tell us...
    // If time < MIN PULSE time it was probably a bounce
    // If time > MAX PULSE time it was probably going off-hook
    if (newtime > timing + MAX_PULSE_TIME) {
      phoneOffHook = true;
	  playEnable = 0;
      Serial.println("Phone: Off-hook");
	  myDFPlayer.pause(); 
	  if(enableRinging_theBell_R1 == true || enableRinging_theBell_R2 == true || enableRinging_theBell_R3 == true || enableRinging_theBell_R4 == true){
		disableBell();

		if(enableRinging_theBell_R1 == true)
		{reminder1_alarmed = true;
		//enableRinging_theBell_R1 = false; // 10 01 2023
	    myDFPlayer.playFolder(1, 1);
	    delay(Alarm_pick_delay);
		//Serial.print("Playing Track R1 ");
		}
	
		if(enableRinging_theBell_R2 == true)
		{reminder2_alarmed = true;
		//enableRinging_theBell_R2 = false; // 10 01 2023
	    myDFPlayer.playFolder(2, 1);
	    delay(Alarm_pick_delay);
		//Serial.print("Playing Track R2 ");
	
		}
	
		if(enableRinging_theBell_R3 == true)
		{reminder3_alarmed = true;
		//enableRinging_theBell_R3 = false; // 10 01 2023
	    myDFPlayer.playFolder(3, 1);
	    delay(Alarm_pick_delay);
		//Serial.print("Playing Track R3 ");
		}
	
		if(enableRinging_theBell_R4 == true)
		{reminder4_alarmed = true;
		//enableRinging_theBell_R4 = false; // 10 01 2023
	    myDFPlayer.playFolder(4, 1);
	    delay(Alarm_pick_delay);
		//Serial.print("Playing Track R4 ");	
		}
		}
      pulseCount = 0;
      readDigit = -1;
    } else if (newtime > timing + MIN_PULSE_TIME) {
      // Count it as a valid pulse
      pulseCount++;
      //Serial.print("Pulse: ");
     //Serial.println(pulseCount);
    } else {
      // Probably a short bounce, so ignore
    }

    // reset the timer
    timing = newtime;
  }

/*
  //if ((lastPulse == LOW) && (pulse == LOW)) {
	if ((lastPulse == LOW) && (pulse == HIGH)) {
    // If we've stayed low, then we are either between pulses
    // or between digits, so need to work out which...
    if (newtime > timing + DIGIT_GAP_TIME) {
      // Store the pulseCount so far and reset for the next digit
      if (pulseCount > 0) {
        readDigit = pulseCount;
        if (readDigit == 10) readDigit = 0; // "0" is 10 pulses
        Serial.print("Digit: ");
        Serial.println(readDigit);
      } else {
        // Nothing to report yet
      }
      pulseCount = 0;
    } else {
      // Just keep waiting, might just be between pulses
    }
  }*/

  if ((lastPulse == LOW) && (pulse == HIGH)) {
    // We have a rising edge, so reset the timer
    timing = newtime;
  }

  if ((lastPulse == HIGH) && (pulse == HIGH)) {
    // If we've stayed HIGH for longer than a pulse
    // then assume the phone is back on the hook.
    if (newtime > timing + ON_HOOK_TIME) {
      if (phoneOffHook) {
        phoneOffHook = false;
		//myDFPlayer.stop();
		//delay(500);
		
		
		if(pulseCount>=1 && pulseCount <=9){
			DialPadValue = pulseCount;
		}else
		if(pulseCount == 10){
			
			DialPadValue = 0;
		}else
			if(pulseCount>10 || pulseCount ==0){
				DialPadValue = 20;
			}
		else
		{
			DialPadValue = pulseCount;
		}
		delay(200);

		Serial.print("DialPad is:");
		Serial.println(DialPadValue);
		playTrackNo = DialPadValue;
		playEnable = 1;
		
        readDigit = -1;
        pulseCount = 0;
		DialPadValue = 20;
      }
    }
	
  }

  lastPulse = pulse;
  //Serial.println(playEnable);
  if(playEnable == 1){
	  //myDFPlayer.stop();
	  //delay(200);
	  if(playTrackNo>0 && playTrackNo<=9){

		myDFPlayer.playFolder(9, playTrackNo);
	    delay(100);
		myDFPlayer.enableLoop(); //enable loop.
        delay(1000);
		Serial.print("Playing Track No: ");
		Serial.println(playTrackNo);
	    playEnable = 0; 
	  }else
	if(playTrackNo==0){
		myDFPlayer.playFolder(9, 10);
	    delay(100);
		myDFPlayer.enableLoop(); //enable loop.
        delay(1000);
		Serial.print("HH Playing Track No: ");
		Serial.println(10);
	    playEnable = 0; 
	  }

  }
}





void isMP3Playing(){
	
	if(digitalRead(mp3PlayerIsBusyPin) == 0){
	phoneIsBusy = true;
	}
	else{
		phoneIsBusy = false;
	}
	
}


void dialler_ringer_loop(){
	
	
 //ROUTINE TO CHECK IF PHONE IS PICKED OR IS IT PLACED ?
  //If the phone is not busy (i.e. mp3 is not playing), then check the status of the Phone if it is placed or picked
  if(!phoneIsBusy){
	phoneHolderSensor = analogRead(phoneHolder);
	float phoneHolderVolts = (phoneHolderSensor/1023)*5;
	//Serial.print("VOLT = ");
	//Serial.println(phoneHolderVolts);

	if(phoneHolderVolts >4.00 && phoneHolderVolts <=4.25){
	  state = PhoneIsPicked;
	  
	}
	 else
	 if(phoneHolderVolts >4.8){
	  state = PhoneIsPlaced;
	}/*
 else
 if(phoneHolderVolts<1.5){
  myDFPlayer.pause(); 
 }*/
  }
  
  
  //Serial.println(phoneIsBusy); //read mp3 state
 // Serial.println(state); //read mp3 state
  readDiallerValue();
  if(state == PhoneIsPlaced){//1
	  //myDFPlayer.pause(); 
	  dialTonePlayed = false;
  }
  
    if(state == PhoneIsPicked){//2
	  disableBell();
  }
  
  if(state == PhoneIsPicked && enableRinging_theBell_R1 == false && enableRinging_theBell_R2 == false 
      && enableRinging_theBell_R3 == false && enableRinging_theBell_R4 == false ){

	if(dialTonePlayed==false){
		DialTone();
		dialTonePlayed = true;
		//myDFPlayer.playFolder(6, 1);
	}
}
}

void DialTone(){
	myDFPlayer.playFolder(6, 1);
	delay(100);
	myDFPlayer.enableLoop(); //enable loop.
    delay(500);
}
