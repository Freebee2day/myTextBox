#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "cmake_modules/Typing.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000, 32), "Test");

    sf::Font myfont;
    myfont.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
    sf::Text label;
    label.setCharacterSize(50);
    label.setString("First Name");
    label.setPosition(95,55);
    label.setFont(myfont);



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

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                float x = sf::Mouse::getPosition(window).x;
                float y = sf::Mouse::getPosition(window).y;
                if(x>100 && x<900 && y>110 && y<165){   //check if mouse clicked on the textbox
                    typing.clickedOn(true);
                    box.setOutlineColor(sf::Color::Yellow);
                }else{
                    typing.clickedOn(false);
                    box.setOutlineColor(sf::Color::White);
                }
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
        window.draw(label);
        typing.drawTo(window);
        window.draw(box);
        window.display();

    }
    return 0;
}
