//
//  Favorer.cpp
//  NycGame
//
//  Created by NycMac on 13-6-10.
//
//

#include "Favorer.h"
#include "MainBall.h"
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
          
        }else
        {
            if (this->getPositionX()>targetPoint.x) {
                this->setPositionX(this->getPositionX()-moveSpeed);
            }else{
                this->setPositionX(this->getPositionX()+moveSpeed);
            }
        }
     
        CCArray *arr=*mainAr;
        if (arr!=NULL&&arr->count()>0) {
            for (int n=0; n<arr->count(); n++) {
                MainBall *bal=(MainBall *)arr->objectAtIndex(n);
                if (bal->isFire==false) {
                    bal->setPositionX(this->getPositionX());
                }
                
            }
        }
    }

}
Favorer *Favorer::getFavorer()
{
    Favorer *favorer = Favorer::create();
    
     CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("favorerImg.jpg");
    CCTexture2D *pNewTexture =pFrame->getTexture();
    CCRect rect=CCRect(pFrame->getRect().origin.x, pFrame->getRect().origin.y, 100, 15);
    favorer->initWithTexture(pNewTexture, rect);
 
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