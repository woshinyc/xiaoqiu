//
//  Props.cpp
//  NycGame
//
//  Created by NycMac on 13-6-15.
//
//

#include "Props.h"
using namespace cocos2d;
bool Props::init()
{
    if (!CCSprite::init()) {
        return false;
    }
    return true;
}

Props *Props::getProps(PropsType type)
{
    Props *propsStar = Props::create();

    ccColor3B color;
    const char *string;
    switch (type) {
        case createMother_Son:
            string="Icon-Small.png";
            //color=ccc3(1, 1, 1);
            color=ccWHITE;
            break;
        case createBrothers:
            string="Icon-Small.png";
             color=ccYELLOW;
            break;
        case becomeSmall:
            string="Icon-Small.png";
            color=ccBLUE;
            break;
        case becomeStrong:
            string="Icon-Small.png";
            color=ccGREEN;
            break;
        case becomeFireBall:
            string="Icon-Small.png";
            color=ccRED;
            break;
        case ball_Speed_up:
            string="Icon-Small.png";
            color=ccMAGENTA;
            break;
        case gongzih_Speed_up:
            string="Icon-Small.png";
             color=ccBLACK;
            break;
        case gongzih_Speed_down:
            string="Icon-Small.png";
            color=ccORANGE;
            break;
        default:
            break;
    }

    propsStar->initWithFile(string);
    propsStar->propsType=type;
    propsStar->setColor(color);
    return propsStar;

}