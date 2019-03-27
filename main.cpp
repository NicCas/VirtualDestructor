// virtual destructor example   base pointer problem
#include<iostream>

class base {
public:
    // constructor
    base()
    {
        std::cout << "Constructing base \n";
    }
    // destructor
    ~base()
    {
        std::cout << "Destructing base \n";
    }
};

class derived : public base {
public:
    derived()
    {
        std::cout << "Constructing derived \n";
    }
    ~derived()
    {
        std::cout << "Destructing derived \n";
    }
};

int main(void)
{
    // Declaration, calls another constructor in it
    //
    derived *d = new derived();

    // pointer of type base
    base *b = d;

    // have only called destructor for b (the base), but there’s still memory being used by d, so it’s a memory leak
    // don’t use base destructor, use derived class destructor
    delete b;
    getchar();
    return 0;
}

