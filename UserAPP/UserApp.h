#ifndef USERAPP_H
#define USERAPP_H

#include "main.h"

#ifdef __cplusplus
extern "C"
{
#endif

extern void UserApp_Init(void);

extern void UserApp_TimerHandler(void);

extern void User_Termina(void);

#ifdef __cplusplus
}
#endif

#endif
