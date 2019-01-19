#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

// 7 TX 8 RX
SoftwareSerial BT(8, 7);

/* 40 LEDs on DPIN 11 */
Adafruit_NeoPixel strip = Adafruit_NeoPixel(40, 11, NEO_GRB + NEO_KHZ800);

void setup() {
    Serial.begin(9600);
    // while ( ! Serial) {
    //     ; // wait for serial port to connect. Needed for native USB port only
    // }

    Serial.println("Initialized serial");

    BT.begin(115200);
    Serial.println("Initialized bt");
    // put your setup code here, to run once:
}

void loop() {

    if (BT.available()) {
        Serial.write(BT.read());
    }
    if (Serial.available()) {
        BT.write(Serial.read());
    }
}
