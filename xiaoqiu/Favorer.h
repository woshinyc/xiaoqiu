//
//  Favorer.h
//  NycGame
//
//  Created by NycMac on 13-6-10.
//
//

#ifndef __NycGame__Favorer__
#define __NycGame__Favorer__

#include <iostream>
#include "SpriteBase.h"
#include "enumWhole.h"
class Favorer:public SpriteBase
{

public:
    virtual bool init();
    void step();
    float moveSpeed;
    CREATE_FUNC(Favorer);
    static Favorer *getFavorer();
    cocos2d::CCLayer *mainLayer;
    cocos2d::CCPoint targetPoint;
    CCArray **mainAr;
    void assignmentProps(PropsType pType);
    
};

#endif /* defined(__NycGame__Favorer__) */
