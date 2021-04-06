//
// Created by 16262 on 3/30/2021.
//

#ifndef RENAMEHERE_SPECICALCHAR_H
#define RENAMEHERE_SPECICALCHAR_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "myBase.h"
using namespace std;

class SpecialChar: public myBase{
    sf::Text msg;
    sf::Font font;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual float getXpos()const;

    friend class Typing;

public:
    //Letter(char s, float xPos) : myBase(s, xPos)
    SpecialChar(char, float);

};


#endif //RENAMEHERE_SPECICALCHAR_H
