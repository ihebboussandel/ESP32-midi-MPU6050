#include"ring.h"
ring::ring(){
  
}
void ring::setup(uint8_t numleds,uint8_t brightness){
    NUM_LEDS = numleds;
   FastLED.addLeds<WS2812,12>(leds,numleds); 
   FastLED.setBrightness(brightness);
  }
void ring::loop(int x ,int y ,int z ){
     animation(x,y,z);
  }
void ring::animation(int x,int y,int z){
    int pos,pos2,pos3;
  //leds[pos+] = CRGB(50,50,100);
  //leds[pos+] = CRGB(50,50,100);
  pos=map(x,-90,90,2,NUM_LEDS -2);
  pos2=map(y,-190,90,2,NUM_LEDS -2);
  pos3=map(z,-90,90,2,NUM_LEDS -2);
  leds[pos-2] = CRGB(255,0,0);
  leds[pos-1] = CRGB(255,0,0);
  leds[pos] = CRGB(255,0,250);
  leds[pos+1] = CRGB(255,0,0);
  leds[pos+2] = CRGB(255,0,0);

  leds[pos2-2] = CRGB(0,255,0);
  leds[pos2-1] = CRGB(0,255,0);
 
  leds[pos2+1] = CRGB(0,255,0);
  leds[pos2+2] = CRGB(0,255,0);

  leds[pos3-2] = CRGB(0,0,255);
  leds[pos3-1] = CRGB(0,0,255);
  
  
  leds[pos3+1] = CRGB(0,0,255);
  leds[pos3+2] = CRGB(0,0,255);


  leds[pos] = CRGB(255,0,250);
   leds[pos2] = CRGB(255,255,255);
  leds[pos3] = CRGB(255,255,0);
  //leds[pos-1] = CRGB(50,50,100);
  FastLED.show();
  FastLED.clear();
  
  }
