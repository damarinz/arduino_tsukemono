# arduino_tsukemono
IoT漬物センサー開発


Please install BME280 lib before run.

https://github.com/sparkfun/SparkFun_BME280_Breakout_Board

1. download zip
2. Arduino IDE -> Sketch pulldown menu -> Library -> install Zip Library
3. copy souce and paste to IDE
4. Compile and Run


#### Pin connections
BME280 works on 3.3V. 

```
BME280   Arduino
VDD -- 3.3V
GND -- GND
CSB -- OPEN(unconnected)
SDI -- SDA
SDO -- GND(select 0x76) if you want to use 0x77, please connet to 3.3V
SCK -- SCL
```

MH-Z29B works on 5V

```angular2html
Vin -- 5V
GND -- GND
PWM -- D3
```

- Please remove sensor two pepar seals.
- 3min pre herat




