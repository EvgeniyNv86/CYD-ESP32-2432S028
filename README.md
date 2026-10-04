# 💛 CYD — ESP32-2432S028 Library

> Библиотека для **Cheap Yellow Display** (ESP32-2432S028) — дисплей ILI9341 + тач XPT2046 через LovyanGFX

![Platform](https://img.shields.io/badge/platform-ESP32-orange)
![Display](https://img.shields.io/badge/display-ILI9341-blue)
![Touch](https://img.shields.io/badge/touch-XPT2046-green)
![License](https://img.shields.io/badge/license-MIT-yellow)

---

## ✨ Возможности

| Функция | Описание |
|---------|---------|
| 🖥️ **Дисплей** | ILI9341 320×240, SPI, через LovyanGFX |
| 👆 **Тач** | XPT2046, bit-bang, калибровка при старте |
| 💡 **Подсветка** | Управление яркостью (PWM) |
| 🌈 **RGB-светодиод** | Встроенный, на пинах 4/16/17 |
| 🔄 **setRotation** | Поддержка всех 4 ориентаций экрана |

---

## 🔧 Установка

1. Скачайте репозиторий (Clone or Download ZIP)
2. Поместите папку `CYD` в `Documents/Arduino/libraries/`
3. Установите зависимости:
   - [LovyanGFX](https://github.com/lovyan03/LovyanGFX)
4. Перезапустите Arduino IDE

---

## 📋 Пины платы

| Компонент | Пин ESP32 |
|-----------|-----------|
| **Дисплей SPI MOSI** | GPIO 13 |
| **Дисплей SPI MISO** | GPIO 12 |
| **Дисплей SPI SCK** | GPIO 14 |
| **Дисплей CS** | GPIO 15 |
| **Дисплей DC** | GPIO 2 |
| **Дисплей RST** | GPIO -1 |
| **Подсветка** | GPIO 21 |
| **Тач CS** | GPIO 33 |
| **Тач IRQ** | GPIO 36 |
| **Тач SPI MOSI** | GPIO 32 |
| **Тач SPI MISO** | GPIO 39 |
| **Тач SPI SCK** | GPIO 25 |
| **RGB LED (R)** | GPIO 4 |
| **RGB LED (G)** | GPIO 16 |
| **RGB LED (B)** | GPIO 17 |

---

## 🚀 Быстрый старт

```cpp
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
```

---

## 📚 API

| Метод | Описание |
|------|----------|
| `tft.init()` | Инициализация дисплея |
| `tft.setRotation(n)` | Поворот экрана (0–3) |
| `tft.setBrightness(0–255)` | Яркость подсветки |
| `CYD::initLED()` | Инициализация RGB-светодиода |
| `CYD::setLED(r, g, b)` | Цвет RGB (0–255 каждый) |
| `tft.getTouch(&x, &y)` | Чтение координат тача |
| `tft.calibrateTouch()` | Калибровка тача (4 точки) |

---

## ⚙️ Технические детали

- Тач работает через **bit-bang SPI** (`spi_host = -1`) — не зависит от шины дисплея
- Y-ось инвертирована (`y_min=3700, y_max=200`) — особенность XPT2046 на этой плате
- Калибровочные значения можно вшить в `CYD.h` после первой калибровки

---

## 📸 Плата

<img src="https://raw.githubusercontent.com/EvgeniyNv86/CYD-ESP32-2432S028/main/docs/cyd_board.jpg" width="400" alt="ESP32-2432S028" />

*ESP32-2432S028 — Cheap Yellow Display*

---

## 📄 Лицензия

MIT — используйте свободно

---

<p align="center">Made with ❤️ by <b>Evgeniy Shitov</b></p>
