//
//  NycGameAppDelegate.cpp
//  NycGame
//
//  Created by NycMac on 13-6-10.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());
    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    
    CCSize designSize = CCSizeMake(320, 480);
   // CCFileUtils* pFileUtils = CCFileUtils::sharedFileUtils();
    
//    if (screenSize.height > 320)
//    {
//        CCSize resourceSize = CCSizeMake(640, 960);
//        std::vector<std::string> searchPaths;
//        searchPaths.push_back("hd");
//        pFileUtils->setSearchPaths(searchPaths);
//        pDirector->setContentScaleFactor(resourceSize.height/designSize.height);
//    }
    
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionShowAll);
    // turn on display FPS

    pDirector->setDisplayStats(true);
    
    pDirector->setAnimationInterval(1.0 / 60);
    
    CCScene *pScene = HelloWorld::scene();
    
    pDirector->runWithScene(pScene);
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
