//
// Created by inqognitoo on 7/24/22.
//

#ifndef KKTOKEN_CLIENT_KKTOKEN_CLIENT_SERIALIZATION_SERIALIZER_H_
#define KKTOKEN_CLIENT_KKTOKEN_CLIENT_SERIALIZATION_SERIALIZER_H_

#include "Serializable.h"

class Serializer
{
  public:
    virtual char* serialize(const Serializable& object);
    virtual Serializable& deserialize(const char* string);
};

#endif//KKTOKEN_CLIENT_KKTOKEN_CLIENT_SERIALIZATION_SERIALIZER_H_
