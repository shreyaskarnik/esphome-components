# esphome-components

This repo contains a custom esphome component/sensor for the person sensor [SEN-21231](https://www.sparkfun.com/products/21231) from [Useful Sensors](https://usefulsensors.com/)

## Motivation

I wanted to use the person sensor for triggering automations in Home Assistant using ESPHome.
This is a work in progress and I am not very well versed in C++ or interfacing with hardware over I2C.
Huge thank you to [Pete Warden](https://github.com/petewarden) and the Useful Sensors team for their work on the [Person Sensor](https://usefulsensors.com/) and providing example code which makes this custom component possible.

## Testing

I tested the custom component on a ESP32 dev board with the person sensor connected to the I2C bus. With `sda` connected to pin 21 and `scl` connected to pin 22.

## Example

[example](./example.png)

## ESPHome Configuration

```yaml
esphome:
  name: sense
  platform: ESP32
  board: esp32dev
external_components:
  - source:
      type: git
      url: https://github.com/shreyaskarnik/esphome-components
    components: [sen21231]
sensor:
  - platform: sen21231
    name: "Person Sensor"
```
