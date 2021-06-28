/**
 * Code for patterns on LED grid
 */

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif

#define PIN 6
#define LENGTH 8
#define HEIGHT 8

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  LENGTH,
  HEIGHT,
  PIN,
  NEO_MATRIX_TOP
    + NEO_MATRIX_RIGHT
    + NEO_MATRIX_COLUMNS
    + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800
);

// define a structure RGB with values r, g, and b
struct RGB {
  byte r;
  byte g;
  byte b;
};

// rgb values of common colors
RGB white = {255, 255, 255};
RGB red = {255, 0, 0};
RGB green = {0, 255, 0};
RGB blue = {0, 0, 255};
RGB yellow = {255, 255, 0};
RGB purple = {255, 200, 255};
RGB orange = {255, 128, 0};

RGB colors[] = {
  white,
  red,
  green,
  blue,
  yellow,
  purple,
  orange,
};

// size of array of colors
int size = sizeof colors / sizeof colors[0];
int wait = 10;

void setup() {
  matrix.begin();
  matrix.setBrightness(1);
}

// This function is by Brent Schooley
void colorWipe(RGB color, uint8_t wait) {
  for(uint16_t row=0; row < LENGTH; row++) {
    for(uint16_t column=0; column < HEIGHT; column++) {
      matrix.drawPixel(column, row, matrix.Color(color.r, color.g, color.b));
      matrix.show();
      delay(wait);
    }
  }
}

void loop() {
  for (int i = 0; i < size; i++) {
    colorWipe(colors[i], wait);
  }
}
