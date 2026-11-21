#include "OSAL_Task.h"
#include "main.h"

void OSAL_Task_SysRelay(void *param)
{
    (void)param;
    Middleware_TimerHandler();
}


void OSAL_Task_Lvgl(void *param)
{
    (void)param;
    MgrLvgl_TimerHandler();

}

void OSAL_Task_Life(void *param)
{
    (void)param;

    HAL_GPIO_TogglePin(LIFE_LED_Port,LIFE_LED_Pin);
		HAL_IWDG_Refresh(&hiwdg);
}
