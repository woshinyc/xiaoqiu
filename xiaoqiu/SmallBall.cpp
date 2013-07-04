//
//  SmallBall.cpp
//  NycGame
//
//  Created by NycMac on 13-6-25.
//
//

#include "SmallBall.h"
using namespace cocos2d;
bool SmallBall::init()
{
    if (!CCSprite::init()) {
        return false;
    }
    
    return true;
}

SmallBall* SmallBall::getSmallBall()
{
    SmallBall *ball=SmallBall::create();
    ball->harmNum=3;
    ball->initWithFile("ball.png");
    return ball;
}

void SmallBall::smallBallChange()
{
    float addF=1.0/60*2*M_PI;
    radian=radian+addF;
    this->setSpeedAndRadian(speed, radian);

}
void SmallBall::setSpeedAndRadian(float speed,float radian)
{
    speedX=speed *cosf(radian);
    speedY=speed *sinf(radian);
     //CCLog("X=%i,Y=%i",speedX,speedY);
   
}


