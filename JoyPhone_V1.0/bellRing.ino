
//This code is to ring the bell on the rotarytelephone.

// Motor Driver => L298
// IN3 -> D4 Nano
// IN4 -> D3 Nano
// ENB -> D2 Nano
// OUT1-> Pin 2 of Rotary Phone -> Green Wire
// OUT2-> Pin 3 of Rotary Phone -> Red Wire

#define ring_positive 4 //A+ //IN1
#define ring_negative 3 //A- //IN2
#define enable_ring 2 //EN1
#define heartbeat 13

#define RL1 5 //To on the signal for motor driver A+ going to pin4 of phone
#define RL2 6 //To on the signal for motor driver A- going to pin2 of phone

#define delayRingTime 20 

#define turnOnRelay 0
#define turnOffRelay 1


bool ringFlag = false;
bool noRingFlag = false;
bool TRUE = 1;
bool FALSE = 0;
int timer1_counter=3036;  // preload timer 65536-16MHz/256/1Hz => 1sec



typedef struct      //structure use to hold the status and time of different time functions.
{
  char status;
  unsigned int time;
} timer_state;

timer_state timer_3s;
timer_state timer_1s;
unsigned int timer1_interruptCounter =0;

void timer1_init(){
  
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 3036; //64000;   // preload timer 65536-16MHz/256/1Hz => 1sec
  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 = 0b00000001; // Set the TOIE1 bit
    //Initialize 3sec timer
  timer_3s.time = 3;        //1sec *120  (3sec)
  timer_3s.status = 0x00;
  timer_1s.time =1;        //1sec *120  (3sec)
  timer_1s.status = 0x00;
  interrupts();             // enable all interrupts

}


ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
  timer1_interruptCounter = timer1_interruptCounter+1;
  //digitalWrite(heartbeat, digitalRead(heartbeat) ^ 1);
  if((timer1_interruptCounter % timer_3s.time)==0){
    if(timer_3s.status==FALSE){
      timer_3s.status=TRUE;
    }else
    if(timer_3s.status==TRUE){
      timer_3s.status=FALSE;
    }
 }
 
   if((timer1_interruptCounter % timer_1s.time)==0){
    if(timer_1s.status==FALSE){
      timer_1s.status=TRUE;
    }else
    if(timer_1s.status==TRUE){
      timer_1s.status=FALSE;
    }
 }
 
 
  TCNT1 = timer1_counter;   // preload timer
  //digitalWrite(heartbeat, digitalRead(heartbeat) ^ 1);

}



void ringBell_setup() {
  cli();

  // put your setup code here, to run once:
  pinMode(ring_positive, OUTPUT);
  pinMode(ring_negative, OUTPUT);
  pinMode(enable_ring, OUTPUT);
  pinMode(heartbeat, OUTPUT);
  pinMode(RL1, OUTPUT);
  pinMode(RL2, OUTPUT);

 // pinMode (6, INPUT_PULLUP);
  digitalWrite(enable_ring, 1);
  digitalWrite(ring_positive,0);
  digitalWrite(ring_negative,0);
  timer1_init();
  sei();
  
}

void bellRing_loop() {
  // put your main code here, to run repeatedly:
 // digitalWrite(RL1, turnOnRelay);
  //digitalWrite(RL2, turnOnRelay);
  //ringBell();

  digitalWrite(heartbeat, timer_1s.status);
  digitalWrite(enable_ring, timer_3s.status);
  

  
}

void ringBell(){
  digitalWrite(ring_positive,0);
  digitalWrite(ring_negative,1);
  delay(delayRingTime);
  digitalWrite(ring_positive,1);
  digitalWrite(ring_negative,0);
  delay(delayRingTime);
}


void get_1sec_RTC(){
	    if(timer_1s.status){//Check the values of RTC every 1 sec.
	getRTCvalues();
}
}


void enableBell(){
  digitalWrite(RL1, turnOnRelay);
  digitalWrite(RL2, turnOnRelay);
  ringBell();
}

void disableBell(){
  digitalWrite(RL1, turnOffRelay);
  digitalWrite(RL2, turnOffRelay);
}