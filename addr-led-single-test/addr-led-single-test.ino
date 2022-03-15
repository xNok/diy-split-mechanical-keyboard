#include <FastLED.h>

#define LED_PIN     1
#define NUM_LEDS    1
#define RXLED      17

int R = 0;
int G = 0;
int B = 0;
int INREMENT = 50;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  // Also blink the onboard led to make sure everything is OK
  digitalWrite(RXLED, LOW);
  TXLED0;
}

void loop() {
  
  leds[0] = CRGB(R, G, B); //This set the desired colour
  FastLED.show(); // this send the signal to the LED
  //Increment quantity of red until max
  R += INREMENT;
  if (R>=255) {
    //Increment green and reset red for now
    R = 0;
    G += INREMENT;
  }
  if (G>=255) {
    //Increment blue and reset green for now
    G = 0;
    B += INREMENT;
  }
  if (B>=255){
    //Reset blue and reset green for now
    B=0;
  }
  // wait so our eyes can see the change
  delay(100);

}
