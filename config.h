/* omni mode */
#define noteOFF  128                    //128 = 10000000 in binary, note off command
#define noteON  144                     //144 = 10010000 in binary, note on command
/*mono mode*/

#define afterTouch 160                  //aftertouch  10100000 
#define controlChange 176        //Bn continuous controller 10110000
#define patchChange 192                 //patch change 11000000
#define channelAftertouch 208             // Channel pressure 11010000
#define pitchBend 224                   // Pitch bend 11100000

/************* System messages *******************/

/*System exclusive */

#define system_exclusive_start 240     // F0 status F0 Data 1 : manif ID Data 2 : Data 
#define system_exlusive_end 247        // F7 -  
/*system Common */ 

#define quarter_frame 241               //F1  qharterframe(MTC) F1 data  - 
#define song_pointer 242                // F2 LSbyte MSbyte 
#define song_select  243                // F3 Song Number  - 
#define tune_request 246                // F6 -   - 

/* System Real-time */ 
#define timing_clock 248               //input Timing clock value F8  
#define rt_start                       //FA
#define rt_continue                    //FB
#define rt_stop                        //FC
#define rt_active_sensing              //FE
#define reset                          //FF

/*************System messages end **********/

/*********Control change (2)************/ 

#define bankSelect 0 
#define modulationWheel 1 
#define breathController 2 
#define Undif_1 3
#define footController 4
#define protamentoTime 5
#define dataEntrySlider 6
#define mainVolume 7
#define balance 8
#define undif_2 9
#define pan 10
#define expressionController 11
#define effectControl_1 12
#define effectControl_2 13
#define undif_3 14
#define undif_4 15

/*********Control change (3)************/ 

#define sustainPedal 64
#define portamento_ON_OFF 65
#define sostenutoPedal
#define softPedal
#define legatoFootswitch 
#define hold_2
#define soundcontrollers_46_4f
#define general_c_5_8
#define portamentoControl 84
#define dataIncrement 
#define dataDecrement 
#define NRPC_LSbyte_non_reg_param_cont
#define NRPC_MSbyte
#define RPC_LSbyte_reg_param_cont
#define RPC_MSbyte

/*****************************/ 
#define LED_PIN 12
#define NUM_LEDS 15
#define BRIGHTNESS 60

