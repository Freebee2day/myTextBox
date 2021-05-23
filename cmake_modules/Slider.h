//
// Created by 16262 on 5/21/2021.
//

#ifndef RENAMEHERE_SLIDER_H
#define RENAMEHERE_SLIDER_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <stack>
#include <list>
using namespace std;

class Slider{
public:
    sf::Font myfont;
    sf::CircleShape knob;
    sf::RectangleShape bar;
    sf::Vector2<float> bar_size;
    float knobx;
    float knoby;
    bool clicked = false;
    sf::Text sliderLable;

    Slider(string name, float labelx, float kbx, float barx, float y){
        knobx = kbx;
        knoby = y;

        myfont.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
        sliderLable.setFont(myfont);
        sliderLable.setFillColor(sf::Color::White);
        sliderLable.setCharacterSize(30);
        sliderLable.setPosition(labelx,y-10);
        sliderLable.setString(name);

        int knob_radius = 10;
        knob.setRadius(knob_radius);
        knob.setPosition(knobx,y);

        bar_size = {600,5};
        bar.setSize(bar_size);
        bar.setPosition(barx,y+knob_radius/2);
    }

    void drawTo(sf::RenderWindow &window){
        window.draw(knob);
        window.draw(sliderLable);
        window.draw(bar);
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






#endif //RENAMEHERE_SLIDER_H
