#include "barebones.h"

void Barebones::drawWatchFace() { 
    int displayHour; 

    display.setFont(&FreeMonoOblique24pt7b);
    display.setCursor(40, 110);

    // Check from config.h if we are using 12/24hr time
    if(HOUR_12_24 == 12) {
      displayHour = ((currentTime.Hour + 11) % 12) + 1;
    } else {
      displayHour = currentTime.Hour;
    }

    if(displayHour < 10) {
        display.print("0");
    }

    display.print(displayHour);

    if(currentTime.Minute < 10) {
      display.print("0");
    }

    display.println(currentTime.Minute);  

    if(SHOW_BATTERY_STATUS) {
      drawBattery(); 
    }
}

void Barebones::drawBattery() {
      int8_t batteryLevel = 0;
      float voltage = getBatteryVoltage();

      if(TEXT_BATTERY_DISPLAY) {    
        display.setCursor(1, 1);
        display.print(voltage);
        display.println("V");
      } else {
        display.drawBitmap(1, 1, battery, 37, 21, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
        display.fillRect(6, 6, 27, BATTERY_SEGMENT_HEIGHT, DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);

        if(voltage > 4.1){
            batteryLevel = 3;
        }
        else if(voltage > 3.95 && voltage <= 4.1){
            batteryLevel = 2;
        }
        else if(voltage > 3.80 && voltage <= 3.95){
            batteryLevel = 1;
        }
        else if(voltage <= 3.80){
            batteryLevel = 0;
        }

        for(int8_t batterySegments = 0; batterySegments < batteryLevel; batterySegments++){
            display.fillRect(6 + (batterySegments * BATTERY_SEGMENT_SPACING), 6, BATTERY_SEGMENT_WIDTH, BATTERY_SEGMENT_HEIGHT, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
        }
      }
}