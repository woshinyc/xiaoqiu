//
//  MainBall.cpp
//  NycGame
//
//  Created by NycMac on 13-6-10.
//
//

#include "MainBall.h"
#include "SmallBall.h"
#include "HelloWorldScene.h"
#include "Tool.h"


bool MainBall::init()
{
    if (!CCSprite::init()) {
        return false;
    }
    smallBallList=CCArray::create();
    smallBallList->retain();
        this->schedule(schedule_selector(MainBall::MainBallstep), 1/60);

    return true;
}

MainBall* MainBall::getBall()
{
    MainBall *ball=MainBall::create();
    ball->harmNum=4;

   ball->initWithSpriteFrameName("ball.png");
   CCParticleSun* m_emitter = CCParticleSun::createWithTotalParticles(60);
    m_emitter->setPosition(ccp(ball->getContentSize().width/2, ball->getContentSize().height/2));
    m_emitter->retain();
    ball-> addChild(m_emitter);
    m_emitter->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire-grayscale.png") );
    m_emitter->setVisible(false);
    ball->m_emitter=m_emitter;
    return ball;
}
/////
void MainBall::sportSmallBall()
{
    int smallBnum =smallBallList->count();
    for (int n=0; n<smallBnum; n++) {
        SmallBall *smallB=(SmallBall *)smallBallList->objectAtIndex(n);
        smallB->smallBallChange();
        smallB->setPositionX(smallB->getPosition().x+smallB->speedX);
        smallB->setPositionY(smallB->getPosition().y+smallB->speedY);
    }


}
void MainBall::MainBallstep()
{
//    switch (this->bType) {
//        case ball_Mother_Son_Type:
//            this->sportSmallBall();
//            break;
//            
//        default:
//            break;
//    }
    if (this->bType||ball_Mother_Son_Type) {
        this->sportSmallBall();
    }
}
void MainBall::setSpeedAndRadian(float radian)
{
    ballradian=radian;
    speedX=speed *cosf(radian);
    speedY=speed *sinf(radian);

}

void MainBall::assignmentProps(PropsType pType,CCLayer *mainLayer)
{
    switch (pType) {
        case createMother_Son:
            
            this->ballAmother_son();
            break;
        case createBrothers:
           
            this->ballAbrothers(mainLayer);
            break;
        case becomeSmall:
            
            this->ballAsmall();
            break;
        case becomeStrong:
           
            this->ballAstrong();
            break;
        case becomeFireBall:
           
            this->ballAfireball();
            break;
        case ball_Speed_up:
           
            this->ballAspeed_up();
            break;
        default:
            break;
    }
}

#pragma mark - 改变小球的状态
void MainBall::ballAmother_son()   //子母球
{
this->bType=createMother_Son||bType;
    SmallBall *smallBall=SmallBall::getSmallBall();
    
    smallBall->speed=-smallSpeed;
    if (zhengfu==0) {
        smallBall->radian=smallSpeed;
    }else{
        smallBall->radian=-smallSpeed;
    }
    
    smallBall->setPosition(ccp(30, 30));
    smallBall->setScale(0.5);
    this->addChild(smallBall);
    smallBallList->addObject(smallBall);

}
void MainBall::ballAbrothers(CCNode *mainLayer)    //创建小球
{
     this->bType=createBrothers||bType;
    MainBall *ball;
    HelloWorld *lay= (HelloWorld *)mainLayer;
    for (int n=1; n<=2; n++) {
        ball=MainBall::getBall();
        ball->speed=speed;
        ball->isFire=true;
        ball->setSpeedAndRadian(this->ballradian*2.0/3*M_PI*n);
        ball->setPosition(this->getPosition());
        
        lay->ballArray->addObject(ball);
        lay->addChild(ball);
    }
  
    
}
void MainBall::ballAsmall()       //变小
{
    this->bType=becomeSmall||bType;
    this->setScale(0.5);
}
void MainBall::ballAstrong()     //变成铅球
{
     this->bType=becomeStrong||bType;
       CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ball2.png");
       this->setDisplayFrame(frame);

}
void MainBall::ballAfireball()   //变成火球
{
    this->bType=becomeFireBall||bType;
    if (m_emitter!=NULL) {
         m_emitter->setVisible(true);
    }
   
}
void MainBall::ballAspeed_up()   //速度提升
{
 this->bType=ball_Speed_up||bType;
}

#pragma mark -小球自检测
int MainBall::detectWithRect(CCRect targetRect,bool* collisionBool)
{
    int harm=0;
    CCRect ballRect=this->getRectangle();
    if (ballRect.intersectsRect(targetRect))
    {
        *collisionBool=true;
        harm=harm+this->harmNum;
    }
   harm+= this->smalldetectWithRect(targetRect);
    
//    int smallBallNum=smallBallList->count();
//    SmallBall *ball;
//    CCRect smallRect;
//    for (int n=0; n<smallBallNum; n++) {
//      ball =(SmallBall *)smallBallList->objectAtIndex(n);
//
//        
//        smallRect=ball->getRectangle();
//        smallRect=Tool::MakeOffset(this->convertToWorldSpace(ball->getPosition()), smallRect);//计算小小球在屏幕上的位置
//        if (smallRect.intersectsRect(targetRect)) {
//            harm=harm+this->harmNum;
//        }
//    }
    
    
    return harm;
}

#pragma mark -小小球自检测
int MainBall::smalldetectWithRect(CCRect targetRect)
{
    int harm=0;
 
    int smallBallNum=smallBallList->count();
    SmallBall *ball;
    CCRect smallRect;
    for (int n=0; n<smallBallNum; n++) {
        ball =(SmallBall *)smallBallList->objectAtIndex(n);
        
        
        smallRect=ball->getRectangle();
        smallRect=Tool::MakeOffset(this->convertToWorldSpace(ball->getPosition()), smallRect);//计算小小球在屏幕上的位置
        if (smallRect.intersectsRect(targetRect)) {
            harm=harm+ball->harmNum;
        }
    }
    
    
    return harm;
}


