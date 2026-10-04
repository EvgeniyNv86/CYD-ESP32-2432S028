#include <CYD.h>

CYD tft;

void setup() {
  Serial.begin(115200);
  delay(500);

  tft.init();
  tft.setRotation(0);  // портрет
  CYD::initLED();
  tft.setBrightness(128);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Touch Test");
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.setTextSize(1);
  tft.setCursor(10, 40);
  tft.println("by Evgeniy - Shitov");
  tft.println("Touch the screen!");
  tft.drawRect(0, 0, tft.width(), tft.height(), TFT_WHITE);

  Serial.println("Ready.");
}

void loop() {
  uint16_t x, y;
  if (tft.getTouch(&x, &y)) {
    tft.fillCircle(x, y, 4, TFT_RED);
    Serial.printf("x=%u y=%u\n", x, y);
    delay(100);
  }
}
