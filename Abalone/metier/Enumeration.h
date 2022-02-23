#ifndef ENUMERATION_H
#define ENUMERATION_H
#include "Position.h"
/*!
 * \brief An enum who represent a color.
 */
enum PlayerColor{
    Black,
    White,
    Empty
};

/*!
 * \brief An enum who represent a direction.
 */
enum Direction{
    LEFT,
    RIGHT,
    UPLEFT,
    UPRIGHT,
    DOWNLEFT,
    DOWNRIGHT
};

#endif // ENUMERATION_H
