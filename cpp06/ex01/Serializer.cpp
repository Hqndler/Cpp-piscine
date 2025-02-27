#include "Serializer.hpp"

Serializer::Serializer(void){
    return;
}

Serializer::~Serializer(void){
    return;
}

Serializer::Serializer(const Serializer &s){
    static_cast<void>(s);
    return;
}

Serializer Serializer::operator=(const Serializer &s){
    static_cast<void>(s);
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}