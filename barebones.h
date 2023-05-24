#ifndef _BAREBONES_H_
#define _BAREBONES_H_

#include <Watchy.h>
#include <Fonts/FreeMonoOblique24pt7b.h>
#include "icons.h"

#define SHOW_BATTERY_STATUS true    // True: show battery status on watch face
#define TEXT_BATTERY_DISPLAY false  // True: show graphic battery

#define DARKMODE true

const uint8_t BATTERY_SEGMENT_WIDTH = 7;
const uint8_t BATTERY_SEGMENT_HEIGHT = 11;
const uint8_t BATTERY_SEGMENT_SPACING = 9;

class Barebones : public Watchy{ 
    using Watchy::Watchy;
    public:
        void drawWatchFace();
        void drawBattery();
};

#endif