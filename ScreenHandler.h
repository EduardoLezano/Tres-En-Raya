#pragma once 

#include <string>
#include <iostream>
#include <iomanip>

#include "Tablero.h"

using namespace std;

class ScreenHandler
{
private:
    
public:
    ScreenHandler();
    ~ScreenHandler();

    void ImprirTableroVacio() const;
    void ImprirTablero(Tablero&) const;
};

ScreenHandler::ScreenHandler(/* args */)
{
}

ScreenHandler::~ScreenHandler()
{
}

void ScreenHandler::ImprirTableroVacio() const {
    cout<<setw(30)<<" --------------------------\n";
    cout<<setw(30)<<"|        |        |        |\n";
    cout<<setw(30)<<"|        |        |        |\n";
    cout<<setw(30)<<"|1       |2       |3       |\n";
    cout<<setw(30)<<" --------------------------\n";
    cout<<setw(30)<<"|        |        |        |\n";
    cout<<setw(30)<<"|        |        |        |\n";
    cout<<setw(30)<<"|4       |5       |6       |\n";
    cout<<setw(30)<<" --------------------------\n";
    cout<<setw(30)<<"|        |        |        |\n";
    cout<<setw(30)<<"|        |        |        |\n";
    cout<<setw(30)<<"|7       |8       |9       |\n";
    cout<<setw(30)<<" --------------------------\n";
}
//

void ScreenHandler::ImprirTablero(Tablero& tablero) const {
    cout<<setw(30)<<" --------------------------\n";
    cout<<setw(30)<<"|        |        |        |\n";
    
    cout<<" |";
    for (int i = 1; i <= 3; i++){
        int valor = tablero.getValue(i);
        cout<<"    ";
        if ( valor != 0 ){
            if ( valor == 1 ){
                cout<<"X";
            } 
            else {
                cout<<"O";
            }
        } 
        else {
            cout<<" ";
        }
        cout<<"   |";
    }

    cout<<"\n |1       |2       |3       |\n";
    cout<<" --------------------------\n";
    cout<<" |        |        |        |\n";
    
    cout<<" |";
    for (int i = 4; i <= 6; i++){
        int valor = tablero.getValue(i);
        cout<<"    ";
        if ( valor != 0 ){
            if ( valor == 1 ){
                cout<<"X";
            } 
            else {
                cout<<"O";
            }
        } 
        else {
            cout<<" ";
        }
        cout<<"   |";
    }
    cout<<"\n |4       |5       |6       |\n";
    cout<<"  --------------------------\n";
    cout<<setw(30)<<"|        |        |        |\n";
    cout<<" |";
    for (int i = 7; i <= 9; i++){
        int valor = tablero.getValue(i);
        cout<<"    ";
        if ( valor != 0 ){
            if ( valor == 1 ){
                cout<<"X";
            } 
            else {
                cout<<"O";
            }
        } 
        else {
            cout<<" ";
        }
        cout<<"   |";
    }
    cout<<"\n |7       |8       |9       |\n";
    cout<<setw(30)<<" --------------------------\n";
}