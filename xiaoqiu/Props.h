//
//  Props.h
//  NycGame
//
//  Created by NycMac on 13-6-15.
//
//

#ifndef __NycGame__Props__
#define __NycGame__Props__

#include <iostream>
#include "SpriteBase.h"
#include "enumWhole.h"
class Props:public SpriteBase
{
public:
    virtual bool init();
     CREATE_FUNC(Props);
    PropsType propsType;
    static Props *getProps(PropsType type);
    
};
#endif /* defined(__NycGame__Props__) */
