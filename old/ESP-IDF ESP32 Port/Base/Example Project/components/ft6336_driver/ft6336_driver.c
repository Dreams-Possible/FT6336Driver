#include"ft6336_driver.h"
//enable ft6336 driver
#ifdef FT6336_DRIVER_H

//define
#define ADDR 0x38
#define ID 0xa8
#define TC_NUM 0x02
#define TC1 0x03
#define TC2 0x09

//read data
static void read(uint8_t addr,uint8_t*data,uint8_t len);
//ft6336 init
void ft6336_init();
//ft6336 id
uint8_t ft6336_id();
//ft6336 read
uint8_t ft6336_read(uint16_t*tc1,uint16_t*tc2);

//read data
static void read(uint8_t addr,uint8_t*data,uint8_t len)
{
    
    return;
}

//ft6336 init
void ft6336_init()
{

    return;
}

//ft6336 id
uint8_t ft6336_id()
{
    uint8_t id=0;
    read(ID,&id,1);
    return id;
}

//ft6336 read
uint8_t ft6336_read(uint16_t*tc1,uint16_t*tc2)
{
    uint8_t state=0;
    read(TC_NUM,&state,1);
    if(state&&tc1)
    {
        uint16_t x1=0;
        uint16_t y1=0;
        uint8_t t1[4];
        read(TC1,t1,4);
        x1=((uint16_t)(t1[0]&0X0f)<<8)+t1[1];
        y1=((uint16_t)(t1[2]&0X0f)<<8)+t1[3];
        tc1[0]=x1;
        tc1[1]=y1;
        if(state>1&&tc2)
        {
            uint16_t x2=0;
            uint16_t y2=0;
            uint8_t t2[2];
            read(TC2,t2,4);
            x2=((uint16_t)(t2[0]&0X0f)<<8)+t2[1];
            y2=((uint16_t)(t2[2]&0X0f)<<8)+t2[3];
            tc2[0]=x2;
            tc2[1]=y2;
        }
    }
    return state;
}

#endif//#ifdef FT6336_DRIVER_H
