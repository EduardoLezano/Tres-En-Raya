#pragma once
#include <string>
#include <iostream>

class Tablero
{
private:
    int datos[3][3];
    int ganador;

public:
    Tablero(/* args */);
    ~Tablero();

    bool GanaJugador(int jugadorNumber) const;
    bool IngresarEntrada(int jugadorNumber, int position);
    bool CasillaDisponible(int position);
    int getGanador();
    void printData();
    int getValue(int position);

private:
    void ingresarDato(int jugadorNumber);
    void setValue( int position , int value );
    void getPosition(int* i, int* j,int posicition);
};

Tablero::Tablero(/* args */)
{
    //llenar la matriz de tados en cero
    //      0   0   0
    //      0   0   0
    //      0   0   0
    ganador = 0;
    for (short int i = 0; i<3 ; i++){
        for (short int j = 0; j < 3; j++)
        {
            datos[i][j] = 0;
        }
    }
}

Tablero::~Tablero()
{
}

bool Tablero::GanaJugador(int jugadorNumber) const{
    bool hayGanador = false;
    int sumaTotal;

    if ( jugadorNumber == 1 ) {
        sumaTotal = 3;
    }
    else {
        sumaTotal = 6;
    }

    int sumaDatos = 0;

    //buscar por filas
    for (int i = 0; i < 3; i++){
        sumaDatos = 0;
        for (int j = 0; j < 3; j++){
            if ( datos[i][j] == jugadorNumber ){
                sumaDatos += jugadorNumber;
            }
        }
        std::cout<<"Filas: suma : "<<sumaDatos<<" suma total: "<<sumaTotal<<std::endl;
        if ( sumaDatos == sumaTotal ){
            hayGanador = true;
            break;
        }
    }
    
    if ( hayGanador ){
        return hayGanador;
    }

    //buscar por columnas
    for (int i = 0; i < 3; i++){
        sumaDatos = 0;
        for (int j = 0; j < 3; j++){
            if ( datos[j][i] == jugadorNumber ){
                sumaDatos += jugadorNumber;
            }
        }

        std::cout<<"Columnas: suma : "<<sumaDatos<<" suma total: "<<sumaTotal<<std::endl;
        if ( sumaDatos == sumaTotal ){
            hayGanador = true;
            break;
        }
    }
    
    if (hayGanador){
        return hayGanador;
    }

    //busqueda en las diagonales
    sumaDatos=0;
    for (int i = 0; i < 3; i++){
        if ( datos[i][i] == jugadorNumber ){
            sumaDatos += jugadorNumber;
        }
    }
    std::cout<<"Diagonal p: suma : "<<sumaDatos<<" suma total: "<<sumaTotal<<std::endl;
    if ( sumaDatos == sumaTotal ){
        hayGanador = true;
        return hayGanador;
    }

    //Diagonal invertida
    int i=0,j=2;
    sumaDatos = 0;
    while ( i < 3){
        if ( datos[i][j] == jugadorNumber ){
            sumaDatos += jugadorNumber;
        }
        i++;
        j--;
    }
    std::cout<<"Diagonal s: suma : "<<sumaDatos<<" suma totala: "<<sumaTotal<<std::endl;
    if ( sumaDatos == sumaTotal ){
        hayGanador = true;
        return hayGanador;
    }

    return hayGanador;
}

bool Tablero::IngresarEntrada(int jugadorNumber, int position){
    if ( CasillaDisponible(position) ){
        setValue(position,jugadorNumber);

        //Verificar si gana el jugador
        if (GanaJugador(jugadorNumber)){
            std::cout<<"\nJugador "<<jugadorNumber<<" gana la partida\n";
            ganador = jugadorNumber;
        }

        return true;
    } else {
        std::cout<<"No se puede usar esa casilla escoja otra\n";
        return false;
    }
}

bool Tablero::CasillaDisponible(int position) {
    if ( getValue(position) == 0 ){
        return true;
    }
    else {
        return false;
    }

}

int Tablero::getValue(int position){
    int i,j;
    getPosition(&i,&j,position);

    return datos[i][j];
}

void Tablero::setValue( int position , int value ){
    int i,j;
    getPosition(&i,&j,position);
    datos[i][j] = value;
}

int Tablero::getGanador(){
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
            std::cout<<datos[i][j]<< " ";
        }
        std::cout<<"]\n";
    }
    
}