#include <FastLED.h>

#define LED_PIN     1
#define NUM_LEDS    27 //crkbd model as 27 leds

int R = 0;
int G = 0;
int B = 0;
int INREMENT = 0;
int ON_OFF = 1;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  Serial.begin(9600); // open the serial po0rt at 9600 bps, so we ca see the counter
}


void loop() {
  // turn on the LED on at the time
  // then turn then off one at the time

  leds[INREMENT] = CRGB(255*ON_OFF, 0, 0);
  FastLED.show();
  Serial.print(INREMENT);
  Serial.print("\n");
  
  delay(200);
  INREMENT++;
  if (INREMENT>=NUM_LEDS) {
    INREMENT = 0;
    if (ON_OFF) {
      ON_OFF = 0;
    }else {
      ON_OFF = 1;
    }
  }
  
}
