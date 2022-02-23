#ifndef BOARD_H
#define BOARD_H
#include "Piece.h"
#include "vector"
#include "Enumeration.h"

/*!
 * \brief Class who represent a board.
 */
class Board{

    /*!
     * \brief The array who represent the board.
     */
    std::vector<std::vector<Piece>> pieces_;

    /*!
     * \brief The size of the x-axis of the board.
     */
    static constexpr size_t x_ = 9;

    /*!
     * \brief The size of the y-axis of the board.
     */
    static constexpr size_t y_ = 9;


public:

    /*!
     * \brief Constructor of the board.
     */
    Board();

    /*!
     * \brief Gives the board.
     * \return A 3d vector of piece.
     */
    std::vector<std::vector<Piece>>& getBoard_();

    /*!
     * \brief Gives the x-axis size of the board.
     * \return A size_t.
     */
    size_t getX_();

    /*!
     * \brief Gives the y-axis size of the board.
     * \return A size_t.
     */
    size_t getY_();

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
    void push(Piece & p, Position pos);

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
    Piece getPiece_(Position position);

    /*!
     * \brief initialize the board with all the correct piece positions
     */
    void initialize();

    /*!
     * \brief setPieceColor set the color of the piece in the board
     * \param color that will be applied to the new piece
     * \param pos of the piece
     */
    void setPieceColor(PlayerColor color,Position pos);
};

#endif // BOARD_H
