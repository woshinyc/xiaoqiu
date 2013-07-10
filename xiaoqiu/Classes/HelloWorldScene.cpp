#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "SmallBox.h"
#include "BoxInfo.h"
#include "Tool.h"

#include "enumWhole.h"
#include "StarSprite.h"
#include "Obstacle.h"
#include "PropsObject.h"

using namespace cocos2d;
using namespace CocosDenshion;






CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    // 首先载入贴图集
    CCSpriteBatchNode *spriteBatch=CCSpriteBatchNode::create("mapT.png");
    this->addChild(spriteBatch);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mapT.plist");

    this->setTouchEnabled(true);
    boxArray=CCArray::create();
    ballArray=CCArray::create();
    propsArray=CCArray::create();
    obstacleArray=CCArray::create();
    propsTMXArray=CCArray::create();
    
    
    ballArray->retain();
    boxArray->retain();
    propsArray->retain();
    obstacleArray->retain();
    propsTMXArray->retain();
    
    
    
   windowSize = CCDirector::sharedDirector()->getWinSize();
    _tileMap=CCTMXTiledMap::create("lv001.tmx");
    addChild(_tileMap);
    boxTMXlayer=_tileMap->layerNamed("boxTMXlayer");
    obstaclelayer=_tileMap->layerNamed("obstaclelayer");
    propslayer=_tileMap->layerNamed("propslayer");

//    Floatingayer=_tileMap->layerNamed("Floatingayer");
//    this->creatBox();

    CCLog("w.w=%f w.h=%f",windowSize.width,windowSize.height);
    //*****************************************************************************
    //                创建数组
    //*****************************************************************


    //*****************************************************************************
    //                创建守护者
    //*****************************************************************

    favorer=Favorer::getFavorer();
    favorer->setPosition(ccp(windowSize.width/2, 10));
    favorer->moveSpeed=6.0;
    favorer->targetPoint=favorer->getPosition();
    favorer->mainAr=&ballArray;
    this->addChild(favorer);
    this->creatBall();
     this->getAllStar();
    this->getAllObstacle();
    this->getProps();
 
    //*****************************************************************************
    //                启动计时器
    //*****************************************************************
    this->schedule(schedule_selector(HelloWorld::step), 1/60);
    
    return true;
}

