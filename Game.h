#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>

#include "Tablero.h"
#include "Player.h"
#include "ScreenHandler.h"

using namespace std;

class Game
{
private:
    ScreenHandler _screen;
    Tablero _tablero;
    Player _player1;
    Player _player2;

public:
    Game();
    ~Game();
    void Run();

private:
    void mostrarMenuInicio();
    string getUserInput();
    void play();
};

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run(){
    mostrarMenuInicio();
    play();
}

void Game::mostrarMenuInicio(){
    cout<<"\n\t\tJuego Tres en raya\n\n";
    _screen.ImprirTableroVacio();
}

void Game::play(){
    int opc = -1;
    int iter = 0;
    int posicion;
    int turnoJugador;

    while ( true ){
        //system("cls");

        if ( (iter %= 2) == 0 ) {
            cout<<"Juagor 1: ";
            turnoJugador = 1;
        }
        else {
            cout<<"Juagor 2: ";
            turnoJugador = 2;
        }

        cin>>posicion;
        if (posicion == 0){
            cout<<"Pulsaste 0, Saliendo\n";
            break;
        }
        if ( !_tablero.IngresarEntrada(turnoJugador,posicion) ){
            continue;
        }
        _tablero.printData();
        _screen.ImprirTablero(_tablero);

        if(_tablero.getGanador() != 0){
            cout<<"Felicidades, Jugador "<< turnoJugador <<" haz ganado, Saliendo\n";
            break;
        }
        iter++;
    }

}
