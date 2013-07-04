//
//  MainBall.h
//  NycGame
//
//  Created by NycMac on 13-6-10.
//
//

#ifndef __NycGame__MainBall__
#define __NycGame__MainBall__

#include <iostream>

#include "SpriteBase.h"
#include "enumWhole.h"
using namespace cocos2d;

class MainBall:public SpriteBase
{
public:
    virtual bool init();
    CREATE_FUNC(MainBall);
    static MainBall *getBall();
    bool isFire;
    float speedX,speedY;
    float speed,ballradian;
    int bType;
    CCParticleSun* m_emitter ;
    
    
    //ACTION
    void setSpeedAndRadian(float radian);
    void assignmentProps(PropsType pType,cocos2d::CCLayer *mainLayer);
    cocos2d::CCArray *smallBallList;
    //***********
    void ballAmother_son();
    void ballAbrothers(cocos2d::CCNode *mainLayer);
    void ballAsmall();
    void ballAstrong();
    void ballAfireball();
    void ballAspeed_up();
    //***********
    void sportSmallBall();
     int detectWithRect(CCRect targetRect,bool* collisionBool);
    //**********
     void MainBallstep();
   
};
#endif /* defined(__NycGame__MainBall__) */
