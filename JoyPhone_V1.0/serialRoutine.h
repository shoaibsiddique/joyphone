#include "SoftwareSerial.h"
SoftwareSerial mySoftwareSerial(10, 11); //RX, TX


unsigned char Rx_buffer_tmp[13];
unsigned char Rx_buffer[13];
u8 rx_ctr =0;
unsigned char RX_Flag = 0x00;
int rx_ByteSize = 2; //rx_ByteSize = ByteSize - 1

char recByte = 0x00;
int index = 0;
byte rec_arrayBytes[3] = {0}; 
bool replyFlag = false;


bool reminder_Set_reply = 0;