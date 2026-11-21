#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H

#include "Middleware_utils.h"
#include "MicroMem.h"
#include "MgrLvgl.h"
#include "MgrNtc.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern void Middleware_Init(void);

extern void Middleware_TimerHandler(void);

extern void Middleware_TickHandler(void);
#ifdef __cplusplus
}
#endif

#endif
