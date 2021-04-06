//
// Created by 16262 on 3/31/2021.
//

#include "Keyword.h"


Keyword::Keyword(char s, float xPos) : myBase(s, xPos) {
    font.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
    msg.setFont(font);
    msg.setFillColor(sf::Color::Magenta);
    msg.setCharacterSize(50);
    msg.setPosition(xPos,100);
    msg.setString(s);
}

void Keyword::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(msg,states);
}

float Keyword::getXpos()const{
    return msg.getPosition().x;
}