#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Favorer.h"
#include "enumWhole.h"
#include "Props.h"
#include "MainBall.h"
class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();

    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    void fireBall(MainBall *ball);
    bool isWin;
    
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
     CCPoint tileCoordForPosition(CCPoint position);
    void creatProps(PropsType pType ,cocos2d::CCPoint po);
    void creatBall();
    void step();
    void test();
    
    void getAllStar();

    void creatBox();
    CCTMXTiledMap* _tileMap;
    CCTMXLayer *boxTMXlayer;
    CCTMXLayer *Floatingayer;

    cocos2d::CCSize windowSize;
    Favorer *favorer;
   cocos2d::CCArray *boxArray;
    cocos2d::CCArray *ballArray;
    cocos2d::CCArray *propsArray;
    cocos2d::CCArray *starArray;
    cocos2d::CCPoint beganTouchLocation;
    

    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
