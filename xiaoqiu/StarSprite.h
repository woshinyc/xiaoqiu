//
//  StarSprite.h
//  NycGame
//
//  Created by NycMac on 13-7-1.
//
//

#ifndef __NycGame__StarSprite__
#define __NycGame__StarSprite__

#include <iostream>
#include "SpriteBase.h"
USING_NS_CC;
class StarSprite :public SpriteBase
{
public:
    virtual bool init();
    CREATE_FUNC(StarSprite);

    
    static StarSprite* getStar();
   
};
#endif /* defined(__NycGame__StarSprite__) */
