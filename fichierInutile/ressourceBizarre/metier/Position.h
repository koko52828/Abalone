#ifndef POSITION_H
#define POSITION_H

/*!
 * \brief Class who represent a position.
 */
class Position{

    /*!
     * \brief Integer who represent x axis of the position.
     */
    int x;

    /*!
     * \brief Integer who represent y axis of the position.
     */
    int y;

    /*!
     * \brief Integer who represent z axis of the position.
     */
    int z;


public :
    /*!
     * \brief Constructor of a position.
     * \param x Integer who represent x axis.
     * \param y Integer who represent y axis.
     * \param z Integer who represent z axis.
     */
    Position(int x, int y, int z);

    /*!
     * \brief Gives the x axis of a position.
     * \return An integer x.
     */
    int getX();

    /*!
     * \brief Gives the y axis of a position.
     * \return An integer y.
     */
    int getY();

    /*!
     * \brief Gives the z axis of a position.
     * \return An integer z.
     */
    int getZ();
};

#endif // POSITION_H
