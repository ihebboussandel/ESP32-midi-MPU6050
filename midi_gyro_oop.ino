

//internal classes 
#include"ring.h"

#include"gyro_cont.h"

#include "config.h"



uint8_t velocity = 100;                 //velocity of MIDI notes, must be between 0 and 127
 

#include <Wire.h>

ring leds ;
gyro_cont gyro ;


void setup() {
  Wire.begin(0,4);
  gyro.setup();
  leds.setup(NUM_LEDS,BRIGHTNESS);


  //Set MIDI baud rate:
  Serial.begin(115200);
  delay(500);

}

void loop() {
 gyro.loop();
 leds.loop(gyro.get_x(),gyro.get_y(),gyro.get_z());
 MIDIControlChange_gyro(controlChange, 14,gyro.get_x());//turn note on
 MIDIControlChange_gyro(controlChange, 15,gyro.get_y());//turn note on
 MIDIControlChange_gyro(controlChange, 16,gyro.get_z());//turn note on
 }

//send MIDI Control messages
void MIDIControlChange_gyro(int command, int data1, int data2) {
  uint8_t datacaml=mapCalibrate(data2, -90, 90, 0.0, 127.0,0.0);

  Serial.write(command);//send command byte
  Serial.write(data1);//send data byte #1
  Serial.write(datacaml);//send data byte #2
}
void MIDImessage(int command, int data1, int data2) {

  Serial.write(command);//send command byte
  Serial.write(data1);//send data byte #1
  Serial.write(data2);//send data byte #2
}
void MIDIaftertouch(int command, int data1, int data2) {
  Serial.write(command);//send aftetouch_command
  Serial.write(data1);//send pitch data
  Serial.write(data2);//send velocity data
  
}
void SystemExclusive(int systemStartbit,int ManifacturerID ,int data1,int data2,int data3,int SystemENDbit){
  Serial.write(systemStartbit);//send aftetouch_command

}

bool MIDIclock() {
  String Serial_valeus= (String)Serial.read() ;
    if(Serial_valeus==(String)timing_clock){
      return true;
    }else{
      return false;
    }
}

//math librray 
float mapCalibrate( float Input,float H_in, float L_in,float H_out, float L_out,  float Calib){

 return  L_out +  ((Input - L_in) /(H_in - L_in)) * (H_out - L_out) + 0;
}



