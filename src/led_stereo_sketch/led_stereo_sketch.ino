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

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  8,
  8,
  PIN,
  NEO_MATRIX_TOP
    + NEO_MATRIX_RIGHT
    + NEO_MATRIX_COLUMNS
    + NEO_MATRIX_PROGRESSIVE,
  NEO_GRB + NEO_KHZ800
);

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

int size = sizeof colors / sizeof colors[0];

int wait = 10;

int crossColor(int startVal, int endVal, int i, int steps) {
  return startVal + (endVal - startVal) * i / steps;
}

void setup() {
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(1);
}

void crossFadeScreen(RGB startColor, RGB endColor, int steps, int wait) {
  for(int i = 0; i <= steps; i++) {
     int r = crossColor(startColor.r, endColor.r, i, steps);
     int g = crossColor(startColor.g, endColor.g, i, steps);
     int b = crossColor(startColor.b, endColor.b, i, steps);

     matrix.fillScreen(matrix.Color(r, g, b));
     matrix.show();
  }
}

void colorWipe(RGB color, uint8_t wait) {
  for(uint16_t row=0; row < 8; row++) {
    for(uint16_t column=0; column < 8; column++) {
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
