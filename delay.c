#include "delay.h"

/* Using TIM3 for delay */

void Delay_Init()
{
    HAL_TIM_Base_Start(&htim3);
}

void Delay_us(uint16_t nus)
{
    uint16_t start = __HAL_TIM_GET_COUNTER(&htim3);
    uint16_t curr;
    while (1)
    {
        curr = __HAL_TIM_GET_COUNTER(&htim3);
        
        if ((uint16_t)(curr - start) >= nus)
            break;
    }
}

void Delay_ms(uint16_t nms)
{
    HAL_Delay(nms);
}
