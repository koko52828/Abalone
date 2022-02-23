#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "observer.h"
#include "subject.h"

#include "Game.h"
#include "View.h"


/*!
 * \brief The Controller class control the dynamic of the game
 */

class Controller : nvs::Observer, public nvs::Subject{


private :

    /*!
     * \brief the game
     */
    Game game;

    /*!
     * \brief the view of the game
     */
    View view;


public:
    /*!
     * \brief Constructor of the Controller
     */
    Controller();

    Game getGame();

    /*!
     * \brief this method start the game with all the game methods
     */
    void startGame();

    /*!
     * \brief Update the observer.
     * \param subject The nvs::Subject who notify the update.
     */
    virtual void update(const nvs::Subject * subject) override;
};




#endif // CONTROLLER_H
