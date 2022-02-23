#include "catch.hpp"
#include "Board.h"


TEST_CASE("Test of board"){

    Board board {};

    SECTION("Isinside when is inside."){
        Position pos {2,2};
        REQUIRE(board.isInside(pos) == true);
    }

    SECTION("Isinside when is not inside with a negatif position."){
        Position pos {-3,-1};
        REQUIRE(board.isInside(pos) == false);
    }

    SECTION("Isinside when is not inside with a positif too big position."){
        Position pos {50,64};
        REQUIRE(board.isInside(pos) == false);
    }

    SECTION("isFree when true."){
        Position pos {3,2};
        REQUIRE(board.isFree(pos) == true);
    }

    SECTION("isFree when false with black color."){
        Position pos {0,2};
        board.setPieceColor(PlayerColor::Black ,pos);
        REQUIRE_FALSE(board.isFree(pos) == true);
    }

    SECTION("isFree when false with white color."){
        Position pos {0,2};
        board.setPieceColor(PlayerColor::White ,pos);
        REQUIRE_FALSE(board.isFree(pos) == true);
    }

    SECTION("SetPieceColor of a position with color Black."){
        Position pos {2,2};
        board.setPieceColor(PlayerColor::Black, pos);
        REQUIRE(board.getPiece_(pos).getColor_() == PlayerColor::Black);
    }

    SECTION("SetPieceColor of a position with color White."){
        Position pos {2,2};
        board.setPieceColor(PlayerColor::White, pos);
        REQUIRE(board.getPiece_(pos).getColor_() == PlayerColor::White);
    }

    SECTION("SetPieceColor of a position when false."){
        Position pos {2,2};
        board.setPieceColor(PlayerColor::White, pos);
        REQUIRE_FALSE(board.getPiece_(pos).getColor_() != PlayerColor::White);
    }

    SECTION("isMyOwn when true with black color."){
        Position pos {2,1};
        board.setPieceColor(PlayerColor::Black, pos);
        REQUIRE(board.isMyOwn(pos, PlayerColor::Black));
    }

    SECTION("isMyOwn when true with white color."){
        Position pos {2,1};
        board.setPieceColor(PlayerColor::White, pos);
        REQUIRE(board.isMyOwn(pos, PlayerColor::White));
    }

    SECTION("isMyOwn when is false."){
        Position pos {2,1};
        board.setPieceColor(PlayerColor::White, pos);
        REQUIRE_FALSE(board.isMyOwn(pos, PlayerColor::Black));
    }

    SECTION("isMyOwn when is empty."){
        Position pos {2,1};
        board.setPieceColor(PlayerColor::Empty, pos);
        REQUIRE_FALSE(board.isMyOwn(pos, PlayerColor::Black));
    }
}
