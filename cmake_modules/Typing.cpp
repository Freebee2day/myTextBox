//
// Created by 16262 on 3/19/2021.
//

#include "Typing.h"
#include "Letter.h"
#include "SpecicalChar.h"
#include "Number.h"
#include "LetterLower.h"
#include "Keyword.h"
#include <iostream>
#include <stack>

Typing::Typing(){
    //need to keep track of position using original message.
    font.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");
    msg.setFont(font);
    //msg.setString("in typing!!");  //string will be set by user input.
    msg.setFillColor(sf::Color::White);
    msg.setCharacterSize(50);
    msg.setPosition(100,600);

//    rec.setFillColor(sf::Color::Transparent);
//    rec.setOutlineThickness(5);
//    rec.setOutlineColor(sf::Color::White);
//    rec.setPosition(100,100);
}

void Typing:: captureInput(int charac){

    //8 correspond to the backspace key
    //if key other than the backspace key is press, caputure the key
    if(charac!=8){

        //update nonColor String
        //nonColor String is used as reference for positioning the char (in the colored string).
        input<<static_cast<char>(charac);   //translate the num to its corresponding character.
        msg.setString(input.str());
        lastXPos= msg.findCharacterPos(msg.getString().getSize()-1).x;

        //update Color String
        if (charac>64 && charac< 91){   //check UpperCase
            Letter *mlt = new Letter(static_cast<char>(charac),lastXPos);
            msgBucket.push_back(mlt);
        }else if (charac>96 && charac< 123){    //check LowerCase
            LetterLower *myLowerCase = new LetterLower(static_cast<char>(charac),lastXPos);
            msgBucket.push_back(myLowerCase);
        }else if (charac>47 && charac< 58) {    //check Number
            Number *myNum = new Number(static_cast<char>(charac), lastXPos);
            msgBucket.push_back(myNum);
        }else{      //the rest are treated as special characters
            SpecialChar *msc = new SpecialChar(static_cast<char>(charac),lastXPos);
            msgBucket.push_back(msc);
        }


        //clear the stack so user would have a new stack of deleted item to work with.
        //update nonColor String
        while(!charStack.empty()){
            charStack.pop();
        }
        //update Color String
        while(!deletedItems.empty()){
            deletedItems.pop();
        }

        //after user input, always check if keywords are detected.
        checkAll();

    }else if (charac == 8 ) {  //if backspace/delete key is pressed
        deleteChar();
    }

    sf::Vector2f sz={msg.findCharacterPos(input.str().length()-1).x -20,60};
    //rec.setSize(sz);
    msg.setString(input.str()); //link our text to user's text input.

}

//for handling the event which user press backspace to delete
void Typing::deleteChar(){
    if (input.str().length() > 0) {  //check to see if there is still character in input to delete

        //update nonColor String
        //create a new string and copy all input value (except the last character)
        //essentially deleting the last character.
        string original = input.str();
        string shortened = "";
        for (int i = 0; i < input.str().length()-1; i++) {
            shortened += original[i];
        }

        //update Color String
        deletedItems.push(msgBucket.back());
        msgBucket.pop_back();


        //put the deleted character in stack, in case user needs to undo the delete.
        //update nonColor String
        char lastone= original[input.str().length()-1];
        charStack.push(lastone);
        input.str("");      //need to clear the value of input
        input << shortened;       //now re-enter the new value of input without the last character.
        msg.setString(input.str());
    }
};



// if LControl and 'z' are pressed simultaneously
// "two keys are pressed simultaneously" => twoSim
//the twoSim fxn will be called to undo the delete
void Typing::twoSim(){
    //update nonColor String
    if (!charStack.empty()) {
        char toBeReinserted= charStack.top();   //look at and record the top item in the stack
        charStack.pop();                        //remove the top item in stack
        input<<toBeReinserted;                  //append the character back to the string.
        msg.setString(input.str());

//        adjust the size of the rectangular box
//        sf::Vector2f sz={msg.findCharacterPos(input.str().length()-1).x -20,60};
//        rec.setSize(sz);
    }

    //update Color String
    if (!deletedItems.empty()){
        msgBucket.push_back(deletedItems.top());
        deletedItems.pop();
    }

}

void Typing::drawTo(sf::RenderWindow &window){
    //draw the nonColor String
    //window.draw(msg);

    //Draw Color String
    for(auto itr=msgBucket.begin();itr!=msgBucket.end();itr++){
        window.draw(**itr);
        //the first * dereference what the iterator points to, which is the LinkedList Node
        //the second * dereference the the stuff in the Node, which is address to the myBase object.
    }

    //window.draw(rec);
}

void Typing::addEventHandler(sf::Event e){
    if(clicked) {
        int character = e.text.unicode;
        if (character < 128) {
            captureInput(character);
        }
    }
}


//remove the original word in the msgBucket, and replace the word in keyword color
void Typing::replaceKey(string word) {
    //remove the original char in colored string
    stack<myBase*> temp;

    for(int i=word.length()-1; i>=0;i--){
        float tempXpos = msgBucket.back()->getXpos();
        msgBucket.pop_back();
        Keyword *myKW = new Keyword(static_cast<char>(word[i]),tempXpos);
        temp.push(myKW);
    }
    while(!temp.empty()) {
        msgBucket.push_back(temp.top());
        temp.pop();
    }
}


//passing in a keyword and check if it appears in the string
//if so, return true, else return false
bool Typing::checkKey(string key){
    string original = msg.getString();
    if(original.length()>=key.length()) {
        string temp = original.substr(original.length() - key.length(), original.length() - 1);
        if (temp == key){
            return true;
        }
    }
    return false;
}


//checking the 3 keywords, if detected => change color by calling replaceKey fxn.
void Typing::checkAll() {

    if (checkKey("int")){
        replaceKey("int");
    }
    if (checkKey("char")){
        replaceKey("char");
    }
    if (checkKey("double")){
        replaceKey("double");
    }
    if (checkKey("float")){
        replaceKey("float");
    }
}


//void Typing::updateCursor(bool &blinking){
//    if(blinking){
//
//        blinking = false;
//    }else{
//
//        blinking = true;
//    }
//}


