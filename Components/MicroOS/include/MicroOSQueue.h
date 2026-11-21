#ifndef MicroOSQueue_H
#define MicroOSQueue_H

#include "MicroOSQueue_types.h"
#include "MicroOS_types.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if MICROOS_USE_MEM
/**
 * @brief Init MicroOSQueue
 * 
 * @param handle 
 * @return MicroOS_Status_t 
 */
extern MicroOS_Status_t MicroOSQueue_Init(MicroOSQueue_Handle_t *handle, MicroOSQueue_Conf_t *conf);

/**
 * @brief Push queue
 * 
 * @param handle a queue object
 * @param data User push data
 * @param size data len
 * @return MicroOS_Status_t 
 */
extern MicroOS_Status_t MicroOSQueue_Push(MicroOSQueue_Handle_t handle,const void *data,size_t size);

/**
 * @brief Pop queue
 * 
 * @param handle a queue object
 * @param data Copy buffer
 * @param size Copy len buffer
 * @return MicroOS_Status_t 
 */
extern MicroOS_Status_t MicroOSQueue_Pop(MicroOSQueue_Handle_t handle,void *data,size_t *size);

/**
 * @brief the queue object is empty
 * 
 * @param handle a queue object
 * @return true is empty
 * @return false not empty
 */
extern bool MicroOSQueue_IsEmpty(MicroOSQueue_Handle_t handle);

/**
 * @brief the queue object is full
 * 
 * @param handle a queue object
 * @return true is full
 * @return false not full
 */
extern bool MicroOSQueue_IsFull(MicroOSQueue_Handle_t handle);

/**
 * @brief Reset the queue
 * 
 * @param handle a queue object
 * @return MicroOS_Status_t 
 */
extern MicroOS_Status_t MicroOSQueue_Reset(MicroOSQueue_Handle_t handle);

/**
 * @brief 
 * 
 * @param handle 
 * @return uint32_t 
 */
extern uint32_t MicroOSQueue_Size(MicroOSQueue_Handle_t handle);
#else
/**
 * @brief Init MicroOSQueue
 * 
 * @param obj 
 * @return MicroOS_Status_t 
 */
extern MicroOS_Status_t MicroOSQueue_Init(MicroOSQueue_Obj_t *obj);

/**
 * @brief Push queue
 * 
 * @param obj a queue object
 * @param data User push data
 * @param size data len
 * @return MicroOS_Status_t 
 */
extern MicroOS_Status_t MicroOSQueue_Push(MicroOSQueue_Obj_t *obj,const void *data,size_t size);

/**
 * @brief Pop queue
 * 
 * @param obj a queue object
 * @param data Copy buffer
 * @param size Copy len buffer
 * @return MicroOS_Status_t 
 */
extern MicroOS_Status_t MicroOSQueue_Pop(MicroOSQueue_Obj_t *obj,void *data,size_t *size);

/**
 * @brief the queue object is empty
 * 
 * @param obj a queue object
 * @return true is empty
 * @return false not empty
 */
extern bool MicroOSQueue_IsEmpty(MicroOSQueue_Obj_t *obj);

/**
 * @brief the queue object is full
 * 
 * @param obj a queue object
 * @return true is full
 * @return false not full
 */
extern bool MicroOSQueue_IsFull(MicroOSQueue_Obj_t *obj);

/**
 * @brief Reset the queue
 * 
 * @param obj a queue object
 * @return MicroOS_Status_t 
 */
extern MicroOS_Status_t MicroOSQueue_Reset(MicroOSQueue_Obj_t *obj);

/**
 * @brief Get the queue size
 * 
 * @param obj 
 * @return uint32_t 
 */
extern uint32_t MicroOSQueue_Size(MicroOSQueue_Obj_t *obj);
#endif

#ifdef __cplusplus
}
#endif

#endif
