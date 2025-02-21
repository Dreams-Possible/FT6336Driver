#include<stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"

#include"ft6336_driver.h"

void app_main(void)
{
    //iic init
    // iic_init();

    //ft6336 init
    ft6336_init();

    uint16_t tc1[2]={0};
    uint16_t tc2[2]={0};
    while(1)
    {
        //ft6336 read
        uint8_t num=ft6336_read(tc1,tc2);
        if(num>0)
        {
            printf("x1=%d,y1=%d\n",tc1[0],tc1[1]);
        }
        if(num>1)
        {
            printf("x2=%d,y2=%d\n",tc2[0],tc2[1]);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
