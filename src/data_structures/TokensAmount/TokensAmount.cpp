//
// Created by metagigachad on 09/07/22.
//

#include "TokensAmount.h"

#include <stdexcept>

TokensAmount::operator std::string() const {
    std::string value = std::to_string(value_);

    std::string before_point = value.size() > constants::decimal_places_count ?
            value.substr(0, value.size() - constants::decimal_places_count) :
            "0";

    std::string after_point = value.size() >= constants::decimal_places_count ?
            value.substr(value.size() - constants::decimal_places_count) :
            std::string(constants::decimal_places_count - value.size(), '0') + value;

    return before_point + '.' + after_point;
}

TokensAmount::TokensAmount(int64_t internal_value) : value_(internal_value) {}

TokensAmount::TokensAmount(int64_t before_point, int64_t after_point) {
    for (size_t i = 0; i < constants::decimal_places_count; ++i) {
        before_point *= 10;
    }

    if (constants::decimal_places_count < std::to_string(after_point).size()) {
        throw std::runtime_error("After point value exceeded the limit.");
    }

    for (size_t i = 0; i < constants::decimal_places_count - std::to_string(after_point).size(); ++i) {
        after_point *= 10;
    }

    value_ = before_point + after_point;
}

bool TokensAmount::operator<=>(const TokensAmount &other) const {
    return value_ - other.value_;
}

bool TokensAmount::operator==(const TokensAmount &other) const {
    return value_ == other.value_;
}
