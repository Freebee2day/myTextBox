//
// Created by 16262 on 3/30/2021.
//

#include "SpecicalChar.h"


SpecialChar::SpecialChar(char s, float xPos) : myBase(s, xPos) {
    font.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
    msg.setFont(font);
    msg.setFillColor(sf::Color::Red);
    msg.setCharacterSize(50);
    msg.setPosition(xPos,100);
    msg.setString(s);
}

void SpecialChar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(msg,states);
}

float SpecialChar::getXpos()const{
    return msg.getPosition().x;
}
