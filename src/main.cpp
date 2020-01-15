#include <Arduino.h>
#include <FastLED.h>
#include <Visualization.h>

// FAST LED
#define NUM_LEDS 288
#define DISPLAY_LED_PIN 2

CRGB leds[NUM_LEDS];

#define SATURATION 244

Visualization * all;


void setup() {
  delay(1000);

  Serial.begin(9600);
  Serial.println("setup started");

  // DISPLAY STUFF
  FastLED.addLeds<NEOPIXEL, DISPLAY_LED_PIN>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );;
  all = new Visualization(NUM_LEDS, 1, 0, 0, leds);

  //FastLED.setBrightness(32);
  all->setAllCRGB(0x003000);
  FastLED.show();
  delay(1000);

  Serial.println("setup complete");
}

void loop() {
//  all->setAllCRGB(0xFF0004);

  for (uint_fast16_t i = 0; i < NUM_LEDS; i++) {
    uint_fast8_t hue = floor(i / 10);
    hue = (hue % 2) * 64;
    leds[i] = CHSV(hue, SATURATION, VALUE);
  }

  FastLED.show();
  FastLED.delay(1000000);
}
