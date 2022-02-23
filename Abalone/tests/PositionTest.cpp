#include "catch.hpp"
#include "Position.h"

TEST_CASE("Test of a position."){

    // Pas tester
    // posPieceToIndice
    // posIndicetoPiece
    SECTION("Operator+ when positive position."){
        Position a {2,2};
        Position b = {1,1};
        Position result = a + b;
        Position expectedResult {3,3};
        REQUIRE(result.equals(expectedResult));
    }

    SECTION("Operator+ when negative position."){
        Position a {4,5};
        Position b = {-2,-1};
        Position result = a + b;
        Position expectedResult {2,4};
        REQUIRE(result.equals(expectedResult));
    }

    SECTION("Next position in right."){
        Position a {2,2};
        Position result = a.next(Direction::RIGHT);
        Position expectedResult {2,3};
        REQUIRE(result.equals(expectedResult));
    }

    SECTION("Next position in left."){
        Position a {2,2};
        Position result = a.next(Direction::LEFT);
        Position expectedResult {2,1};
        REQUIRE(result.equals(expectedResult));
    }

    SECTION("Next position in upright."){
        Position a {2,2};
        Position result = a.next(Direction::UPRIGHT);
        Position expectedResult {1,3};
        REQUIRE(result.equals(expectedResult));
    }

    SECTION("Next position in upleft."){
        Position a {2,2};
        Position result = a.next(Direction::UPLEFT);
        Position expectedResult {1,2};
        REQUIRE(result.equals(expectedResult));
    }

    SECTION("Next position in downleft."){
        Position a {2,2};
        Position result = a.next(Direction::DOWNLEFT);
        Position expectedResult {3,1};
        REQUIRE(result.equals(expectedResult));
    }

    SECTION("Next position in downright."){
        Position a {2,2};
        Position result = a.next(Direction::DOWNRIGHT);
        Position expectedResult {3,2};
        REQUIRE(result.equals(expectedResult));
    }

    SECTION("Equals when true."){
        Position a {1,1};
        Position b {1,1};
        REQUIRE(a.equals(b) == true);
    }

    SECTION("Equals when false."){
        Position a {1,1};
        Position b {4,1};
        REQUIRE(a.equals(b) == false);
    }

    SECTION("Position of a direction, right."){
        Position expectedResult {0,1};
        Position result = Position::positionOfDirection(Direction::RIGHT);
        REQUIRE(expectedResult.equals(result));
    }

    SECTION("Position of a direction, left."){
        Position expectedResult {0,-1};
        Position result = Position::positionOfDirection(Direction::LEFT);
        REQUIRE(expectedResult.equals(result));
    }

    SECTION("Position of a direction, downleft."){
        Position expectedResult {1,-1};
        Position result = Position::positionOfDirection(Direction::DOWNLEFT);
        REQUIRE(expectedResult.equals(result));
    }

    SECTION("Position of a direction, downright."){
        Position expectedResult {1,0};
        Position result = Position::positionOfDirection(Direction::DOWNRIGHT);
        REQUIRE(expectedResult.equals(result));
    }

    SECTION("Position of a direction, upleft."){
        Position expectedResult {-1,0};
        Position result = Position::positionOfDirection(Direction::UPLEFT);
        REQUIRE(expectedResult.equals(result));
    }

    SECTION("Position of a direction, upright."){
        Position expectedResult {-1,1};
        Position result = Position::positionOfDirection(Direction::UPRIGHT);
        REQUIRE(expectedResult.equals(result));
    }

    SECTION("Position of a direction when false."){
        //downleft
        Position expectedResult {1,-1};
        Position result = Position::positionOfDirection(Direction::DOWNRIGHT);
        REQUIRE(expectedResult.equals(result) == false);
    }
}
