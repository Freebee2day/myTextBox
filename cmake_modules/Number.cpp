//
// Created by 16262 on 3/31/2021.
//

#include "Number.h"

Number::Number(char s, float xPos) : myBase(s, xPos) {
    font.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
    msg.setFont(font);
    msg.setFillColor(sf::Color::Blue);
    msg.setCharacterSize(50);
    msg.setPosition(xPos,100);
    msg.setString(s);
}

void Number::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(msg,states);
}

float Number::getXpos()const{
    return msg.getPosition().x;
}