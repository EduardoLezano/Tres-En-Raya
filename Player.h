#pragma once

#include <string>

using namespace std;

class Player
{
private:
    string _name;
public:
    Player(/* args */);
    Player(string);
    ~Player();

    string GetName() const;
    void SetName(const string);
};

Player::Player(/* args */)
{
}

Player::Player(string name)
    :_name(name)    
{
}

Player::~Player()
{
}

string Player::GetName() const{
    return _name;
}

void Player::SetName(const string newName){
    _name = newName;
}