#ifndef VIEW_H
#define VIEW_H

#include "observer.h"
#include "Game.h"
#include "string"


/*!
 * \brief Class who represent The View of the game
 */
class View : public nvs::Observer{

public :

    /*!
     * \brief Constructor of the View
     */
    View();

    /*!
     * \brief this method display the Board
     * \param g this is the game
     */
    void displayBoard(Game g);

    /*!
     * \brief this method display the Current Player
     * \param g, this is the game
     */
    void displayCurrentPlayer(Player p);

    /*!
     * \brief this method manages the keyboard entry of the player of a position
     * \return a position
     */
    Position displayEnterPosition();

    /*!
     * \brief this method display the Winner
     * \param player , this is the player winner
     */
    void displayWinner(Player player);

    /*!
     * \brief this method displays an error message appropriate to the situation
     * \param game the game
     * \param begin the position of the piece one
     * \param end the position of the second piece
     */
    void displayError(Game game,Position begin,Position end);

    /*!
     * \brief displays a message if the player's movement has been completed
     */
    void displayGoodMove();

    /*!
     * \brief Update the observer.
     * \param subject The nvs::Subject who notify the update.
     */
    virtual void update(const nvs::Subject * subject) override;

    /*!
     * \brief Put in a string a player.
     * \param p The player.
     * \return A string.
     */
    std::string toStringPlayer(Player p);

    /*!
     * \brief Put in a string a piece.
     * \param p The piece
     * \return A string.
     */
    std::string toStringPiece(Piece p);

    /*!
     * \brief Put in a string a position.
     * \param p The position.
     * \return A string.
     */
    std::string toStringPosition(Position p);
};
#endif // VIEW_H
