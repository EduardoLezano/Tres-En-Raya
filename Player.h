#pragma once

#include <string>

using namespace std;

class Player
{
private:
    string _name;
    char _simbol;
public:
    Player(/* args */);
    Player(string,char);
    ~Player();

    string GetName() const;
    char GetSimbol() const;
    void SetSimbol(const char) ;
    void SetName(const string);
    void PrintPlayer();
};

Player::Player(/* args */)
{
}

Player::Player(string name,char simbol)
    : _name(name)
    , _simbol(simbol)   
{
}

Player::~Player()
{
}

string Player::GetName() const{
    return _name;
}
char Player::GetSimbol() const{
    return _simbol;
}

void Player::SetName(const string newName){
    _name = newName;
}

void Player::SetSimbol(const char newSimbol){
    _simbol = newSimbol;
}

void Player::PrintPlayer(){
    std::cout<<"  Player Name : "<<_name<<std::endl;
    std::cout<<"Player Simbol : "<<_simbol<<std::endl;
}