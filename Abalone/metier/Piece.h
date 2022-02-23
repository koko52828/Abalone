    #ifndef PIECE_H
#define PIECE_H
#include "Position.h"
#include "Enumeration.h"
#include "string"


/*!
 * \brief Class who represent a piece.
*/

class Piece{

    /*!
    * \brief The color of a piece.
    */
    PlayerColor color_;

    /*!
    * \brief The position of the piece.
    */
    Position pos_;

public :

    /*!
    * \brief Constructor of the piece.
    * \param color The color of the piece.
    * \param pos The position of the piece.
    */
    Piece(PlayerColor color=PlayerColor::Empty, Position pos=Position{0,0});

    /*!
    * \brief Gives the color of the piece.
    * \return A PlayerColor.
    */
    PlayerColor getColor_();

    /*!
     * \brief Gives the position.
     * \return A position.
     */
    Position getPos_();

    /*!
    * \brief Change the color of the piece.
    * \param color The new color.
    */
    void setColor(PlayerColor color);

    /*!
     * \brief chang the position of the piece
     * \param pos , the new position
     */
    void setPosition(Position pos);

};

#endif // PIECE_H