#pragma mark -创建砖块
 void HelloWorld::creatBox()
{
   
CCSize s = Floatingayer->getLayerSize();
    CCSize fanggeSize=Floatingayer->getMapTileSize();
    for (int x = 0; x<s.width; x++) {
        for (int y = 0; y<s.height; y++) {
            int gid = Floatingayer->tileGIDAt(ccp(x, y));
            if (gid !=0) {
                  CCDictionary *properties=_tileMap->propertiesForGID(gid);
                SmallBox *box=SmallBox::getBox(properties, fanggeSize);
               // box->setAnchorPoint(ccp(0, 1));
                box->setPosition(ccp(x*fanggeSize.width, windowSize.height- y*fanggeSize.height));
                box->boxRect=box->getRectangle();
                boxArray->addObject(box);
                this->addChild(box,1);
            }
        }
    }

}
#pragma mark - 帧判断
void HelloWorld::step()
{
    if (isWin==false&&starArray->count()<=0) {
        isWin=true;
    }
    if (isWin==true){
        //unschedule(schedule_selector(HelloWorld::step));
    }
    int ballNum=ballArray->count();
    int propNum=propsArray->count();
    // 保护者 
    CCRect favorerRect=favorer->getRectangle();
     // 道具检测
    for (int n=0; n<propNum;n++) {
        Props *propSprite=(Props *)propsArray->objectAtIndex(n);
        propSprite->setPositionY(propSprite->getPositionY()-PropSpeed);
        if (propSprite->isUseless==false&&favorerRect.intersectsRect(propSprite->getRectangle()))
        {
            MainBall *ball;
            propSprite->isUseless=true;
            switch (propSprite->propsType) {
                case createBrothers:
                    if(ballArray->count()>0)
                    {
                        ball =(MainBall *)ballArray->objectAtIndex(0);
                    }
                    ball->assignmentProps(createBrothers, this);
                    break;
                case becomeSmall:
                    if(ballArray->count()>0)
                    {
                        for (int n=0; n<ballArray->count(); n++) {
                            ball =(MainBall *)ballArray->objectAtIndex(n);
                            ball->assignmentProps(becomeSmall, this);
                        }
                     
                    }
                    
                    break;
                case becomeStrong:
                    
                    if(ballArray->count()>0)
                    {
                        for (int n=0; n<ballArray->count(); n++) {
                            ball =(MainBall *)ballArray->objectAtIndex(n);
                            ball->assignmentProps(becomeStrong, this);
                        }
                        
                    }
                    
                    break;
                case becomeFireBall:
                    if(ballArray->count()>0)
                    {
                        for (int n=0; n<ballArray->count(); n++) {
                            ball =(MainBall *)ballArray->objectAtIndex(n);
                           ball->assignmentProps(becomeFireBall, this);
                        }
                        
                    }
                     
                    break;
                case ball_Speed_up:
                    if(ballArray->count()>0)
                    {
                        for (int n=0; n<ballArray->count(); n++) {
                            ball =(MainBall *)ballArray->objectAtIndex(n);
                            ball->assignmentProps(ball_Speed_up, this);
                        }
                        
                    }
                    
                    break;
                case gongzih_Speed_up:
                    favorer->assignmentProps(gongzih_Speed_up);
                    break;
                case gongzih_Speed_down:
                     favorer->assignmentProps(gongzih_Speed_down);
                    break;
                default:
                    break;
            }
        }
    }
    // 小球检测
    for (int n=0;n<ballNum;n++)
    {
        MainBall *ball=(MainBall *)ballArray->objectAtIndex(n);
        if (ball->isFire==true)
        {
            ball->setPositionX(ball->getPosition().x+ball->speedX);
            ball->setPositionY(ball->getPosition().y+ball->speedY);
            ball->m_emitter->setPosition(ccp(ball->getPosition().x, ball->getPosition().y));
            if (ball->getPositionY()<0) {
                ball->isUseless=true;
                
            }
            //*****************得到碰撞点
            CCSize spriteSize=ball->getContentSize();

            CCPoint upPoint   =ball->convertToWorldSpace(ccp(spriteSize.width/2, spriteSize.height));
            CCPoint downPoint  =ball->convertToWorldSpace(ccp(spriteSize.width/2,0));
            CCPoint leftPoint  =ball->convertToWorldSpace(ccp(0,spriteSize.height/2));
            CCPoint rightPoint =ball->convertToWorldSpace(ccp(spriteSize.width,spriteSize.height/2));
            //setTextureRect
            //*****************得到碰撞点
           
            //*****************碰撞墙壁
            if (leftPoint.x<3) {
                ball->speedX=fabsf(ball->speedX);
            }
            
            if (rightPoint.x>windowSize.width-3) {
                ball->speedX=-fabsf(ball->speedX);
            }
            if (upPoint.y>windowSize.height-2) {
                ball->speedY=-fabsf(ball->speedY);
            }
            if (favorerRect.containsPoint(downPoint)) {
                //CCPoint touchPointInFavorer=Tool::getOffset(favorer->getPosition(), downPoint);
                CCPoint touchPointInFavorer=favorer->convertToNodeSpace(downPoint);
               // float radianCoefficient=favorer->getContentSize().width/2-touchPointInFavorer.x;
                float radianCoefficient=favorer->getContentSize().width-touchPointInFavorer.x;
                radianCoefficient=radianCoefficient/favorer->getContentSize().width;
                float speedRadian=(radianCoefficient*2/3.0+1/6.0)*M_PI ;
                ball->setSpeedAndRadian(ball->speed,speedRadian);
              
            }
            //*****************碰撞墙壁
            //*****************碰撞砖块
             CCPoint nextPo=Tool::MakeOffset(ball->getPosition(), ccp(ball->speedX,ball->speedY));
            if (nextPo.y>0) {
                CCPoint nextTMXPoint=this->tileCoordForPosition(nextPo);
                int boxtileGid = boxTMXlayer->tileGIDAt(nextTMXPoint);
                int obstacleGid=obstaclelayer->tileGIDAt(nextTMXPoint);
                int propGid=propslayer->tileGIDAt(nextTMXPoint);
                if (boxtileGid||obstacleGid) {
                    
                    int mapy= _tileMap->getMapSize().height-nextTMXPoint.y;//从左下算起的点Y
                    float x=(nextTMXPoint.x+0.5)*_tileMap->getTileSize().width;
                    float y=(mapy-0.5)*_tileMap->getTileSize().height;
                   
                    CCPoint boxPo=ccp(x,y);
                    CCPoint po= Tool::getOffset(boxPo,ball->getCenterPoint());
                    float radian=ccpToAngle(po);
                    if (radian<0) {
                        radian=radian+2*M_PI;
                    }
                    
                    if (radian>=M_PI_4&&radian<M_PI_2+M_PI_4) {
                    //上边缘
                        ball->speedY=fabsf(ball->speedY*1.01);
                        CCLog("上边缘");
                    }else if (radian>=M_PI_2+M_PI_4&&radian<M_PI+M_PI_4){
                    //左边缘
                         ball->speedX=-fabsf(ball->speedX*1.01);
                        CCLog("左边缘");
                    }else if (radian>=M_PI+M_PI_4&&radian<(2*M_PI-M_PI_4)) {
                    //下边缘
                        ball->speedY=-fabsf(ball->speedY*1.01);
                        CCLog("下边缘");
                    }else{
                    //右边缘
                        ball->speedX=fabsf(ball->speedX*1.01);
                        CCLog("右边缘");
                    }
                    if (obstacleGid) {
                        //如果为可摧毁的障碍物
                        if (obstacleArray!=NULL&&obstacleArray->count()>0) {
                            for (int n=0; n<obstacleArray->count(); n++) {
                                Obstacle *thisOb=(Obstacle*)obstacleArray->objectAtIndex(n);
                                if (thisOb->position.equals(nextTMXPoint)) {
                                    thisOb->HealthNum=thisOb->HealthNum-ball->harmNum;
                                    CCLog("hp=%i",thisOb->HealthNum);
                                    break;
                                }
                            }
                        }
                    }
                    
            }
                else if (propGid)
                {
                    if (propsTMXArray!=NULL&&propsTMXArray->count()>0) {
                        for (int n=0; n<propsTMXArray->count(); n++) {
                            PropsObject *thisPo=(PropsObject*)propsTMXArray->objectAtIndex(n);
                            if (thisPo->position.equals(nextTMXPoint)) {
                                
                                thisPo->HealthNum=thisPo->HealthNum-10;
                                int mapy= _tileMap->getMapSize().height-nextTMXPoint.y;//从左下算起的点Y
                                float x=(nextTMXPoint.x+0.5)*_tileMap->getTileSize().width;
                                float y=(mapy-0.5)*_tileMap->getTileSize().height;
                                
                                CCPoint boxPo=ccp(x,y);
                                this->creatProps(thisPo->propsType, boxPo);
        
                                break;
                            }
                        }
                    }
                }
 
            }
            //*****************碰撞砖块
            
           //*****************星星处理
            int starNum=starArray->count();
            for (int n=0; n<starNum; n++) {
                StarSprite*thisStar=(StarSprite*)starArray->objectAtIndex(n);
               CCRect StarCGRect=thisStar->getRectangle();
                CCRect ballRect=ball->getRectangle();
                if (StarCGRect.intersectsRect(ballRect)) {
                    thisStar->isUseless=true;
                   
                }
                
            }
            
           //*****************星星处理
        }
    }
    int boxNum=boxArray->count();
    for (int n=boxNum-1; n>=0; n--)
    {
        SmallBox *box=(SmallBox *)boxArray->objectAtIndex(n);
        if (box->isUseless)
        {
            box->removeFromParent();
              boxArray->removeObject(box);
        }
      
    }
    for (int n=ballNum-1; n>=0; n--) {
        MainBall *ball=(MainBall *)ballArray->objectAtIndex(n);
        if (ball->isUseless) {
             ball->m_emitter->release();
            ball->m_emitter->removeFromParent();
            ball->removeFromParent();
            ballArray->removeObject(ball);
        }
    }
    int starNum=starArray->count();
    for (int n=starNum-1; n>=0; n--) {
        StarSprite*star=(StarSprite *)starArray->objectAtIndex(n);
        if (star->isUseless) {
            star->removeFromParent();
            starArray->removeObject(star);
        }
    }
    int obstacleNum=obstacleArray->count();
    for (int n=obstacleNum-1; n>=0; n--) {
        Obstacle *thisOb=(Obstacle*)obstacleArray->objectAtIndex(n);
        if (thisOb->HealthNum<=0) {
            obstaclelayer->removeTileAt(thisOb->position);
            obstacleArray->removeObject(thisOb);
        }
    }
    int propsTMXNum=propsTMXArray->count();
    for (int n=propsTMXNum-1; n>=0; n--) {
        PropsObject *thisOb=(PropsObject*)propsTMXArray->objectAtIndex(n);
        if (thisOb->HealthNum<=0) {
            propslayer->removeTileAt(thisOb->position);
            propsTMXArray->removeObject(thisOb);
        }
    }
}

