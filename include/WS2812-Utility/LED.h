#pragma once

#include <WS2812.h>
#include <algorithm>
#include <cmath>

namespace m2d
{
namespace ESP32
{
namespace LED
{
class Strip : public WS2812
{
  public:
    Strip(gpio_num_t gpioNum, uint16_t pixelCount, int channel = RMT_CHANNEL_0)
        : WS2812(gpioNum, pixelCount, channel = RMT_CHANNEL_0)
    {
        _pixelCount = pixelCount;
    }

    uint16_t numberOfPixels()
    {
        return this->_pixelCount;
    };

  protected:
    uint16_t _pixelCount;
};

class Color
{
  private:
    int _red = 0;
    int _green = 0;
    int _blue = 0;
    int _brightness = 0;

  public:
    Color() {}
    Color(int red, int green, int blue, int brightness = 100)
    {
        this->_red = std::min(red, 255);
        this->_green = std::min(green, 255);
        this->_blue = std::min(blue, 255);
        this->_brightness = std::min(brightness, 255);
    }

    int redValue()
    {
        return this->_red;
    }

    int greenValue()
    {
        return this->_green;
    }

    int blueValue()
    {
        return this->_blue;
    }

    int brightness()
    {
        return this->_brightness;
    }

    float brightness_ratio()
    {
        return this->_brightness / 255.0;
    }

    pixel_t pixel_color()
    {
        pixel_t p;
        p.red = this->redValue() * this->brightness_ratio();
        p.green = this->greenValue() * this->brightness_ratio();
        p.blue = this->blueValue() * this->brightness_ratio();

        return p;
    }

    static Color red(int brightness = 255)
    {
        return Color(255, 0, 0, brightness);
    }

    static Color green(int brightness = 255)
    {
        return Color(0, 255, 0, brightness);
    }

    static Color blue(int brightness = 255)
    {
        return Color(0, 0, 255, brightness);
    }

    static Color yellow(int brightness = 255)
    {
        return Color(255, 255, 0, brightness);
    }

    static Color orange(int brightness = 255)
    {
        return Color(255, 127, 0, brightness);
    }

    static Color purple(int brightness = 255)
    {
        return Color(127, 0, 127, brightness);
    }

    static Color indigo(int brightness = 255)
    {
        return Color(0, 127, 255, brightness);
    }

    static Color white(int brightness = 255)
    {
        return Color(255, 255, 255, brightness);
    }

    static Color off()
    {
        return Color(0, 0, 0, 0);
    }
};
} // namespace LED
} // namespace ESP32
} // namespace m2d