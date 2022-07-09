//
// Created by metagigachad on 09/07/22.
//

#pragma once

#include <cstdint>
#include <string>

#include "constants.h"

class TokensAmount {
public:
    explicit TokensAmount(int64_t internal_value = 0);
    explicit TokensAmount(int64_t before_point, int64_t after_point);

    explicit operator std::string() const;

    bool operator <=>(const TokensAmount& other) const;
    bool operator ==(const TokensAmount& other) const;

protected:
    int64_t value_;
};

// TODO: Bad security (Memory limit, etc.) Fix all holes or create something based on long numbers.
