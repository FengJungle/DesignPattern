/*  header file */

// forward declaration
class PAimpl;

class A
{
public:
    A()
    {
        // initial work
    }
    ~A() {
        // free resource
    }
public:
    void func1(int a, char* b);
    bool isEnabled();
    // other public interface which will exposed outside
private:
    PAimpl* pimpl;
};