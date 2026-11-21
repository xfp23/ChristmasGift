#include "MgrLvgl.h"

void MgrLvgl_Init(void)
{
    lv_init();
//	lv_port_disp_init();
}

void MgrLvgl_TimerHandler(void)
{
    lv_timer_handler();
}

void MgrLvgl_TickHandler(void)
{
    lv_tick_inc(5);
}