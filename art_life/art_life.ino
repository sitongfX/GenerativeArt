/*
 Display all the cool text.

 This sketch uses the GLCD (font 1) and fonts 2, 4, 6, 7, 8
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
*/


// Pause in milliseconds between screens, change to 0 to time font rendering
#define WAIT 500

#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h


void setup(void) {
  tft.init();
  randomSeed(analogRead(5)); 
  tft.setRotation(1);
}

void loop() {

  
  int randcol = random(0,128);
  int randcol1 = random(0,128);
  tft.fillScreen(tft.color565(randcol, 0, randcol1));
  tft.fillScreen(TFT_YELLOW);
  tft.setTextColor(TFT_ORANGE);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_BLUE, TFT_BLACK);

  tft.drawString("OK", 0, 0, 8);

  delay(WAIT);

  int randsize = random(0,9);
  int randsize1 = random(0,9);
  int randsize2 = random(0,9);

  int randpos = random(0,20);
  int randpos1 = random(0,30);
  int randpos2 = random(0,10);
  
  tft.fillScreen(TFT_RED);

  tft.setTextColor(TFT_MAGENTA);

  tft.drawString("...", 0, randpos, randsize1);  // if fontsize is not valid then it will not appear
  delay(WAIT);

  tft.drawString("...", randpos1, 0, randsize);
  delay(WAIT);
  
  tft.drawString("...", 0, randpos2, randsize2);
  delay(WAIT);

  tft.drawString("...", randpos1, 0, randsize2);
  delay(WAIT);

  tft.setTextColor(TFT_GREEN);
 
  tft.drawString("DESCRIBE LIFE ; ( ", 10, 20, 2);
  delay(WAIT);
  delay(4000);


  tft.setTextColor(TFT_ORANGE);

  tft.drawString("Sitong : < ", 80, 80, 4);

  delay(4000);
}
