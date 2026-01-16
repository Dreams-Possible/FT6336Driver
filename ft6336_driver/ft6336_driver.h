//启用FT6336驱动
#if 1
#ifndef FT6336_DRIVER_H
#define FT6336_DRIVER_H

//include
#include<stdio.h>
#include<stdint.h>

//初始化FT6336
uint8_t ft6336_init();
//读取FT6336器件ID
uint8_t ft6336_read_id();
//读取FT6336触摸数据
uint8_t ft6336_read_touch(uint8_t*num,uint16_t*tc1,uint16_t*tc2);

#endif//#ifndef FT6336_DRIVER_H
#endif//#if 1
