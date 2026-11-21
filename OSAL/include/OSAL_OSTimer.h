#ifndef OSAL_OSTIMER_H
#define OSAL_OSTIMER_H

#ifdef __cplusplus
extern "C"
{
#endif

enum {
    OSAL_OSTIMER_SYSTICK,
    OSAL_OSTIMER_LVGLTICK,
};

extern void OSAL_OSTimer_SysTick(void *param);

extern void OSAL_OSTimer_LvglTick(void *param);

#ifdef __cplusplus
}
#endif

#endif
