#ifndef PLAYER_H
#define PLAYER_H
#include "Piece.h"
#include "Enumeration.h"
#include "string"

/*!
 * \brief Class who represent a player.
 */
class Player{

    /*!
     * \brief The color of a player.
     */
    PlayerColor color_;

public:

    /*!
     * \brief Constructor of a player.
     * \param color Color of the player.
     */
    Player(PlayerColor color);

    /*!
     * \brief Gives the color of the player.
     * \return A PlayerColor.
     */
    PlayerColor getColor_();

    /*!
     * \brief give the color of the player in a string form
     * \return his color
     */

    std::string playerToString();

};

#endif // PLAYER_H
