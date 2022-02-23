#ifndef POSITION_H
#define POSITION_H
#include <iostream>
#include <Enumeration.h>


/*!
 * \brief Class who represent a position.
 */
class Position{

    /*!
     * \brief Integer who represent x axis of the position.
     */
    int x_;

    /*!
     * \brief Integer who represent y axis of the position.
     */
    int y_;


public :
    /*!
     * \brief Constructor of a position.
     * \param x Integer who represent x axis.
     * \param y Integer who represent y axis.
     */
    Position(int x, int y);

    /*!
     * \brief Gives the x axis of a position.
     * \return An integer x.
     */
    int getX_();

    /*!
     * \brief Gives the y axis of a position.
     * \return An integer y.
     */
    int getY_();

    /*!
     * \brief operator + on a position
     * \param pos the position target
     * \return a position
     */
    Position operator+(Position pos);

    /*!
     * \brief gives the next position in a direction
     * \param direction
     * \return a position
     */
    Position next(Direction direction);

    /*!
     * \brief check if two position are the same
     * \param pos this is the second positon
     * \return a boolean
     */
    bool equals(Position pos);

    /*!
     * \brief convert the position of a piece to a position in the array
     * \return position
     */
    Position posPieceToIndice();

    /*!
     * \brief give a position in a direction
     * \param direction
     * \return a position
     */
    static Position positionOfDirection(Direction direction);

    /*!
     * \brief convert the position in the array of a piece to a position in game
     * \return position
     */

    Position posIndiceToPiece();
};

#endif // POSITION_H
