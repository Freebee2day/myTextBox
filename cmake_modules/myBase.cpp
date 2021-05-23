//
// Created by 16262 on 4/1/2021.
//

#include "myBase.h"

myBase::myBase(char s, float xPos){
    font.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
    msg.setFont(font);
    msg.setFillColor(sf::Color::White);
    msg.setCharacterSize(50);
    msg.setPosition(xPos,300);
    msg.setString(s);
}

void myBase::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(msg,states);
}

float myBase::getXpos()const{
    return msg.getPosition().x;
}