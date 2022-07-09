#include <catch.hpp>

#include "TokensAmount.h"

TEST_CASE("TokensAmount Constructors") {
    REQUIRE(TokensAmount() == TokensAmount(0));

    REQUIRE(TokensAmount(100) > TokensAmount(99));

    if (constants::decimal_places_count == 2) {
        REQUIRE(TokensAmount(111) == TokensAmount(1, 11));
        REQUIRE(TokensAmount(1111) != TokensAmount(1, 11));
        REQUIRE(TokensAmount(111) != TokensAmount(11, 11));

        bool exception_caught = false;

        try {
            TokensAmount(11, 111);
        } catch (...) {
            exception_caught = true;
        }

        REQUIRE(exception_caught);
    }

    REQUIRE(std::string(TokensAmount(100)) == std::string("1.00"));
    REQUIRE(std::string(TokensAmount(16900)) == std::string("169.00"));
    REQUIRE(std::string(TokensAmount(69)) == std::string("0.69"));
    REQUIRE(std::string(TokensAmount(9)) == std::string("0.09"));
    REQUIRE(std::string(TokensAmount()) == std::string("0.00"));
}