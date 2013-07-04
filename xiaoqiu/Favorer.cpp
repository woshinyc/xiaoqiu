//
//  Favorer.cpp
//  NycGame
//
//  Created by NycMac on 13-6-10.
//
//

#include "Favorer.h"
#define MAXSpeed 10
#define MINSpeed 1
using namespace cocos2d;
bool Favorer::init()
{
    if (!CCSprite::init()) {
        return false;
    }
    this->schedule(schedule_selector(Favorer::step), 1/60);
    return true;
}
void Favorer::step()
{
    if (&targetPoint!=NULL) {
        if (fabsf(this->getPositionX()-targetPoint.x)<moveSpeed) {
            this->setPositionX(targetPoint.x);
            //this->setPosition(ccp(targetPoint.x, 10));
        }else
        {
            if (this->getPositionX()>targetPoint.x) {
                this->setPositionX(this->getPositionX()-moveSpeed);
            }else{
                this->setPositionX(this->getPositionX()+moveSpeed);
            }
        }
     
        
    }

}
Favorer *Favorer::getFavorer()
{
    Favorer *favorer = Favorer::create();
    favorer->initWithFile("favorerImg.jpg", CCRectMake(0, 0, 100, 15));
    return favorer;

}


 void Favorer::assignmentProps(PropsType pType)
{
    switch (pType) {
        case gongzih_Speed_up:
            if (this->moveSpeed<MAXSpeed) {
                this->moveSpeed++;
            };
            break;
        case gongzih_Speed_down:
            if (this->moveSpeed>MINSpeed) {
                this->moveSpeed--;
            };
            break;
        default:
            break;
    }

}