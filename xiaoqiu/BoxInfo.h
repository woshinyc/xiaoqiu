//
//  BoxInfo.h
//  NycGame
//
//  Created by NycMac on 13-6-10.
//
//

#ifndef __NycGame__BoxInfo__
#define __NycGame__BoxInfo__

#include <iostream>
#include "enumWhole.h"
#include "ObjectBase.h"
#include "enumWhole.h"
class BoxInfo :public ObjectBase
{
public:
    cocos2d::CCString *imgName;
    BoxType boxType;
    bool isProps;
    PropsType pType;
    
};
#endif /* defined(__NycGame__BoxInfo__) */
