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
    _player1.SetName("Player 1");
    _player1.SetSimbol('X');
    _player2.SetName("Player 2");
    _player2.SetSimbol('O');
}

Game::~Game()
{
}

void Game::Run(){
    mostrarMenuInicio();
    play();
}

void Game::mostrarMenuInicio(){
    cout<<"\n\t\t>>> Juego Tres en raya <<<\n\n";
    _screen.ImprirTableroVacio();
}

void Game::play(){
    int opc = -1;       //Opcion del menu
    int iter = 1;   //Numero de iteracciones 
    int posicion;   //Posicion seleccionada por el jugador
    int turnoJugador; //Quin tiene el turno

    cout<<"\n\n  Pulse ENTER para INICIAR \n";
    char in;
    cin.get(in);

    while ( true ){
        //system("cls"); // for windows
        system("clear"); // for Linux
        //_tablero.printData();
        //cout<<"iter: "<<iter<<endl;
        cout<<"Ingrese 0 para salir\n\n";
        _screen.ImprirTablero(_tablero);

        if ( (iter % 2) != 0 ) {
            cout<<"\n[X] Juagor 1 ";
            turnoJugador = 1;
        }
        else {
            cout<<"\n[O] Juagor 2 ";
            turnoJugador = 2;
        }
        cout<<"\nIngrese posición: ";
        cin>>posicion;
        if (posicion == 0){
            cout<<"Pulsaste 0, Saliendo\n";
            break;
        }

        if ( turnoJugador == 1){
            if ( !_tablero.IngresarEntrada(_player1,posicion) ){
                continue;
            }
        } else {
            if ( !_tablero.IngresarEntrada(_player2,posicion) ){
                continue;
            }
        }
        
        if(_tablero.getGanador() != nullptr){
            system("clear");
            cout<<"Felicidades, Jugador "<< _tablero.getGanador()->GetName() <<" haz ganado, Saliendo\n";
            _screen.ImprirTablero(_tablero);
            break;
        }

        iter++;

        if ( iter > 9){
            cout<<"¡¡¡ Nadie gana !!!";
        }
        
    }

}
