//
//  SmallBall.h
//  NycGame
//
//  Created by NycMac on 13-6-25.
//
//

#ifndef __NycGame__SmallBall__
#define __NycGame__SmallBall__

#include <iostream>
#include "SpriteBase.h"

class SmallBall:public SpriteBase
{
public:
    virtual bool init();
    CREATE_FUNC(SmallBall);
    static SmallBall *getSmallBall();

    void smallBallChange();
    void setSpeedAndRadian(float speed,float radian);
    float speedX,speedY;
    float speed,radian;
    
   
};
#endif /* defined(__NycGame__SmallBall__) */
