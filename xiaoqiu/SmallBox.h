//
//  SmallBox.h
//  NycGame
//
//  Created by NycMac on 13-6-10.
//
//

#ifndef __NycGame__SmallBox__
#define __NycGame__SmallBox__

#include <iostream>
#include "SpriteBase.h"
#include "BoxInfo.h"


class SmallBox :public SpriteBase
{
public:
    virtual bool init();
    CREATE_FUNC(SmallBox);
    BoxInfo *info;
    static SmallBox* getBox(BoxInfo *info ,CCSize boxSize);
    static SmallBox* getBox(CCDictionary *TMLdic,CCSize boxSize);
    cocos2d::CCRect boxRect;
    CCDictionary *TMLdic;
};
#endif /* defined(__NycGame__SmallBox__) */
