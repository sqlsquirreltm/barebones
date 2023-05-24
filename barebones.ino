// Barebones watchface for the Watchy
// This is mostly bits and pieces taken from the 7SEG
// If you don't like the battery display you can comment on the call on line 28 of barebones.cpp
#include "barebones.h"
#include "settings.h"

Barebones b(settings); 

void setup() {
  b.init(); 
}

void loop() {

}
