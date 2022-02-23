#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Board.h"

/*!
 * \brief Class who represent a game.
 */
class Game{

    /*!
     * \brief The current player of the game.
     */
    Player current;

    /*!
     * \brief The opponent player of the game.
     */
    Player opponent;

    /*!
     * \brief The board of the game.
     */
    Board board;

public :

    /*!
     * \brief Constructor of the game.
     */
    Game();

    /*!
     * \brief Gives the current player.
     * \return A Player.
     */
    Player getCurrent();

    /*!
     * \brief Gives the opponent player.
     * \return A Player.
     */
    Player getOpponent();

    /*!
     * \brief Gives the board.
     * \return A Board.
     */
    Board getBoard();

    /*!
     * \brief Initialize the game.
     */
    void initialize();

    /*!
     * \brief Swap the current player and the opponent player.
     */
    void swapPlayer();

    /*!
     * \brief Make a move of a piece.
     * \param piece The piece who are concerned.
     * \param pos The position who the piece should be.
     */
    void play(Piece piece, Position pos);

    /*!
     * \brief determines if the game is over.
     * \return A boolean.
     */
    bool isOver();

    /*!
     * \brief Determines if a movement is possible.
     * \param p The concerned piece.
     * \param pos The position.
     * \return A boolean.
     */
    bool canPlay(Piece p, Position pos);

    /*!
     * \brief Gives the number of piece of a player.
     * \param player The player.
     * \return An integer.
     */
    int nbrOfCurrentPiece(Player player);
};

#endif // GAME_H
