#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
int latchPin = A1; //Pin connected to Pin 12 of 74HC595 (Latch)
int clockPin = A2; //Pin connected to Pin 11 of 74HC595 (Clock)
int dataPin = A0; //Pin connected to Pin 14 of 74HC595 (Data)
float x,y,z;
int dataPin2 = 6;
int k=0;
float A=45.00002;
float B=-A;
float AY=A*0.5;
float BY=B*0.5;
float AX=A*0.5;
float BX=B*0.5;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop() {
  mpu6050.update();
    Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
    Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
 Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());

     if(abs(mpu6050.getAngleZ()) >abs( mpu6050.getAngleY()) && abs(mpu6050.getAngleZ()) >abs( mpu6050.getAngleX()) )
     {


  if(mpu6050.getAngleZ()>0 && mpu6050.getAngleZ()<1*A )  // 1  z +ve
  { 
     digitalWrite(latchPin, LOW); 
  shiftout(0x3f81);
  digitalWrite(latchPin, HIGH);
     }
    
  
 else if(mpu6050.getAngleZ()>1*A && mpu6050.getAngleZ()<2*A  )    // 2 z +ve
  {
   
 
      digitalWrite(latchPin, LOW); 
  shiftout(0x7f55);
  digitalWrite(latchPin, HIGH);
   
  }

  
 else if(mpu6050.getAngleZ()>2*A && mpu6050.getAngleZ()<3*A  )     // 3 z +ve
  {
   
        
       digitalWrite(latchPin, LOW); 
  shiftout(0x3f60);
  digitalWrite(latchPin, HIGH);

  }

  
 else if(mpu6050.getAngleZ()>3*A && mpu6050.getAngleZ()<4*A  )     // 4 z +ve
  {
     digitalWrite(latchPin, LOW); 
  shiftout(0xbfAA);
  digitalWrite(latchPin, HIGH);

  }
   if(mpu6050.getAngleZ()<0 && mpu6050.getAngleZ()>1*B )        // 1 z -ve
  { 
   
    Serial.print("over 0 less than 10");
     digitalWrite(latchPin, LOW); 
  shiftout(0x3f81);
  digitalWrite(latchPin, HIGH);
 
  }
  
 else if(mpu6050.getAngleZ()<1*B && mpu6050.getAngleZ()>2*B )      // 2 z -ve
  {
    Serial.print("over 10 less than 15");

      digitalWrite(latchPin, LOW); 
  shiftout(0xBfAA);
  digitalWrite(latchPin, HIGH);

  }

  
 else if(mpu6050.getAngleZ()<2*B && mpu6050.getAngleZ()>3*B )    // 3 z -ve
  {
    
        
       digitalWrite(latchPin, LOW); 
  shiftout(0x3f60);
  digitalWrite(latchPin, HIGH);
;
  }

  
 else if(mpu6050.getAngleZ()<3*B && mpu6050.getAngleZ()>4*B )      // 4 z -ve
  {
     digitalWrite(latchPin, LOW); 
  shiftout(0x7f55);
  digitalWrite(latchPin, HIGH);

  }
     }
 

     if(abs(mpu6050.getAngleY()) >abs( mpu6050.getAngleX()) && abs(mpu6050.getAngleY()) >abs( mpu6050.getAngleZ()))
     {

  
  if(mpu6050.getAngleY()>0 && mpu6050.getAngleY()<1*AY )     // 1  y +ve 
  {
     if(mpu6050.getAngleZ() > mpu6050.getAngleY()  )
     {
    Serial.print("over 0 less than 10");
     digitalWrite(latchPin, LOW); 
  shiftout(0x3f81);
  digitalWrite(latchPin, HIGH);
     }
     else if(mpu6050.getAngleZ()<  mpu6050.getAngleY()  )
     {
          digitalWrite(latchPin, LOW); 
  shiftout(0xAAAA);
  digitalWrite(latchPin, HIGH);
 
     }
  }
  
 else if(mpu6050.getAngleY()>1*AY && mpu6050.getAngleY()<2*AY )    // 2 y +ve 
  {
    Serial.print("over 10 less than 15");

      digitalWrite(latchPin, LOW); 
  shiftout(0xAA55);
  digitalWrite(latchPin, HIGH);
 
  }

  
 else if(mpu6050.getAngleY()>2*AY && mpu6050.getAngleY()<3*AY )     // 3  y +ve 
  {
    
        
       digitalWrite(latchPin, LOW); 
  shiftout(0x55AA);
  digitalWrite(latchPin, HIGH);
 
  }

  
 else if(mpu6050.getAngleY()>3*AY && mpu6050.getAngleY()<4*AY )    // 4  y +ve 
  {
     digitalWrite(latchPin, LOW); 
  shiftout(0x5555);
  digitalWrite(latchPin, HIGH);
 
  }
   if(mpu6050.getAngleY()<0 && mpu6050.getAngleY()>1*BY )     // 1  y -ve 
  {
    Serial.print("over 0 less than 10");
     digitalWrite(latchPin, LOW); 
  shiftout(0x5555);
  digitalWrite(latchPin, HIGH);
 
  }
  
 else if(mpu6050.getAngleY()<1*BY && mpu6050.getAngleY()>2*BY )    // 2  y -ve 
  {
    Serial.print("over 10 less than 15");

      digitalWrite(latchPin, LOW); 
  shiftout(0x55AA);
  digitalWrite(latchPin, HIGH);
 
  }

  
 else if(mpu6050.getAngleY()<2*BY && mpu6050.getAngleY()>3*BY )   // 3  y -ve 
  {
    
        
       digitalWrite(latchPin, LOW); 
  shiftout(0xAA55);
  digitalWrite(latchPin, HIGH);
 
  }

  
 else if(mpu6050.getAngleY()<3*BY && mpu6050.getAngleY()>4*BY )   // 4  y -ve 
  {
     digitalWrite(latchPin, LOW); 
  shiftout(0xAAAA);
  digitalWrite(latchPin, HIGH);
  
 
  }
     }
          if(abs(mpu6050.getAngleX()) >abs( mpu6050.getAngleY()) && abs(mpu6050.getAngleX()) >abs( mpu6050.getAngleZ()) )
     {


  if(mpu6050.getAngleX()>0 && mpu6050.getAngleX()<1*AX )  // 1  X +ve
  { 
     digitalWrite(latchPin, LOW); 
  shiftout(0x0081);
  digitalWrite(latchPin, HIGH);
     }
    
  
 else if(mpu6050.getAngleX()>1*AX && mpu6050.getAngleX()<2*AX  )    // 2 X +ve
  {
   

      digitalWrite(latchPin, LOW); 
  shiftout(0x06);
  digitalWrite(latchPin, HIGH);
   
  }

  
 else if(mpu6050.getAngleX()>2*AX && mpu6050.getAngleX()<3*AX  )     // 3 X +ve
  {
    
        
       digitalWrite(latchPin, LOW); 
  shiftout(0x0018);
  digitalWrite(latchPin, HIGH);

  }

  
 else if(mpu6050.getAngleX()>3*AX && mpu6050.getAngleX()<4*AX  )     // 4 X +ve
  {
     digitalWrite(latchPin, LOW); 
  shiftout(0x0060);
  digitalWrite(latchPin, HIGH);

  }
   if(mpu6050.getAngleX()<0 && mpu6050.getAngleX()>1*BX )        // 1 X -ve
  { 
   
    Serial.print("over 0 less than 10");
     digitalWrite(latchPin, LOW); 
  shiftout(0x0060);
  digitalWrite(latchPin, HIGH);
 
  }
  
 else if(mpu6050.getAngleX()<1*BX && mpu6050.getAngleX()>2*BX )      // 2 X -ve
  {
    Serial.print("over 10 less than 15");

      digitalWrite(latchPin, LOW); 
  shiftout(0x0018);
  digitalWrite(latchPin, HIGH);

  }

  
 else if(mpu6050.getAngleX()<2*BX && mpu6050.getAngleX()>3*BX )    // 3 X -ve
  {
    
        
       digitalWrite(latchPin, LOW); 
  shiftout(0x0006);
  digitalWrite(latchPin, HIGH);
;
  }

  
 else if(mpu6050.getAngleX()<3*BX && mpu6050.getAngleX()>4*BX )      // 4 X -ve
  {
     digitalWrite(latchPin, LOW); 
  shiftout(0x081);
  digitalWrite(latchPin, HIGH);

  }
     }
 

  

  
  
  else{
    printf("over shoot");
  }
  
}
void shiftout(int dataOut) {
  boolean pinState;
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);
  for (int i = 0; i <= 15; i++) {
    
    digitalWrite(clockPin, LOW); 
    if ( dataOut & (1 << i) ) { 
      pinState = HIGH; 
    }
    else {
      pinState = LOW;
    }
    
    digitalWrite(dataPin, pinState); 
    digitalWrite(clockPin, HIGH);
    
   
  }
  digitalWrite(clockPin, LOW);
}
