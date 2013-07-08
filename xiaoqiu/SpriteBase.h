//
//  SpriteBase.h
//  NycGame
//
//  Created by NycMac on 13-6-12.
//
//

#ifndef __NycGame__SpriteBase__
#define __NycGame__SpriteBase__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class SpriteBase:public cocos2d::CCSprite
{
    
public:
    virtual bool init();
    CREATE_FUNC(SpriteBase);
    int harmNum;            //伤害力
    float speedX,speedY;
    float speed,radian;
    bool isUseless;         //无用 。删除用
    void setHealthNum(int num);
    int  getHealthNum();
    void beAttack(int num); //遭受攻击
      CCPoint getCenterPoint(); // 获得中心点
     cocos2d::CCRect getRectangle();
      void setSpeedAndRadian(float _speed,float _radian);
private:
     int healthNum;          //生命值
  
  
  
};
#endif /* defined(__NycGame__SpriteBase__) */