#pragma mark - 创建道具
void HelloWorld::creatProps(PropsType pType ,CCPoint po)
{
    Props *propSprite=Props::getProps(pType);
    propSprite->setPosition(po);
     propsArray->addObject(propSprite);
    this->addChild(propSprite);
}

#pragma mark- Methon
void HelloWorld::test()
{
    if (ballArray->count()<1) {
        this->creatBall();
    }

}
void HelloWorld::creatBall()
{
      
    MainBall *ball=MainBall::getBall();
    ball->setPosition(ccp(favorer->getPosition().x, favorer->getPosition().y+30));
    //ball->assignmentProps(createMother_Son, this);
    this->addChild(ball);
    ballArray->addObject(ball);
    CCParticleSun* m_emitter = CCParticleSun::createWithTotalParticles(60);
    m_emitter->setPosition(ball->getPosition());
    m_emitter->retain();
  
    m_emitter->setTexture( CCTextureCache::sharedTextureCache()->addImage("fire-grayscale.png") );
    m_emitter->cocos2d::CCParticleSystem::setTotalParticles(0);
    ball->m_emitter=m_emitter;
      this-> addChild(m_emitter);

}
void HelloWorld::fireBall(MainBall *ball)
{

    ball->speed=5;
    ball->setSpeedAndRadian(ball->speed,0.8);
    ball->isFire=true;
}

