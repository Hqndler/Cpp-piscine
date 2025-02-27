#include "Base.hpp"

Base::~Base(void){
    return;
}

Base *generate(void){
    Base *p;
    int r = rand() % 3;
    
    if (r == 0){
        p = new A();
        std::cout << "Created a A class" << std::endl;
    }
    else if (r == 1){
        p = new B();
        std::cout << "Created a B class" << std::endl;
    }
    else{
        p = new C();
        std::cout << "Created a C class" << std::endl;
    }
    return p;
}

void identify(Base *p){
    A* a = dynamic_cast<A*>(p);
    B* b = dynamic_cast<B*>(p);
    C* c = dynamic_cast<C*>(p);
    if (a != 0)
        std::cout << p << " is a A pointer" << std::endl;
    else if (b != 0)
        std::cout << p << " is a B pointer" << std::endl;
    else if (c != 0)
        std::cout << p << " is a C pointer" << std::endl;
    else
        std::cout << "Not a recognised pointer" << std::endl;
}

void identify(Base &p){
    bool k = false;
    try{
        A &a = dynamic_cast<A&>(p);
        k = true;
        std::cout << &a << " is a A reference" << std::endl;
    }
    catch (std::exception &e){
    }

    try{
        B &b = dynamic_cast<B&>(p);
        k = true;
        std::cout << &b << " is a B reference" << std::endl;
    }
    catch (std::exception &e){
    }

    try{
        C &c = dynamic_cast<C&>(p);
        k = true;
        std::cout << &c << " is a C reference" << std::endl;
    }
    catch (std::exception &e){
    }
    if (!k)
        std::cout << "Not a recognised reference" << std::endl;
}