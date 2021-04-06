//
// Created by 16262 on 4/1/2021.
//

#ifndef RENAMEHERE_MYBASE_H
#define RENAMEHERE_MYBASE_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace std;

class myBase: public sf::Drawable{
    sf::Text msg;
    sf::Font font;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    friend class Typing;

public:
    myBase(char s,float xPos);
    virtual float getXpos()const;

};


#endif //RENAMEHERE_MYBASE_H
