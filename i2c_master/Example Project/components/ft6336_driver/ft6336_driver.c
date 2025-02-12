#include"ft6336_driver.h"
//enable ft6336 driver
#ifdef FT6336_DRIVER_H

//config
#define IIC I2C_NUM_1
#define RATE 100*1000

//define
#define ADDR 0x71
#define ID 0xa8
#define TC_NUM 0x02
#define TC1 0x03
#define TC2 0x09

//static data
typedef struct static_data_t
{
    i2c_master_dev_handle_t iic;
}static_data_t;
static static_data_t static_data={0};

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
    i2c_master_transmit_receive(static_data.iic,&addr,1,data,len,-1);
    return;
}

//ft6336 init
void ft6336_init()
{
    //add iic device
    i2c_device_config_t config={0};
    config.dev_addr_length=I2C_ADDR_BIT_LEN_7;
    config.device_address=ADDR;
    config.scl_speed_hz=RATE;
    i2c_master_bus_handle_t handle;
    i2c_master_get_bus_handle(IIC,&handle);
    i2c_master_bus_add_device(handle,&config,&static_data.iic);
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
    if(state)
    {
        uint16_t x1=0;
        uint16_t y1=0;
        uint8_t t1[4];
        read(TC1,t1,1);
        x1=((uint16_t)(t1[0]&0X0f)<<8)+t1[1];
        y1=((uint16_t)(t1[2]&0X0f)<<8)+t1[3];
        tc1[0]=x1;
        tc1[1]=y1;
        if(state>1)
        {
            uint16_t x2=0;
            uint16_t y2=0;
            uint8_t t2[2];
            read(TC2,t2,1);
            x2=((uint16_t)(t2[0]&0X0f)<<8)+t2[1];
            y2=((uint16_t)(t2[2]&0X0f)<<8)+t2[3];
            tc2[0]=x2;
            tc2[1]=y2;
        }
    }
    return state;
}

#endif//#ifdef FT6336_DRIVER_H