void HelloWorld::ccTouchesBegan(CCSet *pTouches,CCEvent *pEvent)
{
    CCSetIterator it = pTouches->begin();
    CCTouch *touch = (CCTouch *)(*it);
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
    CCLOG("po.x=%f po.y=%f",touchLocation.x,touchLocation.y);
    beganTouchLocation=touchLocation;
    favorer->targetPoint=beganTouchLocation;
    
}
void HelloWorld::ccTouchesMoved(CCSet *pTouches,CCEvent *pEvent)
{
    CCPoint location;
    CCSetIterator iter = pTouches->begin();
     CCTouch *touch = (CCTouch *)(*iter);
    CCPoint touchLocation = touch->getLocationInView();
    
     touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
     favorer->targetPoint=touchLocation;
    int num=ballArray->count();
    for (int n=0;n<num;n++) {
        MainBall *ball=(MainBall *)ballArray->objectAtIndex(n);
        if (ball->isFire==false) {
            ball->setPositionX(touchLocation.x);
        }
    }
}
void HelloWorld::ccTouchesEnded(CCSet *pTouches,CCEvent *pEvent)
{
    CCPoint location;
    CCSetIterator iter = pTouches->begin();
    CCTouch *touch = (CCTouch *)(*iter);
    CCPoint touchLocation = touch->getLocationInView();
    touchLocation = CCDirector::sharedDirector()->convertToGL(touchLocation);
     favorer->targetPoint=touchLocation;
    if (fabsf(beganTouchLocation.x-touchLocation.x)<7) {
        int num=ballArray->count();
        this->test();
        for (int n=0;n<num;n++) {
            MainBall *ball=(MainBall *)ballArray->objectAtIndex(n);
            if (ball->isFire==false) {
                this->fireBall(ball);
                
            }
        }
    }
}



void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
#pragma mark-  map格子转换
CCPoint  HelloWorld::tileCoordForPosition(CCPoint position){
    
    int x = position.x/_tileMap->getTileSize().width;
   // CCLog("position.x=%f width=%f x=%i",position.x,_tileMap->getTileSize().width,x);
    int y = ((_tileMap->getMapSize().height*_tileMap->getTileSize().height)-position.y)/_tileMap->getTileSize().height;
    //MapSize 为地图高度格子数  TileSize 为每个格子高度
    return ccp(x, y);
}

