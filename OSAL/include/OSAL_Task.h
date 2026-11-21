#ifndef OSAL_TASK_H
#define OSAL_TASK_H

#ifdef __cplusplus
extern "C"
{
#endif

enum {
    OSAL_TASK_SYSRELAY,
    OSAL_TASK_LVGL,
    OSAL_TASK_LIFE,
};

extern void OSAL_Task_SysRelay(void *param);

extern void OSAL_Task_Lvgl(void *param);

extern void OSAL_Task_Life(void *param);

#ifdef __cplusplus
}
#endif

#endif
