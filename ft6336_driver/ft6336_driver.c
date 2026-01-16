#include"ft6336_driver.h"
//启用FT6336驱动
#ifdef FT6336_DRIVER_H

//寄存器地址定义
#define FT6336_ADDR 0x38
#define FT6336_ID 0xa8
#define FT6336_TC_NUM 0x02
#define FT6336_TC1 0x03
#define FT6336_TC2 0x09

//IIC读数据
static uint8_t iic_read(uint8_t addr,uint8_t*data,uint8_t len);
//用户初始化
static uint8_t init_user();
//初始化FT6336
uint8_t ft6336_init();
//读取FT6336器件ID
uint8_t ft6336_read_id();
//读取FT6336触摸数据
uint8_t ft6336_read_touch(uint8_t*num,uint16_t*tc1,uint16_t*tc2);

//IIC读数据
static uint8_t iic_read(uint8_t addr,uint8_t*data,uint8_t len)
{
    return 0;
}

//用户初始化
static uint8_t init_user()
{

    return 0;
}

//FT6336初始化
uint8_t ft6336_init()
{
    if(init_user())
    {
        return 1;
    }
    return 0;
}

//读取FT6336器件ID
uint8_t ft6336_read_id()
{
    uint8_t id=0;
    iic_read(FT6336_ID,&id,1);
    return id;
}

//读取FT6336触摸数据
uint8_t ft6336_read_touch(uint8_t*num,uint16_t*tc1,uint16_t*tc2)
{
    uint8_t tc_num=0;
    if(iic_read(FT6336_TC_NUM,&tc_num,1))
    {
        return 1;
    }
    if(num)
    {
        *num=tc_num;
    }
    if(tc_num>0&&tc1)
    {
        uint16_t x1=0;
        uint16_t y1=0;
        uint8_t t1[4];
        iic_read(FT6336_TC1,t1,4);
        x1=((uint16_t)(t1[0]&0X0f)<<8)+t1[1];
        y1=((uint16_t)(t1[2]&0X0f)<<8)+t1[3];
        tc1[0]=x1;
        tc1[1]=y1;
        if(tc_num>1&&tc2)
        {
            uint16_t x2=0;
            uint16_t y2=0;
            uint8_t t2[2];
            iic_read(FT6336_TC2,t2,4);
            x2=((uint16_t)(t2[0]&0X0f)<<8)+t2[1];
            y2=((uint16_t)(t2[2]&0X0f)<<8)+t2[3];
            tc2[0]=x2;
            tc2[1]=y2;
        }
    }
    return 0;
}

#endif//#ifdef FT6336_DRIVER_H
