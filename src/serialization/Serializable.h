//
// Created by inqognitoo on 7/24/22.
//

#ifndef KKTOKEN_CLIENT_KKTOKEN_CLIENT_SERIALIZATION_SERIALIZABLE_H_
#define KKTOKEN_CLIENT_KKTOKEN_CLIENT_SERIALIZATION_SERIALIZABLE_H_

#include <iostream>

class Serializable
{
  public:
    virtual std::istream& operator>>(std::istream& stream) = 0;
    virtual std::ostream& operator<<(std::ostream& stream) = 0;
};

#endif//KKTOKEN_CLIENT_KKTOKEN_CLIENT_SERIALIZATION_SERIALIZABLE_H_
