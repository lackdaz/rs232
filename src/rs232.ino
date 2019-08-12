#include <SoftwareSerial.h>

SoftwareSerial RS232Out(D4, D3); // RX (red), TX (orange)
int i = 0;
int globalIndex = 0;

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
    globalIndex=0;
   }
   else if(inByte == 9) 
   {
    globalIndex++;
   }
   else
   {
    if(globalIndex == 3)
    {
      Serial.print(char(inByte)); 
    }
   }
 }
}
