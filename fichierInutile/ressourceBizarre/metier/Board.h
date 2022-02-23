#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"

/*!
 * \brief Class who represent a board.
 */
class Board{

    /*!
     * \brief The array who represent the board.
     */
    Piece array[5][5][5];

public:

    /*!
     * \brief Constructor of the board.
     */
    Board();

    /*!
     * \brief Determines if the position is inside the board.
     * \param pos The position.
     * \return A boolean.
     */
    bool isInside(Position pos);

    /*!
     * \brief Make a movement.
     * \param p The piece.
     * \param pos The position.
     */
    void push(Piece p, Position pos);

    /*!
     * \brief Determines if the position is free.
     * \param position The position.
     * \return A boolean.
     */
    bool isFree(Position position);

    /*!
     * \brief Determines if a piece belong to a player.
     * \param position The position.
     * \param color The color.
     * \return A boolean.
     */
    bool isMyOwn(Position position, PlayerColor color);

    /*!
     * \brief Gives a piece.
     * \param position The position.
     * \return A piece.
     */
    Piece getPiece(Position position);

    /*!
     * \brief Remove a piece at a position.
     * \param position The position.
     */
    void remove(Position position);

    /*!
     * \brief Gives the board.
     */
    Piece getBoard();
};

#endif // BOARD_H
