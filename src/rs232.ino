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
  int ion_count = Read_Ion_Count();
  Serial.println(ion_count);
}
int Read_Ion_Count()
{
 char buffer[4];
 int bufferIndex =0;
 for( int globalIndex = 0; ;)
 {
   if (RS232Out.available()) 
   {
     int inByte = RS232Out.read();
     if(inByte == 10) 
     {
      break;
     }
     else if(inByte == 9)
     {
      globalIndex++;
     }
     else if(globalIndex == 3)
     {
      buffer[bufferIndex] = char(inByte);
      bufferIndex++;
     }
   }
 }
 int  ion_count;
 ion_count = atoi(buffer);
 return ion_count;
}
