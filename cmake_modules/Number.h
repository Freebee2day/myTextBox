//
// Created by 16262 on 3/31/2021.
//

#ifndef RENAMEHERE_NUMBER_H
#define RENAMEHERE_NUMBER_H


#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "myBase.h"
using namespace std;

class Number: public myBase{
    sf::Text msg;
    sf::Font font;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual float getXpos()const;

    friend class Typing;

public:
    //Letter(char s, float xPos) : myBase(s, xPos)
    Number(char, float);

};

#endif //RENAMEHERE_NUMBER_H
