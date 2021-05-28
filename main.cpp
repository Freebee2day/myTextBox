#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "cmake_modules/Typing.h"
#include "cmake_modules/Slider.h"
#include "cmake_modules/Menu.h"
using namespace std;

void saveLogo(sf::RenderWindow& myWindow,string name){
    sf::Texture myfile;
    sf::Image tempIMG;
    myfile.create(myWindow.getSize().x, myWindow.getSize().y);
    myfile.update(myWindow);
    tempIMG=myfile.copyToImage();
    tempIMG.saveToFile(name);



}
int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000, 32), "Final Project");

    sf::Font fontOS;
    fontOS.loadFromFile("../cmake_modules/OpenSans-Bold.ttf");

    sf::Font fontAM;
    fontAM.loadFromFile("../cmake_modules/Amatic.ttf");

    sf::Font fontPF;
    fontPF.loadFromFile("../cmake_modules/Pacifico.ttf");

    sf::Text label;
    label.setCharacterSize(50);
    int logox = 100;
    int logoy = 20;
    label.setPosition(logox,logoy);
    label.setFont(fontOS);
    int label_alp = 255;
    label.setFillColor(sf::Color(255,255,255,label_alp));




    sf::Text shadow;
    shadow.setCharacterSize(50);
    int shadowx = 100;
    int shadowy = 150;
    shadow.scale(1.25,-.9);
    shadow.setPosition(shadowx,shadowy);
    int shadow_alp = 100;
    shadow.setFillColor(sf::Color(240,255,240,shadow_alp));
    shadow.setFont(fontOS);


    //text input box
    Typing typing;
    sf::RectangleShape box;
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(5);
    box.setOutlineColor(sf::Color::White);
    box.setPosition(100,300);
    sf::Vector2f mySize(800,55);
    box.setSize(mySize);

    Slider slider_size("Size",100,200,200,400);
    Slider slider_shift_horizontal("Horizontal",100,400,300,450);
    Slider slider_shift_vertical("Vertical",100,400,300,500);
    Slider slider_skew("Skew",100,400,300,550);
    Slider shadow_horizontal("Shadow_Horizontal",100,500,400,600);
    Slider shadow_vertical("Shadow_Vertical",100,500,400,650);
    Slider shadow_opacity("Shadow_Opacity",100,500,400,700);
    Slider label_opacity("Text_Opacity",100,500,400,750);
    Slider label_rotate("Rotate",100,500,400,850);
    //bool onBlink = true;


    vector<string> optionList ={"Option", "Save", "Exit"};
    Menu optionMenu(730,8,"",optionList);

    vector<string> fontList ={"OpenSans", "Amatic", "Pacifico"};
    Menu fontMenu(100,800,"Font",fontList);

    vector<string> colorList ={"White","Red", "Green", "Blue"};
    Menu colorMenu(400,800,"Color",colorList);

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
                cout<<"x:"<<x<<", y:"<<y<<endl;

                if(x>100 && x<900 && y>300 && y<350){   //check if mouse clicked on the textbox
                    typing.clickedOn(true);
                    box.setOutlineColor(sf::Color::Yellow);
                }else{
                    typing.clickedOn(false);
                    box.setOutlineColor(sf::Color::White);
                }

                //check Menu subItems:
                if(fontMenu.clicked){
                    for(int i=0;i<fontMenu.processedMenuItems.size();i++){
                        auto item = fontMenu.processedMenuItems[i];
                        if( x> item->itmx-10 &&
                            x< item->itmx-10+150 &&
                            y> item->itmy-30 &&
                            y< item->itmy){
                                //set menu name
                                fontMenu.selectedName.setString(item->label.getString());
                                //change font
                                switch(i){
                                    case 0:
                                        label.setFont(fontOS);
                                        break;
                                    case 1:
                                        label.setFont(fontAM);
                                        break;
                                    case 2:
                                        label.setFont(fontPF);
                                        break;
                                    default:
                                        label.setFont(fontOS);
                                }
                        }
                    }
                }

                //check Option Menu subItems:
                if(optionMenu.clicked){
                    for(int i=0;i<optionMenu.processedMenuItems.size();i++){
                        auto item = optionMenu.processedMenuItems[i];
                        if( x> item->itmx-10 &&
                            x< item->itmx-10+150 &&
                            y> item->itmy-30 &&
                            y< item->itmy){
                            switch(i){
                                case 0:
                                    break;
                                case 1:
                                    saveLogo(window,"mySavedLogo.png");
                                    cout<<"Logo Saved"<<endl;
                                    break;
                                case 2:
                                    cout<<"closing"<<endl;
                                    window.close();
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                }

                //check Color Menu subItems:
                if(colorMenu.clicked){
                    for(int i=0;i<colorMenu.processedMenuItems.size();i++){
                        auto item = colorMenu.processedMenuItems[i];
                        if( x> item->itmx-10 &&
                            x< item->itmx-10+150 &&
                            y> item->itmy-30 &&
                            y< item->itmy){
                            colorMenu.selectedName.setString(item->label.getString());
                            switch(i){
                                case 0:
                                    break;
                                case 1:
                                    label.setFillColor(sf::Color::Red);
                                    break;
                                case 2:
                                    label.setFillColor(sf::Color::Green);
                                    break;
                                case 3:
                                    label.setFillColor(sf::Color::Blue);
                                    break;
                                default:
                                    label.setFillColor(sf::Color::White);
                                    break;
                            }
                        }
                    }
                }

                //check menu
                if( x>fontMenu.orgX+100 && x<fontMenu.orgX+100+150
                    && y>fontMenu.orgY && y<fontMenu.orgY+30){   //check if mouse clicked on the textbox
                    fontMenu.box.setOutlineColor(sf::Color::Yellow);
                    fontMenu.clicked = true;
                }else{
                    fontMenu.clicked =false;
                    fontMenu.box.setOutlineColor(sf::Color::White);
                }

                //check option menu
                if( x>optionMenu.orgX+100 &&
                    x<optionMenu.orgX+100+150&&
                    y>optionMenu.orgY &&
                    y<optionMenu.orgY+30){   //check if mouse clicked on the textbox
                    optionMenu.box.setOutlineColor(sf::Color::Yellow);
                    optionMenu.clicked = true;
                }else{
                    optionMenu.clicked =false;
                    optionMenu.box.setOutlineColor(sf::Color::White);
                }

                //check color menu
                if( x>colorMenu.orgX+100 &&
                    x<colorMenu.orgX+100+150&&
                    y>colorMenu.orgY &&
                    y<colorMenu.orgY+30){   //check if mouse clicked on the textbox
                    colorMenu.box.setOutlineColor(sf::Color::Yellow);
                    colorMenu.clicked = true;
                }else{
                    colorMenu.clicked =false;
                    colorMenu.box.setOutlineColor(sf::Color::White);
                }


                //check Size slider
                if( x>slider_size.knobx -20 &&
                    x<slider_size.knobx+20 &&
                    y>slider_size.knoby-20 &&
                    y<slider_size.knoby+20){
                        //reset knob's x position;
                        slider_size.knobx = x;
                        //reset knob's drawing position.
                        slider_size.knob.setPosition(x,slider_size.knoby); //x is mouse position, y is knob position
                        label.setCharacterSize(50+ (x-100)/5);
                }

                //check Horizontal Shift slider
                if( x>slider_shift_horizontal.knobx -20 &&
                    x<slider_shift_horizontal.knobx+20 &&
                    y>slider_shift_horizontal.knoby-20 &&
                    y<slider_shift_horizontal.knoby+20){
                    //reset knob's x position;
                    slider_shift_horizontal.knobx = x;
                    //reset knob's drawing position.
                    slider_shift_horizontal.knob.setPosition(x,slider_shift_horizontal.knoby); //x is mouse position, y is knob position
                    logox = x-300;
                    label.setPosition(logox,logoy);
                }

                //check Vertical Shift slider
                if( x>slider_shift_vertical.knobx -20 &&
                    x<slider_shift_vertical.knobx+20 &&
                    y>slider_shift_vertical.knoby-20 &&
                    y<slider_shift_vertical.knoby+20){
                    //reset knob's x position;
                    slider_shift_vertical.knobx = x;
                    //reset knob's drawing position.
                    slider_shift_vertical.knob.setPosition(x,slider_shift_vertical.knoby); //x is mouse position, y is knob position
                    logoy = x-380;
                    label.setPosition(logox,logoy);
                }


                //check Skew slider
                if( x>slider_skew.knobx -20 &&
                    x<slider_skew.knobx+20 &&
                    y>slider_skew.knoby-20 &&
                    y<slider_skew.knoby+20){

                    if(x>slider_skew.knobx){
                        shadow.scale(1, 1.005);
                    }else{
                        shadow.scale(1, 0.995);
                    }
                    //reset knob's x position;
                    slider_skew.knobx = x;
                    //reset knob's drawing position.
                    slider_skew.knob.setPosition(x,slider_skew.knoby); //x is mouse position, y is knob position
                    //cout<<-0.5 + x*0.01<<endl;
                }

                //check Shadow Horizontal Shift slider
                if( x>shadow_horizontal.knobx -20 &&
                    x<shadow_horizontal.knobx+20 &&
                    y>shadow_horizontal.knoby-20 &&
                    y<shadow_horizontal.knoby+20){
                    //reset knob's x position;
                    shadow_horizontal.knobx = x;
                    //reset knob's drawing position.
                    shadow_horizontal.knob.setPosition(x,shadow_horizontal.knoby); //x is mouse position, y is knob position
                    shadowx = x-380;
                    shadow.setPosition(shadowx,shadowy);
                }

                //check Shadow Vertical Shift slider
                if( x>shadow_vertical.knobx -20 &&
                    x<shadow_vertical.knobx+20 &&
                    y>shadow_vertical.knoby-20 &&
                    y<shadow_vertical.knoby+20){
                    //reset knob's x position;
                    shadow_vertical.knobx = x;
                    //reset knob's drawing position.
                    shadow_vertical.knob.setPosition(x,shadow_vertical.knoby); //x is mouse position, y is knob position
                    shadowy = x-350;
                    shadow.setPosition(shadowx,shadowy);
                }

                //check Shadow Opacity slider
                if( x>shadow_opacity.knobx -20 &&
                    x<shadow_opacity.knobx+20 &&
                    y>shadow_opacity.knoby-20 &&
                    y<shadow_opacity.knoby+20){
                    //reset knob's x position;
                    shadow_opacity.knobx = x;
                    //reset knob's drawing position.
                    shadow_opacity.knob.setPosition(x,shadow_opacity.knoby); //x is mouse position, y is knob position
                    shadow_alp = x-200;
                    shadow.setFillColor(sf::Color(240,255,240,shadow_alp));
                }

                //check Label Opacity slider
                if( x>label_opacity.knobx -20 &&
                    x<label_opacity.knobx+20 &&
                    y>label_opacity.knoby-20 &&
                    y<label_opacity.knoby+20){
                    //reset knob's x position;
                    label_opacity.knobx = x;
                    //reset knob's drawing position.
                    label_opacity.knob.setPosition(x,label_opacity.knoby); //x is mouse position, y is knob position
                    label_alp = x*0.8+45;
                    label.setFillColor(sf::Color(255,255,255,label_alp));
                }

                //check Text Rotation slider
                if( x>label_rotate.knobx -20 &&
                    x<label_rotate.knobx+20 &&
                    y>label_rotate.knoby-20 &&
                    y<label_rotate.knoby+20){
                    if(x>label_rotate.knobx){
                        label.rotate(x*0.01);
                    }else{
                        label.rotate(x*-0.01);
                    }

                    //reset knob's x position;
                    label_rotate.knobx = x;
                    //reset knob's drawing position.
                    label_rotate.knob.setPosition(x,label_rotate.knoby); //x is mouse position, y is knob position
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

        label.setString(typing.msg.getString());
        shadow.setString(typing.msg.getString());
        window.draw(label);
        window.draw(shadow);
        typing.drawTo(window);
        slider_size.drawTo(window);
        slider_shift_horizontal.drawTo(window);
        slider_shift_vertical.drawTo(window);
        slider_skew.drawTo(window);
        shadow_horizontal.drawTo(window);
        shadow_vertical.drawTo(window);
        label_opacity.drawTo(window);
        shadow_opacity.drawTo(window);


        label_rotate.drawTo(window);
        fontMenu.drawTo(window);
        optionMenu.drawTo(window);
        colorMenu.drawTo(window);

        window.draw(box);
        window.display();

    }
    return 0;
}
