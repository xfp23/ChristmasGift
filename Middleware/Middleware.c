#include "Middleware.h"

void Middleware_Init(void)
{
    MicroMem_Init();
    MgrLvgl_Init();

    MgrNtc_Init();
}

void Middleware_TimerHandler(void)
{
    // MgrLvgl_TimerHandler();
}

void Middleware_TickHandler(void)
{
    // MgrLvgl_TickHandler();
}