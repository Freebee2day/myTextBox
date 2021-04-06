#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "cmake_modules/Typing.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000, 32), "Test");

    Typing typing;

    sf::RectangleShape box;
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(5);
    box.setOutlineColor(sf::Color::White);
    box.setPosition(100,110);
    sf::Vector2f mySize(800,55);
    box.setSize(mySize);

    bool onBlink = true;


    while(window.isOpen())
    {
        sf::Event event;
        bool LControl;
        bool pressedZ;



        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            //the keyPressed and KeyReleased Event are used to keep track
            //of whether LControl and 'z' are pressed simultaneously
            if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::LControl){
                    //set control to true
                    LControl = true;
                }
                if (event.key.code == sf::Keyboard::Z){
                    //set z to true
                    pressedZ = true;
                }
                if (LControl && pressedZ){
                    // if both conditions are true, call third fxn.
                    typing.twoSim();
                }

            }
            if(event.type == sf::Event::KeyReleased){
                if (event.key.code == sf:: Keyboard::LControl){
                    //set control to false
                    LControl = false;
                }
                if(event.key.code == sf::Keyboard::Z){
                    //set Z to false
                    pressedZ = false;
                }
            }

            //if (Ctrl + Z) are not pressed, enter record and display text.
            if(!LControl && !pressedZ) {
                if (event.type == sf::Event::TextEntered) {
                    typing.addEventHandler(event);
                }
            }
        }



        window.clear(sf::Color::Black);
        typing.drawTo(window);
//        window.draw(box);
//
//        if(onBlink){
//            //call fxn to display |
//
//            onBlink = false;
//        }else{
//            //call fxn to remove |
//
//            onBlink = true;
//        }

        window.display();

    }
    return 0;
}