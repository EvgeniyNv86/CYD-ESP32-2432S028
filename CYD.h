#pragma once

#include <LovyanGFX.hpp>

// ─── CYD (ESP32-2432S028) — Cheap Yellow Display ───
// Display: ILI9341 240x320 SPI (HSPI)
// Touch:  XPT2046 bit-bang (LovyanGFX internal)
// LED:    RGB on pins 4(R), 16(G), 17(B) — active LOW
// Backlight: pin 21 (via transistor, active HIGH)

class CYD : public lgfx::LGFX_Device {
  lgfx::Bus_SPI      _bus;
  lgfx::Panel_ILI9341 _panel;
  lgfx::Touch_XPT2046 _touch;

public:
  CYD() {
    auto bus_cfg = _bus.config();
    bus_cfg.spi_host    = HSPI_HOST;
    bus_cfg.spi_mode    = 0;
    bus_cfg.freq_write  = 40000000;
    bus_cfg.freq_read   = 16000000;
    bus_cfg.dma_channel = 1;
    bus_cfg.pin_sclk    = 14;
    bus_cfg.pin_mosi    = 13;
    bus_cfg.pin_miso    = 12;
    bus_cfg.pin_dc      = 2;
    _bus.config(bus_cfg);
    _panel.setBus(&_bus);

    auto panel_cfg = _panel.config();
    panel_cfg.pin_cs        = 15;
    panel_cfg.pin_rst       = -1;
    panel_cfg.panel_width   = 240;
    panel_cfg.panel_height  = 320;
    panel_cfg.offset_x      = 0;
    panel_cfg.offset_y      = 0;
    panel_cfg.offset_rotation = 2;
    panel_cfg.dummy_read_pixel = 8;
    panel_cfg.readable    = true;
    panel_cfg.invert      = true;
    panel_cfg.serial_cfg  = 0;
    panel_cfg.dlen_16bit  = false;
    panel_cfg.bus_shared  = false;
    _panel.config(panel_cfg);

    auto touch_cfg = _touch.config();
    touch_cfg.x_min      = 200;
    touch_cfg.x_max      = 3700;
    touch_cfg.y_min      = 3700;
    touch_cfg.y_max      = 200;
    touch_cfg.pin_int    = 36;
    touch_cfg.bus_shared = false;
    touch_cfg.offset_rotation = 0;
    touch_cfg.spi_host   = -1;
    touch_cfg.freq       = 1000000;
    touch_cfg.pin_sclk   = 25;
    touch_cfg.pin_mosi   = 32;
    touch_cfg.pin_miso   = 39;
    touch_cfg.pin_cs     = 33;
    _touch.config(touch_cfg);
    _panel.setTouch(&_touch);

    setPanel(&_panel);
  }

  // ─── RGB LED (active LOW) ───
  static constexpr uint8_t LED_R = 4;
  static constexpr uint8_t LED_G = 16;
  static constexpr uint8_t LED_B = 17;

  static void initLED() {
    pinMode(LED_R, OUTPUT); digitalWrite(LED_R, HIGH);
    pinMode(LED_G, OUTPUT); digitalWrite(LED_G, HIGH);
    pinMode(LED_B, OUTPUT); digitalWrite(LED_B, HIGH);
  }

  static void setLED(bool r, bool g, bool b) {
    digitalWrite(LED_R, !r);
    digitalWrite(LED_G, !g);
    digitalWrite(LED_B, !b);
  }

  // ─── Backlight ───
  static constexpr uint8_t BL_PIN = 21;

  void setBrightness(uint8_t level) {
    if (level == 0) {
      digitalWrite(BL_PIN, LOW);
    } else {
      pinMode(BL_PIN, OUTPUT);
      digitalWrite(BL_PIN, HIGH);
    }
  }
};
