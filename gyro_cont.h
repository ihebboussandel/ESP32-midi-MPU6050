//gyro includes 

#include "I2Cdev.h"
#include "MPU6050.h"

class gyro_cont{
  MPU6050 accelgyro;
  private :
  
            int16_t ax, ay, az, gx, gy, gz;
            double timeStep, time, timePrev;
            double arx, ary, arz, grx, gry, grz, gsx, gsy, gsz, rx, ry, rz;
          
  public : 
            int i;
            double gyroScale = 131;
    
    
            gyro_cont();
            void setup(){
               //time
                  time = millis();
                  i = 0;
          
                  accelgyro.initialize();
                    // verify connection
                //DigiKeyboard.println("Testing device connections...");
                //DigiKeyboard.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
            
                // use the code below to change accel/gyro offset values
                /*
                Serial.println("Updating internal sensor offsets...");
                // -76  -2359 1688  0 0 0
                Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
                Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
                Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
                Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
                Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
                Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
                Serial.print("\n");
                accelgyro.setXGyroOffset(220);
                accelgyro.setYGyroOffset(76);
                accelgyro.setZGyroOffset(-85);
                Serial.print(accelgyro.getXAccelOffset()); Serial.print("\t"); // -76
                Serial.print(accelgyro.getYAccelOffset()); Serial.print("\t"); // -2359
                Serial.print(accelgyro.getZAccelOffset()); Serial.print("\t"); // 1688
                Serial.print(accelgyro.getXGyroOffset()); Serial.print("\t"); // 0
                Serial.print(accelgyro.getYGyroOffset()); Serial.print("\t"); // 0
                Serial.print(accelgyro.getZGyroOffset()); Serial.print("\t"); // 0
                Serial.print("\n");
                */
                accelgyro.setXGyroOffset(45);
                accelgyro.setYGyroOffset(-10);
                accelgyro.setZGyroOffset(10);
            }
            void loop(){
            
            timePrev = time;
            time = millis();
            timeStep = (time - timePrev) / 1000; // time-step in s
           
            // collect readings
            accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
          
            // apply gyro scale from datasheet
            gsx = gx/gyroScale;   
            gsy = gy/gyroScale;   
            gsz = gz/gyroScale;
          
            // calculate accelerometer angles
            arx = (180/3.141592) * atan(ax / sqrt(sq(ay) + sq(az))); 
            ary = (180/3.141592) * atan(ay / sqrt(sq(ax) + sq(az)));
            arz = (180/3.141592) * atan(az /sqrt(sq(ay) + sq(ax)));
          
            // set initial values equal to accel values
            if (i == 1) {
              grx = arx;
              gry = ary;
              grz = arz;
            }
            // integrate to find the gyro angle
            else{
              grx = grx + (timeStep * gsx);
              gry = gry + (timeStep * gsy);
              grz = grz + (timeStep * gsz);
            }  
          
            // apply filter
            rx = (0.9 * arx) + (0.04 * grx);
            ry = (0.9 * ary) + (0.04 * gry);
            rz = (0.9 * arz) + (0.04 * grz);
          
            i = i + 1;
            delay(50);
            //debug();
            
            }
            
            int get_x(){
              return rx;
            }
            int get_y(){
              return ry;
            }
            int get_z(){
              return rz;
            }
            void debug();
};


