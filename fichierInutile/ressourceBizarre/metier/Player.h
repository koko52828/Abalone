#ifndef PLAYER_H
#define PLAYER_H
#include "Piece.h"
#include "Enumeration.h"

/*!
 * \brief Class who represent a player.
 */
class Player{

    /*!
     * \brief The color of a player.
     */
    PlayerColor color;

public :

    /*!
     * \brief Constructor of a player.
     * \param color Color of the player.
     */
    Player(PlayerColor color);

    /*!
     * \brief Gives the color of the player.
     * \return A PlayerColor.
     */
    PlayerColor getColor();
};

#endif // PLAYER_H
