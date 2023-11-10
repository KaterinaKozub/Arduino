#include <Adafruit_NeoPixel.h>

#ifdef AVR
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        5
#define NUMPIXELS 32
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 10 // Reduce delay for smoother transitions

void setup() {
#if defined(AVR_ATtiny85) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
}

void loop() {
  for(int i = 0; i < 360; i++) {
    for(int j = 0; j < NUMPIXELS; j++) {
      // Adding an offset to create a rainbow effect
      uint32_t color = pixels.ColorHSV((i + j * 10) * 65536L / 360, 255, 255);
      pixels.setPixelColor(j, color);
    }
    pixels.show();
    delay(DELAYVAL);
  }
}