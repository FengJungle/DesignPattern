#include "demo.h"
// include other necessary files
#include ....

class PAimpl
{
public:
    void func1(int a, char* b) 
    {
        // implementation
    }
    bool isEnabled()
    {
        // implementation
        return true;
    }
};

void A::func1(int a, char* b)
{
    pimpl->func1(a, b);
}

bool A::isEnabled()
{
    return pimpl->isEnabled();
}