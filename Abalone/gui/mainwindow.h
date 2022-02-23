#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Game.h"
#include <QLabel>
#include <QList>
#include <hexacell.h>
#include "observer.h"



class MainWindow : public QMainWindow, nvs::Observer
{
    Q_OBJECT

private:
    QLabel *playerlabel ;
    QLabel *playervalue ;
    QLabel *nbrpiece ;
    QLabel *nbrpiecetext;
    std::vector<HexaCell *> listofhexa;
    Game game;




public:
    MainWindow(Game & game, QWidget *parent = nullptr);
    ~MainWindow();

    /*!
     * \brief Update the observer.
     * \param subject The nvs::Subject who notify the update.
     */
    virtual void update(const nvs::Subject * subject) override;

    /*!
     * \brief toStringPlayer display the color of the current player
     * \param p player
     * \return his color
     */


    std::string toStringPlayer(Player p);





};
#endif // MAINWINDOW_H
