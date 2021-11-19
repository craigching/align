#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

#include "align.h"

TEST_CASE( "make_seasonality_features is computed correctly", "[make_seasonality_features]" ) {

    std::string left{"HEAGAWGHEE"};
    std::string right{"PAWHEAE"};

    std::cout << "aligning " << left << " and " << right << std::endl;

    auto [leftOut, rightOut] = align2(left, right);

    REQUIRE(leftOut == "AWGHE-E");
    REQUIRE(rightOut == "AW-HEAE");
}