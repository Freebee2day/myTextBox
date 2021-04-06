//
// Created by 16262 on 3/31/2021.
//

#ifndef RENAMEHERE_KEYWORD_H
#define RENAMEHERE_KEYWORD_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "myBase.h"
using namespace std;

class Keyword: public myBase{
    sf::Text msg;
    sf::Font font;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual float getXpos()const;

    friend class Typing;

public:
    //Letter(char s, float xPos) : myBase(s, xPos)
    Keyword(char, float);

};


#endif //RENAMEHERE_KEYWORD_H
