#ifndef PIECE_H
#define PIECE_H
#include "Position.h"
#include "Enumeration.h"

/*!
 * \brief Class who represent a piece.
 */
class Piece{

    /*!
     * \brief The color of a piece.
     */
    PlayerColor color;

    /*!
     * \brief The position of the piece.
     */
    Position pos;

public :

    /*!
     * \brief Constructor of the piece.
     * \param color The color of the piece.
     * \param pos The position of the piece.
     */
    Piece(PlayerColor color, Position pos);

    /*!
     * \brief Gives the color of the piece.
     * \return A PlayerColor.
     */
    PlayerColor getColor();

    /*!
     * \brief Change the color of the piece.
     * \param color The new color.
     */
    void setColor(PlayerColor color);
};

#endif // PIECE_H
