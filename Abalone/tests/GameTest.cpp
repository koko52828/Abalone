#include "catch.hpp"
#include "Game.h"

TEST_CASE("Test of game"){

    Game game{};

    SECTION("SwapPlayer when true."){
       game.swapPlayer();
       REQUIRE((game.getCurrent_().getColor_() == PlayerColor::White
                && game.getOpponent_().getColor_() == PlayerColor::Black) == true);
    }

    SECTION("SwapPlayer when false."){
       game.swapPlayer();
       REQUIRE_FALSE((game.getCurrent_().getColor_() == PlayerColor::Black
                && game.getOpponent_().getColor_() == PlayerColor::White) == true);
    }

    SECTION("nbrOfCurrentPiece when true for black (basic initialization)."){
        game.initialize();
        int result = game.nbrOfCurrentPiece(game.getCurrent_());
        int expectedResult = 14;
        REQUIRE(result == expectedResult);
    }

    SECTION("nbrOfCurrentPiece when true for white (basic initialization)."){
        game.initialize();
        int result = game.nbrOfCurrentPiece(game.getOpponent_());
        int expectedResult = 14;
        REQUIRE(result == expectedResult);
    }

    SECTION("nbrOfCurrentPiece when false because expected more pieces (black color) (basic initialization)."){
        game.initialize();
        int result = game.nbrOfCurrentPiece(game.getCurrent_());
        int expectedResult = 15;
        REQUIRE_FALSE(result == expectedResult);
    }

    SECTION("nbrOfCurrentPiece when false because expected more pieces (white color) (basic initialization)."){
        game.initialize();
        int result = game.nbrOfCurrentPiece(game.getOpponent_());
        int expectedResult = 15;
        REQUIRE_FALSE(result == expectedResult);
    }

    SECTION("nbrOfCurrentPiece when false because expected less pieces (black color) (basic initialization)."){
        game.initialize();
        int result = game.nbrOfCurrentPiece(game.getCurrent_());
        int expectedResult = 13;
        REQUIRE_FALSE(result == expectedResult);
    }

    SECTION("nbrOfCurrentPiece when false because expected less pieces (white color) (basic initialization)."){
        game.initialize();
        int result = game.nbrOfCurrentPiece(game.getOpponent_());
        int expectedResult = 13;
        REQUIRE_FALSE(result == expectedResult);
    }

    SECTION("canPlay with a simple one case arrow movement(upleft) when true."){
        game.initialize();
        Position begin {7,0};
        Position end {6,0};
        REQUIRE(game.canPlay(begin, end));
    }

    SECTION("canPlay with a simple one case arrow movement(upright) when true."){
        game.initialize();
        Position begin {7,0};
        Position end {6,1};
        REQUIRE(game.canPlay(begin, end));
    }

    SECTION("canPlay with a simple one case arrow movement(downleft) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {1,3};
        Position end {2,2};
        REQUIRE(game.canPlay(begin, end));
    }

    SECTION("canPlay with a simple one case arrow movement(downright) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {1,3};
        Position end {2,3};
        REQUIRE(game.canPlay(begin, end));
    }

    /*SECTION("canPlay with a two case arrow movement(upleft) when true."){
        game.initialize();
        Position begin {8,0};
        Position end {6,0};
        REQUIRE(game.canPlay(begin, end));
    }*/

    SECTION("canPlay with a simple one case on line movement(right) when true."){
        game.initialize();
        Position begin {6,4};
        Position end {6,5};
        REQUIRE(game.canPlay(begin, end));
    }

    SECTION("canPlay with a two case on line movement(right) when true."){
        game.initialize();
        Position begin {6,3};
        Position end {6,5};
        REQUIRE(game.canPlay(begin, end));
    }

    SECTION("canPlay with a three case on line movement(right) when true."){
        game.initialize();
        Position begin {6,2};
        Position end {6,5};
        REQUIRE(game.canPlay(begin, end));
    }

    SECTION("canPlay with a simple one case on line movement(left) when true."){
        game.initialize();
        Position begin {6,2};
        Position end {6,1};
        REQUIRE(game.canPlay(begin, end));
    }

    SECTION("canPlay with a two case on line movement(left) when true."){
        game.initialize();
        Position begin {6,3};
        Position end {6,1};
        REQUIRE(game.canPlay(begin, end));
    }

    SECTION("canPlay with a three case on line movement(left) when true."){
        game.initialize();
        Position begin {6,4};
        Position end {6,1};
        REQUIRE(game.canPlay(begin, end));
    }

    //PLAY
    SECTION("play with a simple one case arrow movement(upleft) when true."){
        game.initialize();
        Position begin {7,0};
        Position end {6,0};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.getX_()][begin.getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.getX_()][end.getY_()].getColor_() ==PlayerColor::Black;;
        REQUIRE((a && b) == true);
    }

    SECTION("play with a simple one case arrow movement(upright) when true."){
        game.initialize();
        Position begin {7,0};
        Position end {6,1};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.getX_()][begin.getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.getX_()][end.getY_()].getColor_() ==PlayerColor::Black;;
        REQUIRE((a && b) == true);
    }

    SECTION("play with a simple one case arrow movement(downleft) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {1,3};
        Position end {2,2};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.posPieceToIndice().getX_()][begin.posPieceToIndice().getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.posPieceToIndice().getX_()][end.posPieceToIndice().getY_()].getColor_() ==PlayerColor::White;
        REQUIRE((a && b) == true);
    }

    SECTION("play with a simple one case arrow movement(downright) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {1,3};
        Position end {2,3};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.posPieceToIndice().getX_()][begin.posPieceToIndice().getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.posPieceToIndice().getX_()][end.posPieceToIndice().getY_()].getColor_() ==PlayerColor::White;
        REQUIRE((a && b) == true);
    }

    SECTION("play with a simple one case line movement(left) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {2,4};
        Position end {2,3};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.posPieceToIndice().getX_()][begin.posPieceToIndice().getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.posPieceToIndice().getX_()][end.posPieceToIndice().getY_()].getColor_() ==PlayerColor::White;
        REQUIRE((a && b) == true);
    }

    SECTION("play with a simple one case line movement(right) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {2,6};
        Position end {2,7};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.posPieceToIndice().getX_()][begin.posPieceToIndice().getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.posPieceToIndice().getX_()][end.posPieceToIndice().getY_()].getColor_() ==PlayerColor::White;
        REQUIRE((a && b) == true);
    }

    SECTION("play with 2 case line movement(right) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {2,5};
        Position end {2,7};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.posPieceToIndice().getX_()][begin.posPieceToIndice().getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.posPieceToIndice().getX_()][end.posPieceToIndice().getY_()].getColor_() ==PlayerColor::White;
        REQUIRE((a && b) == true);
    }

    SECTION("play with 3 case line movement(right) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {2,4};
        Position end {2,7};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.posPieceToIndice().getX_()][begin.posPieceToIndice().getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.posPieceToIndice().getX_()][end.posPieceToIndice().getY_()].getColor_() ==PlayerColor::White;
        REQUIRE((a && b) == true);
    }

    SECTION("play with 2 case line movement(left) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {2,5};
        Position end {2,3};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.posPieceToIndice().getX_()][begin.posPieceToIndice().getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.posPieceToIndice().getX_()][end.posPieceToIndice().getY_()].getColor_() ==PlayerColor::White;
        REQUIRE((a && b) == true);
    }

    SECTION("play with 3 case line movement(left) when true."){
        game.initialize();
        game.swapPlayer();
        Position begin {2,6};
        Position end {2,3};
        game.play(begin, end);
        bool a = game.getBoard_()[begin.posPieceToIndice().getX_()][begin.posPieceToIndice().getY_()].getColor_() ==PlayerColor::Empty;
        bool b = game.getBoard_()[end.posPieceToIndice().getX_()][end.posPieceToIndice().getY_()].getColor_() ==PlayerColor::White;
        REQUIRE((a && b) == true);
    }

    SECTION("isMyOwn when is true with black."){
        game.initialize();
        Position pos {7,0};
        REQUIRE(game.isMyOwnGame(pos));
    }

    SECTION("isMyOwn when is true with white."){
        game.initialize();
        game.swapPlayer();
        Position pos {0,0};
        REQUIRE(game.isMyOwnGame(pos));
    }

    SECTION("isMyOwn when is false with an empty position."){
        game.initialize();
        Position pos {4,3};
        REQUIRE_FALSE(game.isMyOwnGame(pos));
    }

    SECTION("isInsideGame when is true."){
        Position pos {0,2};
        REQUIRE(game.isInsideGame(pos));
    }

    SECTION("goodDirection true when right direction."){
        Position a {0,0};
        Position b {0,1};
        REQUIRE(game.goodDirection(a, b) == Direction::RIGHT);
    }

    SECTION("goodDirection true when left direction."){
        Position a {0,1};
        Position b {0,0};
        REQUIRE(game.goodDirection(a, b) == Direction::LEFT);
    }

    SECTION("goodDirection true when downright direction."){
        Position a {0,1};
        Position b {1,1};
        REQUIRE(game.goodDirection(a, b) == Direction::DOWNRIGHT);
    }

    SECTION("goodDirection true when downleft direction."){
        Position a {0,1};
        Position b {1,0};
        REQUIRE(game.goodDirection(a, b) == Direction::DOWNLEFT);
    }

    SECTION("goodDirection true when upright direction."){
        Position a {1,1};
        Position b {0,2};
        REQUIRE(game.goodDirection(a, b) == Direction::UPRIGHT);
    }

    SECTION("goodDirection true when upleft direction."){
        Position a {1,1};
        Position b {0,1};
        REQUIRE(game.goodDirection(a, b) == Direction::UPLEFT);
    }

    SECTION("isOver when false because both players have their pieces."){
        game.initialize();
        REQUIRE(game.isOver() == false);
    }

    SECTION("isOver test when true and black player win."){
        game.initialize();
        game.play(Position{6,2}, Position{5,2});
        game.play(Position{5,2}, Position{4,2});
        game.play(Position{4,2}, Position{3,2});
        game.play(Position{3,2}, Position{2,2});
        game.play(Position{2,2}, Position{1,3});
        game.play(Position{1,3}, Position{0,4});
        game.play(Position{0,4}, Position{0,5});
        game.play(Position{0,5}, Position{0,6});
        game.play(Position{0,6}, Position{0,7});
        game.play(Position{0,7}, Position{0,8});
        REQUIRE(game.isOver() == true);
    }

    SECTION("isOver test when true and white player win."){
        game.initialize();
        game.swapPlayer();
        game.play(Position{2,4}, Position{3,3});
        game.play(Position{3,3}, Position{4,2});
        game.play(Position{4,2}, Position{5,1});
        game.play(Position{5,1}, Position{6,0});
        game.play(Position{6,0}, Position{7,0});
        game.play(Position{7,0}, Position{8,0});
        game.play(Position{8,0}, Position{8,1});
        game.play(Position{8,1}, Position{8,2});
        game.play(Position{8,2}, Position{8,3});
        game.play(Position{8,3}, Position{8,4});
        REQUIRE(game.isOver() == true);
    }

    SECTION("sumito test when 1v1 give false."){
        game.play(Position(6,2), Position{5,2});
        game.play(Position(5,2), Position{4,2});
        game.swapPlayer();
        game.play(Position{2,4}, Position{3,3});
        REQUIRE_FALSE(game.sumito(Position{3,3}, Direction::DOWNRIGHT));
    }

    SECTION("sumito test when 2v2 give false."){
        game.play(Position(6,2), Position{5,2});
        game.play(Position(5,2), Position{4,2});
        game.play(Position(7,1), Position{6,1});
        game.play(Position(6,1), Position{5,1});
        game.swapPlayer();
        game.play(Position{2,4}, Position{3,3});
        game.play(Position{1,5}, Position{2,4});
        REQUIRE_FALSE(game.sumito(Position{5,1}, Direction::UPRIGHT));
    }

    SECTION("sumito test when 2v2 give false."){
        game.play(Position(6,2), Position{5,2});
        game.play(Position(5,2), Position{4,2});
        game.play(Position(7,1), Position{6,1});
        game.play(Position(6,1), Position{5,1});
        game.play(Position(7,0), Position{6,0});
        game.swapPlayer();
        game.play(Position{2,4}, Position{3,3});
        game.play(Position{1,5}, Position{2,4});
        game.play(Position{0,6}, Position{1,5});
        REQUIRE_FALSE(game.sumito(Position{6,0}, Direction::UPRIGHT));
    }

    SECTION("sumito test when 2v1 give true."){
        game.play(Position(6,2), Position{5,2});
        game.play(Position(5,2), Position{4,2});
        game.play(Position(7,1), Position{6,1});
        game.play(Position(6,1), Position{5,1});
        game.swapPlayer();
        game.play(Position{2,4}, Position{3,3});
        game.swapPlayer();
        REQUIRE(game.sumito(Position{5,1}, Direction::UPRIGHT));
    }

    SECTION("sumito test when 3v1 give true."){
        game.play(Position(6,2), Position{5,2});
        game.play(Position(5,2), Position{4,2});
        game.play(Position(7,1), Position{6,1});
        game.play(Position(6,1), Position{5,1});
        game.play(Position(7,0), Position{6,0});
        game.swapPlayer();
        game.play(Position{2,4}, Position{3,3});
        game.swapPlayer();
        REQUIRE(game.sumito(Position{6,0}, Direction::UPRIGHT));
    }

    SECTION("sumito test when 3v2 give true."){
        game.play(Position(6,2), Position{5,2});
        game.play(Position(5,2), Position{4,2});
        game.play(Position(7,1), Position{6,1});
        game.play(Position(6,1), Position{5,1});
        game.play(Position(7,0), Position{6,0});
        game.swapPlayer();
        game.play(Position{2,4}, Position{3,3});
        game.play(Position{1,5}, Position{2,4});
        game.swapPlayer();
        REQUIRE(game.sumito(Position{6,0}, Direction::UPRIGHT));
    }
}
