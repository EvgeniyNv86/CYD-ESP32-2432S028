# CYD — Cheap Yellow Display Library

Библиотека для **ESP32-2432S028** (он же CYD — Cheap Yellow Display).

## Характеристики

- **Дисплей:** ILI9341 240×320, SPI (HSPI_HOST)
- **Тач:** XPT2046, bit-bang через LovyanGFX
- **RGB-светодиод:** пины 4 (R), 16 (G), 17 (B) — active LOW
- **Подсветка:** пин 21

## Установка

1. Установите библиотеку **LovyanGFX** через Arduino Library Manager
2. Скачайте этот репозиторий и положите папку `CYD` в `Documents/Arduino/libraries/`
3. Перезапустите Arduino IDE

## Быстрый старт

```cpp
#include <CYD.h>

CYD tft;

void setup() {
  tft.init();
  tft.setRotation(0);
  CYD::initLED();
  tft.setBrightness(128);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Hello CYD!");
}

void loop() {
  uint16_t x, y;
  if (tft.getTouch(&x, &y)) {
    tft.fillCircle(x, y, 4, TFT_RED);
    delay(100);
  }
}
```

## API

| Метод | Описание |
|---|---|
| `tft.init()` | Инициализация дисплея |
| `tft.setRotation(0..3)` | Поворот экрана |
| `tft.getTouch(&x, &y)` | Чтение координат тача |
| `CYD::initLED()` | Инициализация RGB-светодиода |
| `CYD::setLED(r, g, b)` | Управление RGB (bool) |
| `tft.setBrightness(0..255)` | Подсветка |

Все методы LovyanGFX (`fillScreen`, `drawRect`, `setTextSize`, и т.д.) также доступны.

## Пины

| Назначение | Пин |
|---|---|
| Display SCK | 14 |
| Display MOSI | 13 |
| Display MISO | 12 |
| Display CS | 15 |
| Display DC | 2 |
| Touch SCK | 25 |
| Touch MOSI | 32 |
| Touch MISO | 39 |
| Touch CS | 33 |
| Touch IRQ | 36 |
| LED Red | 4 |
| LED Green | 16 |
| LED Blue | 17 |
| Backlight | 21 |

## Автор

Evgeniy Shitov

## Лицензия

MIT
