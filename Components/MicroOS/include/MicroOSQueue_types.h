/**
 * @file MicroOSQueue_types.h
 * @author https://xfp23.github.io
 * @brief queue types
 * @version 0.1
 * @date 2026-07-22
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef MicroOSQueue_TYPES_H
#define MicroOSQueue_TYPES_H

#include "MicroOS_conf.h"
#include "stdint.h"
#include "string.h"
#if MICROOS_USE_MEM
#include "MicroMem.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#if MICROOS_USE_MEM
typedef struct {
    uint32_t single_msg_size; 
    uint32_t depth; // 队列深度
} MicroOSQueue_Conf_t;
#endif

/**
 * @brief Statically allocated, copy-based byte ring buffer.
 *
 * @note Each stored item is framed with a length header (see
 *       MicroOSQueue.h / MicroOSQueue_LEN_BYTES) so that variable-length
 *       items can share the same raw buffer without losing their
 *       boundaries.
 */

typedef struct 
{
    size_t len;
#if MICROOS_USE_MEM
    uint8_t *data;
#else
    uint8_t data[MICROOS_QUEUE_SINGLE_MSG_SIZE];
#endif

} MicroOSQueue_Message_t;


typedef struct
{
#if MICROOS_USE_MEM
    MicroOSQueue_Message_t *buffer;
    uint32_t single_msg_size;
#else
    MicroOSQueue_Message_t buffer[MICROOS_QUEUE_DEPTH];
#endif
    volatile uint32_t tail;
    volatile uint32_t head;
    volatile uint32_t size;
} MicroOSQueue_Obj_t;

#if MICROOS_USE_MEM
typedef MicroOSQueue_Obj_t *MicroOSQueue_Handle_t;
#endif

#ifdef __cplusplus
}
#endif

#endif
