/*  MILTON STANLEY
 *  POLOLU RGB LED strip
 *  Uses the great library found at https://github.com/pololu/pololu-led-strip-arduino
 *  
 * DONE:
 *   Rainbow fade (whole strip)  
 *
 * TO DO:
 *  Dimmer pot
 *  16 preset colors (including white)
 *    - Primaries + user-defined stored in ROM?
 *  2-color fade 
 *
 *  Rainbow fade (sequential)
 *  R,G,B pots
 *  IR Remote control
 */
  
#include <PololuLedStrip.h>  
  
#define MESSAGE_LENGTH 12    
#define IR_HIGH 1000          
#define IR_LOW 400         
#define IR_THRESHOLD IR_LOW+((IR_HIGH-IR_LOW)/2)
#define START_BIT 2000    
#define IR_READER 4  
#define LED_STRIP 12  
#define LED_COUNT 60  
#define INTERRUPT 9


rgb_color colors[LED_COUNT];
PololuLedStrip<LED_STRIP> ledStrip;

 
void setup() {
  pinMode(IR_READER, INPUT);
  pinMode(13, OUTPUT);
  pinMode(INTERRUPT, OUTPUT);
  delay(1000);
  Serial.begin(9600);
  attachInterrupt(0, getCommand, HIGH);
} 

void loop() {
  unsigned int code = 0x00; 
  while (pulseIn(IR_READER, LOW) < START_BIT) {}
  for (byte i = 0; i < MESSAGE_LENGTH; i++) {
      code |= (pulseIn(IR_READER, LOW) > IR_THRESHOLD) << i;  
  }
  if(code==2050){digitalWrite(INTERRUPT, HIGH);}
  Serial.println(code);
  delay(500);
}
void getCommand(){
  Serial.println("Interrupt");
  digitalWrite(INTERRUPT, LOW);
}

/*
void RainbowFadeStrip(boolean startOff){
  int red;
    if(startOff){red = 0;}
    else{red = 255;}
  int green = 0;
  int blue = 0;  
  if(startOff){while(red<255){red += 1; sendSolid(red, green, blue);}}    // red to max     0,0,0 -> 255,0,0 ONLY IF Cycle starts and ends with ALL OFF
  while(red==255 && green < 255){green += 1; sendSolid(red, green, blue);}  // green to max   255,0,0 -> 255,255,0 
  while(green==255 && red > 0){red -= 1; sendSolid(red, green, blue);}      // red to min     255,255,0 -> 0,255,0
  while(red==0 && blue < 255){blue += 1; sendSolid(red, green, blue);}      // blue to max    0,255,0 -> 0,255,255
  while(blue==255 && green > 0){green -= 1; sendSolid(red, green, blue);}   // green to min   0,255,255 -> 0,0,255
  while(green==0 && red < 255){red += 1; sendSolid(red, green, blue);}      // red to max     0,0,255 -> 255,0,255             
  while(red==255 && blue > 0){blue -= 1; sendSolid(red, green, blue);}      // blue to min    255,0,255 -> 255,0,0
  if(startOff){while(red>0){red-=1; sendSolid(red, green, blue);}}        // red to min     255,0,0 -> 0,0,0 ONLY IF Cycle starts and ends with ALL OFF
  if(startOff){delay(250);}                          // delay if all off ONLY IF Cycle starts and ends with ALL OFF
}

void sendSolid(int red, int green, int blue){
  rgb_color color;
  color.red = red; color.green = green; color.blue = blue;
  for(byte i = 0; i < LED_COUNT; i++) colors[i] = color;
  ledStrip.write(colors, LED_COUNT);  
  delay(5);
}

void newMode(){
  //allRed();
}

void allRed(){
  while(true){
  rgb_color color;
  color.red = 255; color.green = 0; color.blue = 0;
  for(byte i = 0; i < LED_COUNT; i++) colors[i] = color;
  ledStrip.write(colors, LED_COUNT);
  }
}

void allGreen(){
  while(true){
  rgb_color color;
  color.red = 0; color.green = 255; color.blue = 0;
  for(byte i = 0; i < LED_COUNT; i++) colors[i] = color;
  ledStrip.write(colors, LED_COUNT);
  }
}

void allBlue(){
  while(true){
  rgb_color color;
  color.red = 0; color.green = 0; color.blue = 255;
  for(byte i = 0; i < LED_COUNT; i++) colors[i] = color;
  ledStrip.write(colors, LED_COUNT);
  }
}
*/
