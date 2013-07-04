//
//  enumWhole.h
//  NycGame
//
//  Created by NycMac on 13-6-25.
//
//

#ifndef NycGame_enumWhole_h
#define NycGame_enumWhole_h


#define randomBoxtype arc4random()%3
#define randomSpeed  arc4random()%3
#define BallSpeed   5
#define PropSpeed   5
#define createProps  arc4random()%2
#define random_propsType    arc4random()%8
typedef enum
{
    createMother_Son         =1<< 0,          //创建子母球
    createBrothers           =1<< 1,          //创建另外两个球
    becomeSmall              =1<< 2,          //变小球
    becomeStrong             =1<< 3,          //变铅球
    becomeFireBall           =1<< 4,          //变火球
    ball_Speed_up            =1<< 5,          //加快球速度
    gongzih_Speed_up         =1<< 6,          //加快杠子速度
    gongzih_Speed_down       =1<< 7,          //减慢杠子速度
}PropsType;

typedef enum
{
    commonBox  =1<< 0,
    woodBox    =1<< 1,
    ironBox    =1<< 2,
}BoxType;

typedef enum 
{
    ball_Mother_Son_Type       =1<<0,
    ball_small_Type            =1<<1,
    ball_strong_Type           =1<<2,
    ball_fire_Type             =1<<3,
    ball_speed_up_Type         =1<<4,
}BallType;

#endif
