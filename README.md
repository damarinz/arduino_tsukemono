# arduino_tsukemono
IoT漬物センサー開発


#### Pin connection
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

