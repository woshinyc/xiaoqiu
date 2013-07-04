//
//  Tool.h
//  NycGame
//
//  Created by NycMac on 13-6-12.
//
//

#ifndef __NycGame__Tool__
#define __NycGame__Tool__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;
class Tool:public cocos2d::CCObject
{
public:
   static CCPoint MakeOffset(CCPoint pointOrigin ,CCPoint pointOffset); //传入偏移点和原点，得到偏移后的座标
    static CCPoint getOffset(CCPoint pointOrigin,CCPoint otherPoint);//传入两个点。得到点b相对点a的偏移座标
    static CCRect MakeOffset(CCPoint pointOffset,CCRect rect);//传入便宜点 和原Rect 得到偏移后的Rect
};

#endif /* defined(__NycGame__Tool__) */
