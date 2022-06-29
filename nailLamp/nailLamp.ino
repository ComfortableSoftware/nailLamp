

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For an ESP32 
#define TFT_CS 15
#define TFT_DC 27
#define TFT_MOSI 23
#define TFT_CLK 18
#define TFT_RST 4
#define TFT_MISO 19


/*
    - All setup on screen.
    - PWM/brightness of UV/LED.
    - PWM brightness of backlight on display.
    - Stop on removal of hand from the unit.
    - Timer options.
    - Upgrade to bigger touch screen and STM32F103C8T6.

    right to left on the display side
    T-IRQ
    T-DO
    T-DIN
    T_CS
    T_CLK
    SDO/MISO
    LED
    SCK
    SDI/MOSI
    DC
    RESET
    CS
    GND
    VCC

*/

void setup()
{
  // put your setup code here, to run once:

}

void loop()
{
  // put your main code here, to run repeatedly:

}
