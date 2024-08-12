#include "main.h"

// This is just a stub file to make the project compile. This also
// means that this repo will work with the Arduino IDE as well.
// Note that the setup() and loop() functions are defined in the
// src/main.h and src/main.cpp files.
//
//
// Footguns:
//   The *.ino file has a special feature that allows functions to be defined
//   in any order. This is not the case with *.cpp files. You will either need
//   to define the functions in the correct order or forward declare your functions
//   in the *.h or *.cpp files.
// Example ino:
//   void setup() {...}
//   void a() { b();}  // legal in *.ino files, but not in *.cpp files.
//   void b() { Serial.println("Hello World");}
//   void loop() {a();}
//
// Notice that b() is defined AFTER a(). In a *.ino file this is allowed.
// However in a *.cpp file this will generate a compile error. Instead you'll need
// to do this:
// Example main.cpp:
//   void setup() {...}
//   void b();  // forward declare.
//   void a() { b();}  // now this can be used here.
//   void b() { Serial.println("Hello World");}
//   void loop() {a();}