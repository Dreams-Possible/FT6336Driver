//enable ft6336 driver
#if 1
#ifndef FT6336_DRIVER_H
#define FT6336_DRIVER_H

//include
#include<stdio.h>
#include<stdint.h>
#include"driver/i2c_master.h"

//ft6336 init
void ft6336_init();
//ft6336 id
uint8_t ft6336_id();
//ft6336 read
uint8_t ft6336_read(uint16_t*tc1,uint16_t*tc2);

#endif//#ifndef FT6336_DRIVER_H
#endif//#if 1
