//
//  SmallBox.cpp
//  NycGame
//
//  Created by NycMac on 13-6-10.
//
//

#include "SmallBox.h"
using namespace cocos2d;
//using namespace CocosD

bool SmallBox::init()
{
    if (!CCSprite::init()) {
        return false;
    }
    return true;
}
SmallBox*SmallBox::getBox(CCDictionary *TMLdic,CCSize boxSize)
{
  SmallBox *box=SmallBox::create();
    box->initWithFile("commonBoxImg.jpg",CCRectMake(0, 0, boxSize.width, boxSize.height));
    box->TMLdic=TMLdic;
    box->setHealthNum(8);
    return box;
}
SmallBox* SmallBox::getBox(BoxInfo *info,CCSize boxSize)
{
    SmallBox *box=SmallBox::create();
    const char *nameStr;
    switch (info->boxType) {
        case commonBox:
            nameStr="commonBoxImg.jpg";
            box->setHealthNum(8);
            break;
        case woodBox:
            nameStr="woodBoxImg.jpg";
            box->setHealthNum(12);
            break;
        case ironBox:
           nameStr="ironBoxImg.jpg";
            box->setHealthNum(16);
            break;
            
        default:
            break;
    }
    box->initWithFile(nameStr,CCRectMake(0, 0, boxSize.width, boxSize.height));
    return box;
}
//CCRect SmallBox::getRectangle(cocos2d::CCPoint po)
//{
//    float x=po.x-this->getContentSize().width*this->getAnchorPoint().x;
//    float y=po.y-this->getContentSize().height*(1-this->getAnchorPoint().y);
//    CCRect rect=CCRectMake(x, y, this->getContentSize().width, this->getContentSize().height);
//    return rect;
//}
