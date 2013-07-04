//
//  Tool.cpp
//  NycGame
//
//  Created by NycMac on 13-6-12.
//
//

#include "Tool.h"


CCPoint Tool::MakeOffset(CCPoint pointOrigin ,CCPoint pointOffset)
{
    CCPoint newPoint = CCPointMake(pointOrigin.x+pointOffset.x, pointOrigin.y+pointOffset.y);
    return newPoint;

}
CCPoint Tool::getOffset(CCPoint pointOrigin,CCPoint otherPoint)
{
    CCPoint offsetPoint=CCPointMake(otherPoint.x-pointOrigin.x, otherPoint.y-pointOrigin.y);
    return offsetPoint;

}
CCRect Tool::MakeOffset(CCPoint pointOffset,CCRect rect)
{
   CCPoint newPo= Tool::MakeOffset(ccp(rect.origin.x, rect.origin.y), pointOffset);
    CCRect newRect=CCRectMake(newPo.x, newPo.y, rect.size.width,rect.size.height);
    return newRect;
}