#pragma mark -获得所有成功必需品
void HelloWorld::getAllStar()
{
    if (_tileMap==NULL) {
        return;
    }
    CCTMXObjectGroup *objects=_tileMap->objectGroupNamed("starLayer");
    if (starArray==NULL) {
        starArray=CCArray::create();
        starArray->retain();
    }
    CCArray *starDicArray=objects->getObjects();
    for (int n=0; n<starDicArray->count(); n++) {
        CCDictionary *dic=(CCDictionary *)starDicArray->objectAtIndex(n);
        int x = dic->valueForKey("x")->intValue();
        int y = dic->valueForKey("y")->intValue();
        StarSprite *sp=StarSprite::getStar();
        starArray->addObject(sp);
        sp->setPosition(ccp(x,y));
        this->addChild(sp);
        
    }
    
}
#pragma mark - 得到障碍
void HelloWorld::getAllObstacle()
{
    if (_tileMap==NULL) {
        return;
    }
    CCSize s=obstaclelayer->getLayerSize();
   CCRect zeroBoxRect=CCRect(0, 0, _tileMap->getTileSize().width*0.5, _tileMap->getTileSize().height*0.5);//获得原始BoxRect
    for (int x = 0; x<s.width; x++) {
        for (int y =0; y<s.height; y++) {
            int gid=obstaclelayer->tileGIDAt(ccp(x, y));
            if (gid !=0) {
                Obstacle *ob=new Obstacle;
                ob->position=ccp(x, y);
                int mapy= _tileMap->getMapSize().height-y;//从左下算起的点Y
                float xxx=(x+0.5)*_tileMap->getTileSize().width;
                float yyy=(mapy-0.5)*_tileMap->getTileSize().height;
                
                CCPoint boxPo=ccp(xxx,yyy);
               // CCLog("x=%f");
                CCRect boxRect=Tool::MakeOffset(boxPo, zeroBoxRect);//获取真正的BoxRect
                ob->obRect=boxRect;
               // CCLog("ob->obRect.x=%f y = %f  w=%f h=%f",ob->obRect.origin.x,ob->obRect.origin.y,ob->obRect.size.width,ob->obRect.size.height);
                ob->startGID =gid;
                CCDictionary *properties=_tileMap->propertiesForGID(gid);
                if (properties) {
                    ob->infoDic=properties;
                    if (properties->valueForKey("hp")) {
                        CCString *hp=(CCString *)properties->valueForKey("hp");
                        ob->HealthNum=hp->intValue();
                        
                    }
                }
                if (ob->HealthNum==0) {
                    ob->HealthNum=5;
                }
                obstacleArray->addObject(ob);
                
            }
        }
    }
}

#pragma mark -获得道具
 void HelloWorld::getProps()
{
    if (_tileMap==NULL) {
        return;
    }
    CCSize s=propslayer->getLayerSize();
    for (int x = 0; x<s.width; x++) {
        for (int y =0; y<s.height; y++) {
            int gid=propslayer->tileGIDAt(ccp(x, y));
            if (gid !=0) {
                
                PropsObject *ob=new PropsObject;
                ob->position=ccp(x, y);
                ob->startGID =gid;
                CCDictionary *properties=_tileMap->propertiesForGID(gid);
                int typeNum=-1;
                if (properties) {
                    ob->infoDic=properties;
                    if (properties->valueForKey("hp")) {
                        CCString *hp=(CCString *)properties->valueForKey("hp");
                        ob->HealthNum=hp->intValue();
                        
                    }
                    if (properties->valueForKey("type")) {
                        
                        CCString *type=(CCString *)properties->valueForKey("type");
                        typeNum=type->intValue();

                    }
                    
                    
                }
                if (typeNum==-1) {
            
                        typeNum=random_propsType;

                    switch (typeNum) {
                        case 1:
                            ob->propsType=createBrothers ;
                            break;
                        case 2:
                            ob->propsType=becomeSmall ;
                            break;
                        case 3:
                            ob->propsType=becomeStrong ;
                            break;
                        case 4:
                            ob->propsType=becomeFireBall ;
                            break;
                        case 5:
                            ob->propsType=ball_Speed_up ;
                            break;
                        case 6:
                            ob->propsType=gongzih_Speed_up ;
                            break;

                        default:
                             ob->propsType=gongzih_Speed_down ;
                            break;
                    }
                }
                if (ob->HealthNum==0) {
                    ob->HealthNum=1;
                }
                propsTMXArray->addObject(ob);
                
            }
        }
    }


}


