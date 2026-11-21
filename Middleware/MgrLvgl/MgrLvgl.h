#ifndef MGRLVGL_H
#define MGRLVGL_H

#include "lvgl.h"
#include "lv_port_disp.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern void MgrLvgl_Init(void);

extern void MgrLvgl_TimerHandler(void);

extern void MgrLvgl_TickHandler(void);

#ifdef __cplusplus
}
#endif

#endif
