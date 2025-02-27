#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data{
    int key;
    int val;
};

class Serializer{

    private:
        Serializer(void);
        Serializer(const Serializer &s);
        Serializer operator=(const Serializer &s);

    public:
        virtual ~Serializer(void);

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif