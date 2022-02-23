#ifndef GAME_H
#define GAME_H

#include "subject.h"
#include "Player.h"
#include "Board.h"

/*!
 * \brief Class who represent a game.
 */
class Game : public nvs::Subject{

    /*!
     * \brief The current player of the game.
     */
    Player current_;

    /*!
     * \brief The opponent player of the game.
     */
    Player opponent_;

    /*!
     * \brief The board of the game.
     */
    Board board_;

    /*!
     * \brief begin_ The first case selectionned in the fx.
     */
    Position begin_;

    /*!
     * \brief end_ The second case selectionned in the fx.
     */
    Position end_;

    /*!
     * \brief selectedCase_ Number of selected case in the fx.
     */
    int selectedCase_;

public :

    /*!
     * \brief Constructor of the game.
     */
    Game();

    /*!
     * \brief Gives the current player.
     * \return A Player.
     */
    Player getCurrent_();

    /*!
     * \brief Gives the opponent player.
     * \return A Player.
     */
    Player getOpponent_();

    /*!
     * \brief getBegin_ Gives the first selectionned position.
     * \return A Position.
     */
    Position getBegin_();

    /*!
     * \brief getEnd_ Gives the second selectionned piece.
     * \return A Position.
     */
    Position getEnd_();

    /*!
     * \brief getSelectedCase Gives the number of selectionned position to play.
     * \return A Integer.
     */
    int getSelectedCase_();

    /*!
     * \brief setBegin_ Set the value of the first position selected.
     * \param newBegin The new value of begin_.
     */
    void setBegin_(Position newBegin);

    /*!
     * \brief setEnd_ Set the value of the second position selected.
     * \param newEnd The new value of end_.
     */
    void setEnd_(Position newEnd);

    /*!
     * \brief setSelectedCase_ Set the value of selectedCase_.
     * \param newSlectedCase The new value to set.
     */
    void setSelectedCase_(int newSlectedCase);

    /*!
     * \brief Gives the board.
     * \return A 3d vector of piece.
     */
    std::vector<std::vector<Piece>> getBoard_();

    /*!
     * \brief Initialize the game.
     */
    void initialize();

    /*!
     * \brief Swap the current player and the opponent player.
     */
    void swapPlayer();

public:

    /*!
     * \brief Make a move of a piece.
     * \param piece The piece who are concerned.
     * \param pos The position who the piece should be.
     */
    void play(Position begin, Position end);

    /*!
     * \brief determines if the game is over.
     * \return A boolean.
     */
    bool isOver();

    /*!
     * \brief Determines if a movement is possible.
     * \param begin The first positon.
     * \param end The arrival position.
     * \return A boolean.
     */
    bool canPlay(Position begin, Position end);

    /*!
     * \brief Gives the number of piece of a player.
     * \param player The player.
     * \return An integer.
     */
    int nbrOfCurrentPiece(Player player);

    /*!
     * \brief check sumito game rules
     * \param begin position of the piece
     * \param dir, direction of the piece
     * \return A boolean
     */
    bool sumito(Position begin,Direction dir);

    /*!
     * \brief *give in which direction the piece is moving
     * \param begin position of the piece in the beginning
     * \param end position of the piece in the end
     * \return A boolean
     */
    Direction goodDirection(Position begin,Position end);

    /*!
     * \brief check if the piece is inside of the board
     * \param pos, position of the piece
     * \return A boolean
     */
    bool isInsideGame(Position pos);

    /*!
     * \brief check if the piece belongs to me in the board
     * \param pos, position of the piece
     * \return A boolean
     */
    bool isMyOwnGame(Position pos);

};

#endif // GAME_H
