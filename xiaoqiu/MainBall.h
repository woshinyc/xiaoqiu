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
    int bType;
    CCParticleSun* m_emitter ;
    
    
    //ACTION
    void assignmentProps(PropsType pType,cocos2d::CCLayer *mainLayer);
    //***********
 
    void ballAbrothers(cocos2d::CCNode *mainLayer);
    void ballAsmall();
    void ballAstrong();
    void ballAfireball();
    void ballAspeed_up();
    //***********
     int detectWithRect(CCRect targetRect,bool* collisionBool);
    
    //**********
   
};
#endif /* defined(__NycGame__MainBall__) */
