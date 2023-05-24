#include "barebones.h"

#define DARKMODE true

const uint8_t BATTERY_SEGMENT_WIDTH = 7;
const uint8_t BATTERY_SEGMENT_HEIGHT = 11;
const uint8_t BATTERY_SEGMENT_SPACING = 9;

void Barebones::drawWatchFace() { 
    display.setFont(&FreeMonoOblique24pt7b);
    display.setCursor(40, 110);
    int displayHour;
    if(HOUR_12_24==12){
      displayHour = ((currentTime.Hour+11)%12)+1;
    } else {
      displayHour = currentTime.Hour;
    }
    if(displayHour < 10){
        display.print("0");
    }
    display.print(displayHour);
    if(currentTime.Minute < 10){
      display.print("0");
    }  
    display.println(currentTime.Minute);  

    // If you want even more barenones comment this out, You can still view battery life in the about menu
    drawBattery(); 
}

// Taken from 7SEG watch face
void Barebones::drawBattery() {
      display.drawBitmap(1, 1, battery, 37, 21, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
      display.fillRect(6, 6, 27, BATTERY_SEGMENT_HEIGHT, DARKMODE ? GxEPD_BLACK : GxEPD_WHITE);//clear battery segments
      int8_t batteryLevel = 0;
      float VBAT = getBatteryVoltage();
      if(VBAT > 4.1){
          batteryLevel = 3;
      }
      else if(VBAT > 3.95 && VBAT <= 4.1){
          batteryLevel = 2;
      }
      else if(VBAT > 3.80 && VBAT <= 3.95){
          batteryLevel = 1;
      }
      else if(VBAT <= 3.80){
          batteryLevel = 0;
      }

      for(int8_t batterySegments = 0; batterySegments < batteryLevel; batterySegments++){
          display.fillRect(6 + (batterySegments * BATTERY_SEGMENT_SPACING), 6, BATTERY_SEGMENT_WIDTH, BATTERY_SEGMENT_HEIGHT, DARKMODE ? GxEPD_WHITE : GxEPD_BLACK);
      }
}