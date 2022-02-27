#include <iostream>

#define ON  true
#define OFF false

class Lamp
{
public:
    void on() {
        // ...
    }
    void off() {
        // ...
    }
};

class Button
{
public:
    Button(Lamp& lamp): mLamp(lamp){}
    void touch() {
        if (mState == ON) {
            mState = OFF;
            mLamp.off();
        }
        else {
            mState = ON;
            mLamp.on();
        }
    }
private:
    Lamp& mLamp;
    bool mState;
};