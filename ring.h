//led includes 
#include <FastLED.h>

class ring{
  //max leds array is set to 25 by default
   CRGBArray<25> leds;

  public : 
  int NUM_LEDS ;
  ring();
 
  void setup(uint8_t numleds,uint8_t brightness);
  void loop(int x ,int y ,int z );
  void animation(int x,int y,int z);
};

