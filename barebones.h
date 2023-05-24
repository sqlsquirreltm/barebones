#ifndef _BAREBONES_H_
#define _BAREBONES_H_

#include <Watchy.h>
#include <Fonts/FreeMonoOblique24pt7b.h>
#include "icons.h"

class Barebones : public Watchy{ 
    using Watchy::Watchy;
    public:
        //Barebones(const watchySettings& s) : Watchy(s) {}
        void drawWatchFace();
        void drawBattery();
};

#endif