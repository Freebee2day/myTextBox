//
// Created by 16262 on 5/22/2021.
//

#ifndef RENAMEHERE_MENU_H
#define RENAMEHERE_MENU_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <stack>
#include <list>
#include "MenuItem.h"
using namespace std;


class Menu {
public:
    sf::Font myfont;
    vector<string> items;
    sf::RectangleShape box;
    bool clicked = false;
    float orgX;
    float orgY;
    sf::Text menuName;
    sf::Text selectedName;
    vector<MenuItem*> processedMenuItems;

    Menu(float posx, float posy, string name, vector<string> arrItems){
        myfont.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
        items = arrItems;

        orgX = posx;
        orgY = posy;

        menuName.setString(name);
        menuName.setPosition(orgX,orgY);
        menuName.setCharacterSize(30);
        menuName.setFont(myfont);
        menuName.setFillColor(sf::Color::White);

        selectedName.setString(items[0]);
        selectedName.setPosition(orgX+110,orgY);
        selectedName.setCharacterSize(20);
        selectedName.setFont(myfont);
        selectedName.setFillColor(sf::Color::White);


        box.setSize({150,30});
        box.setFillColor(sf::Color::Transparent);
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(5);
        box.setPosition({orgX+100,orgY});

        for(int i=0; i<arrItems.size(); i++){
            MenuItem* myMIptr = new MenuItem(orgX+110,orgY+30*(i+2),arrItems[i]);
            processedMenuItems.emplace_back(myMIptr);
        }

    }

    ~Menu(){
        for(int i=0; i<processedMenuItems.size(); i++){
            delete processedMenuItems[i];
        }
    }

    void drawTo(sf::RenderWindow &window){
        window.draw(menuName);
        window.draw(box);
        window.draw(selectedName);

        if(clicked){
            for(int i=0; i<processedMenuItems.size(); i++){
                MenuItem myITM = *processedMenuItems[i];
                window.draw(myITM.label);
                window.draw(myITM.box);
            }
        }

    }

    void addEventHandler(sf::Event e){
        if(clicked) {
            //change x position.
        }
    }

    void clickedOn(bool tf){
        clicked = tf;
    }

};


#endif //RENAMEHERE_MENU_H
