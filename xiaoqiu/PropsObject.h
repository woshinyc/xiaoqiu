//
//  PropsObject.h
//  xiaoqiu
//
//  Created by NycMac on 13-7-4.
//
//

#ifndef __xiaoqiu__PropsObject__
#define __xiaoqiu__PropsObject__

#include <iostream>
#include "ObjectBase.h"
#include "enumWhole.h"
using namespace cocos2d;

class PropsObject :public ObjectBase
{
public:
	PropsObject(void);
	~PropsObject(void);
    CCPoint position;
    int HealthNum;
	int startGID;
	PropsType propsType;
    CCDictionary *infoDic;
    
};
#endif /* defined(__xiaoqiu__PropsObject__) */
