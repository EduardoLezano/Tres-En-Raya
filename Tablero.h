#pragma once
#include <string>
#include <iostream>

#include "Player.h"

class Tablero
{
private:
    Player* ganador;
    char datos[3][3];

public:
    Tablero(/* args */);
    ~Tablero();

    bool GanaJugador(Player& player) const;
    bool IngresarEntrada(int jugadorNumber, int position);
    bool CasillaDisponible(int position);
    Player*  getGanador();
    void printData();
    char getValue(int position);
    bool IngresarEntrada(Player& player, int position);

private:
    void inicializarTablero();
    void ingresarDato(int jugadorNumber);
    void setValue( int position , int value );
    void setValue( int position , char value );
    void getPosition(int* i, int* j,int posicition);
};

Tablero::Tablero(/* args */)
{
    inicializarTablero();
}

Tablero::~Tablero()
{
}

void Tablero::inicializarTablero(){
    //llenar la matriz de tados en cero
    //      0   0   0
    //      0   0   0
    //      0   0   0
    ganador = nullptr;
    for (short int i = 0; i<3 ; i++){
        for (short int j = 0; j < 3; j++){
            datos[i][j] = ' ';
        }
    }
}

bool Tablero::GanaJugador(Player& player) const{
    bool gana = false;
    short coincidencias = 0; //acumulador de las coincidencias del caracter
    char simbolo = player.GetSimbol();

    //verificar por filas
    for ( int i = 0 ; i < 3; i++ ){
        coincidencias = 0;
        for ( int j = 0 ; j < 3; j++ ){
            if ( datos[i][j] == ' '){
                gana = false;
                break;
                //return;
            }
            else if (datos[i][j] == simbolo){
                coincidencias++;
            }
        }
        if (coincidencias == 3){
            return true;
        }
        
    }

    //verificar por columnas
    for ( int i = 0 ; i < 3; i++ ){
        coincidencias = 0;
        for ( int j = 0 ; j < 3; j++ ){
            if ( datos[j][i] == ' '){
                gana = false;
                break;
                //return;
            }
            else if (datos[j][i] == simbolo){
                coincidencias++;
            }
        }
        if (coincidencias == 3){
            return true;
        }
        
    }  

    //busqueda en las diagonales
    coincidencias = 0;
    for (int i = 0; i < 3; i++){
        if ( datos[i][i] == ' ' ){
            gana = false;
            break;
        }
        else if (datos[i][i] == simbolo){
            coincidencias++;
        }
    }
    if (coincidencias == 3){
        return true;
    }

    //Diagonal invertida
    int i=0,j=0;
    coincidencias = 0;
    while ( i < 3){
        if ( datos[i][j] == ' ' ){
            gana = false;
            break;
        } else if (datos[i][i] == simbolo){
            coincidencias++;
        }
        i++;
        j--;
    }
    if (coincidencias == 3){
        return true;
    }

    return gana;
}

bool Tablero::IngresarEntrada(Player& player, int position){
    //player.PrintPlayer();

    if (position <0 || position >9){
        cout<<"Posicion fuera de rango\n";
        return false;
    }

    if ( CasillaDisponible(position) ){
        setValue(position,player.GetSimbol());

        //Verificar si gana el jugador
        if (GanaJugador(player)){
            std::cout<<"\nJugador "<<player.GetName()<<" gana la partida\n";
            ganador = &player;
        }

        return true;
    } else {
        std::cout<<"No se puede usar esa casilla escoja otra\n";
        return false;
    }
}

bool Tablero::CasillaDisponible(int position) {
    
    if ( getValue(position) == ' ' ){
        return true;
    }
    else {
        return false;
    }

}

char Tablero::getValue(int position){
    int i,j;
    getPosition(&i,&j,position);

    return datos[i][j];
}

void Tablero::setValue( int position , int value ){
    int i,j;
    getPosition(&i,&j,position);
    datos[i][j] = value;
}

void Tablero::setValue( int position , char value ){
    int i,j;
    getPosition(&i,&j,position);
    datos[i][j] = value;
}

Player* Tablero::getGanador(){
    return ganador;
}

void Tablero::getPosition(int* i, int* j,int position){
    switch (position)
    {
    case 1:
        *i = 0;
        *j = 0;
        break;
    case 2:
        *i = 0;
        *j = 1;
        break;
    case 3:
        *i = 0;
        *j = 2;
        break;
    case 4:
        *i = 1;
        *j = 0;
        break;
    case 5:
        *i = 1;
        *j = 1;
        break;
    case 6:
        *i = 1;
        *j = 2;
        break;
    case 7:
        *i = 2;
        *j = 0;
        break;
    case 8:
        *i = 2;
        *j = 1;
        break;
    case 9:
        *i = 2;
        *j = 2;
        break;
    default:
        break;
    }
}

void Tablero::printData(){
    
    for (int i = 0; i < 3; i++){
        std::cout<<"[ ";
        for (int j = 0; j < 3; j++){
            std::cout<<(char)datos[i][j]<< " ";
        }
        std::cout<<"]\n";
    }
    
}