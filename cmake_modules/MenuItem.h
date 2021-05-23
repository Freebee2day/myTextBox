//
// Created by 16262 on 5/23/2021.
//

#ifndef RENAMEHERE_MENUITEM_H
#define RENAMEHERE_MENUITEM_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <stack>
#include <list>
using namespace std;


class MenuItem {
public:
    float itmx;
    float itmy;
    sf::Text label;
    sf::RectangleShape box;
    sf::Font myfont;

    MenuItem(float x, float y, string name){
        itmx =x;
        itmy = y;


        myfont.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
        label.setString(name);
        label.setPosition(itmx,itmy-30);
        label.setCharacterSize(20);
        label.setFont(myfont);
        label.setFillColor(sf::Color::White);


        box.setSize({150,30});
        box.setFillColor(sf::Color::Transparent);
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(5);
        box.setPosition({itmx-10,itmy-30});
    }
};


#endif //RENAMEHERE_MENUITEM_H
