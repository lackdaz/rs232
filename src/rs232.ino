#include <SoftwareSerial.h>

SoftwareSerial RS232Out(D4, D3); // RX (red), TX (orange)
int i = 0;

void setup() {
 Serial.begin(9600);
 RS232Out.begin(19200);
 Serial.println("Start"); 
}

void loop()
{
 char buffer[4];
 if (RS232Out.available()) 
 {
   int inByte = RS232Out.read();
   if(inByte == 10) 
   {
    Serial.println("");
   }
   else
   {
    Serial.print(char(inByte)); 
    //Serial.print("]"); 
    //Serial.print(inByte); 
    //Serial.print("]"); 
   }
 }
}
