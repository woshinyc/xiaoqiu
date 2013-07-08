//
//  MainBall.cpp
//  NycGame
//
//  Created by NycMac on 13-6-10.
//
//

#include "MainBall.h"
#include "HelloWorldScene.h"
#include "Tool.h"


bool MainBall::init()
{
    if (!CCSprite::init()) {
        return false;
    }

    return true;
}

MainBall* MainBall::getBall()
{
    MainBall *ball=MainBall::create();
    ball->harmNum=40;
   ball->initWithSpriteFrameName("ball.png");

 
    return ball;
}

void MainBall::assignmentProps(PropsType pType,CCLayer *mainLayer)
{
    switch (pType) {
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

void MainBall::ballAbrothers(CCNode *mainLayer)    //创建小球
{
     this->bType=createBrothers||bType;
    MainBall *ball;
    HelloWorld *lay= (HelloWorld *)mainLayer;
    for (int n=1; n<=2; n++) {
        ball=MainBall::getBall();
        ball->speed=speed;
        ball->isFire=true;
        ball->setSpeedAndRadian(speed, this->radian*2.0/3*M_PI*n);
        ball->setPosition(this->getPosition());
        
        lay->ballArray->addObject(ball);
        lay->addChild(ball);
        CCParticleSun* m_emitter = CCParticleSun::createWithTotalParticles(60);
        m_emitter->setPosition(this->getPosition());
        m_emitter->retain();
        
        m_emitter->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire-grayscale.png") );
        m_emitter->cocos2d::CCParticleSystem::setTotalParticles(0);
        ball->m_emitter=m_emitter;
        mainLayer-> addChild(m_emitter);
    }
  
    
}
void MainBall::ballAsmall()       //变小
{
    this->bType=becomeSmall|bType;
    this->setScale(0.5);
}
void MainBall::ballAstrong()     //变成铅球
{
     this->bType=becomeStrong|bType;
       CCSpriteFrame *frame=CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("ball2.png");
       this->setDisplayFrame(frame);

}
void MainBall::ballAfireball()   //变成火球
{
    bType=becomeFireBall|bType;
    harmNum=40;
    if (m_emitter!=NULL) {
          m_emitter->cocos2d::CCParticleSystem::setTotalParticles(60);
    }
   
}
void MainBall::ballAspeed_up()   //速度提升
{
 this->bType=ball_Speed_up|bType;
    speed++;
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
    return harm;
}




