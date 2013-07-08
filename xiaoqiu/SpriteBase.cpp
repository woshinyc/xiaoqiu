//
//  SpriteBase.cpp
//  NycGame
//
//  Created by NycMac on 13-6-12.
//
//

#include "SpriteBase.h"

bool SpriteBase::init()
{
    if (!SpriteBase::init()) {
        return false;
    }
    return true;
}
CCPoint SpriteBase::getCenterPoint()
{
  CCRect rect= this->getRectangle();
    return ccp(rect.origin.x+rect.size.width*0.5,rect.origin.y+rect.size.height*0.5);
}
CCRect SpriteBase::getRectangle()
{
    float x=this->getPosition().x-this->getContentSize().width*this->getAnchorPoint().x;
    float y=this->getPosition().y-this->getContentSize().height*this->getAnchorPoint().y;
    CCRect rect=CCRectMake(x, y, this->getContentSize().width, this->getContentSize().height);
//    CCLog("aax=%f,y=%f w=%f,h=%f",x,y,rect.size.width,rect.size.height);
    return rect;
}

void SpriteBase::setHealthNum(int num)
{
    healthNum=num;
    if (healthNum<=0) {
        this->isUseless=true;
    }
}
int  SpriteBase::getHealthNum()
{
    return healthNum;

}
void SpriteBase::beAttack(int num)
{
    this->setHealthNum(healthNum-num);
}

void SpriteBase::setSpeedAndRadian(float _speed,float _radian)
{
    radian=_radian;
    speedX=_speed *cosf(_radian);
    speedY=_speed *sinf(_radian);
    
}
