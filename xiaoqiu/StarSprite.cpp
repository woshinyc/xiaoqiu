//
//  StarSprite.cpp
//  NycGame
//
//  Created by NycMac on 13-7-1.
//
//

#include "StarSprite.h"
bool StarSprite::init()
{
    if (!CCSprite::init()) {
        return false;
    }
    return true;

}

StarSprite *StarSprite::getStar()
{
    StarSprite *star=StarSprite::create();
    star->initWithSpriteFrameName("ball.png");

    CCArray *animFrames = CCArray::create();
    CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ball.png");
    animFrames->addObject(frame);
     frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ball2.png");
     animFrames->addObject(frame);
    CCAnimation *ani=CCAnimation::createWithSpriteFrames(animFrames,0.5);
    CCRepeatForever* mFly=CCRepeatForever::create(CCAnimate::create(ani));
    star->runAction(mFly);
//    CCActionInterval *mb=CCMoveBy::create(1, ccp(130, 0));
//    CCActionInterval *mb2=CCMoveBy::create(1, ccp(-130, 0));
//    CCActionInterval *sqa=CCSequence::create(mb,mb2,NULL);
//    
// //   CCRepeat*ss= CCRepeat::create(sqa, 2);
//    CCRepeatForever*bb=CCRepeatForever::create(sqa);
// //   CCActionInstant::
//    
//    star->runAction(bb);
    return star;

}