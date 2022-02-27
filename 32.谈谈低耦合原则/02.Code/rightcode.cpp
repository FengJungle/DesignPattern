#include <iostream>

#define ON  true
#define OFF false

class Object
{
    virtual ~Object(){}
    virtual void on() = 0;
    virtual void off() = 0;
};

class Lamp : public Object
{
public:
    void on() override {
        // ...
    }
    void off() override {
        // ...
    }
};

class Button
{
public:
    Button(Object& obj): mObj(obj){}
    void touch() {
        if (mState == ON) {
            mState = OFF;
            mObj.off();
        }
        else {
            mState = ON;
            mObj.on();
        }
    }
private:
    Object* mObj;
    bool mState;
};