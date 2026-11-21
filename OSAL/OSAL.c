#include "OSAL.h"

void OSAL_Init(void)
{
    MicroOS_Init();

    MicroOS_OSTimer_Create(OSAL_OSTIMER_SYSTICK,OSAL_OSTimer_SysTick,OS_MS_TICKS(1),true,NULL);
    MicroOS_OSTimer_Create(OSAL_OSTIMER_LVGLTICK,OSAL_OSTimer_LvglTick,OS_MS_TICKS(5),true,NULL);

    MicroOS_AddTask(OSAL_TASK_SYSRELAY,"SystemRelay",OSAL_Task_SysRelay,NULL,OS_MS_TICKS(1));
    MicroOS_AddTask(OSAL_TASK_LVGL,"LvglTick",OSAL_Task_SysRelay,NULL,OS_MS_TICKS(50));
    MicroOS_AddTask(OSAL_TASK_LVGL,"Life",OSAL_Task_Life,NULL,OS_MS_TICKS(500));

    MicroOS_OSTimer_Start(OSAL_OSTIMER_SYSTICK);
    MicroOS_OSTimer_Start(OSAL_OSTIMER_LVGLTICK);
	
}
