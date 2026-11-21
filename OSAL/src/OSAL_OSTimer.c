#include "OSAL_OSTimer.h"
#include "UserApp.h"

void OSAL_OSTimer_SysTick(void *param)
{
    (void)param;
    Middleware_TickHandler();
}

void OSAL_OSTimer_LvglTick(void *param)
{
    (void)param;
    MgrLvgl_TickHandler();

}