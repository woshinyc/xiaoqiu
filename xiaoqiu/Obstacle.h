//
//  Obstacle.h
//  xiaoqiu
//
//  Created by NycMac on 13-7-4.
//
//

#ifndef __xiaoqiu__Obstacle__
#define __xiaoqiu__Obstacle__

#include <iostream>
#include "ObjectBase.h"
using namespace cocos2d;

class Obstacle :public ObjectBase
{
public:
	Obstacle(void);
	~Obstacle(void);
    CCPoint position;
    int HealthNum;
	int startGID;
    CCRect obRect;

	int index;
    CCDictionary *infoDic;
    
};
#endif /* defined(__xiaoqiu__Obstacle__) */
