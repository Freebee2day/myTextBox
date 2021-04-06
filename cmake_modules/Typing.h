//
// Created by 16262 on 3/19/2021.
//

#ifndef RENAMEHERE_TYPING_H
#define RENAMEHERE_TYPING_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <stack>
#include <list>
#include "SpecicalChar.h"
#include "myBase.h"
using namespace std;


class Typing {
private:
    stack<char> charStack;  //for NonColor DeletedItem
    sf::Text msg;           //msg = string for NonColor
    sf::Font font;
    ostringstream input;
    bool clicked = false;



    list<myBase*> msgBucket;
    stack<myBase*> deletedItems;  //for Colored DeletedItem
    float lastXPos =100;
    //sf::RectangleShape rec;

    void deleteChar();
    void replaceKey(string word);
    bool checkKey(string key);
    void checkAll();


public:

    Typing();
    void captureInput(int charac);

    void drawTo(sf::RenderWindow &window);

    void addEventHandler(sf::Event e);

    void twoSim();

    //void updateCursor(bool &blinking);

    void clickedOn(bool tf){
        clicked = tf;
    }



};


#endif //RENAMEHERE_TYPING_H
