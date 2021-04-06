//
// Created by 16262 on 3/30/2021.
//

#include "Letter.h"


Letter::Letter(char s, float xPos) : myBase(s, xPos) {
    font.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
    msg.setFont(font);
    msg.setFillColor(sf::Color::Cyan);
    msg.setCharacterSize(50);
    msg.setPosition(xPos,100);
    msg.setString(s);
}

void Letter::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(msg,states);
}

float Letter::getXpos()const{
    return msg.getPosition().x;
}