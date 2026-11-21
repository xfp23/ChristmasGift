#include "MicroOSQueue.h"
#include "MicroOS_utils.h"
#include "string.h"

#if MICROOS_USE_MEM

MicroOS_Status_t MicroOSQueue_Init(MicroOSQueue_Handle_t *handle, MicroOSQueue_Conf_t *conf)
{
    MICROOS_CHECK_PTR(handle);
    MICROOS_CHECK_PTR(conf);

    if (conf->depth == 0 || conf->single_msg_size == 0)
        return MICROOS_INVALID_PARAM;

    if (*handle != NULL)
        return MICROOS_ALREADY_EXIST;

    uint32_t slots = conf->depth + 1;

    MicroOSQueue_Obj_t *q = MicroMem_Alloc(1, sizeof(*q));
    if (!q) return MICROOS_ERROR;

    q->buffer = MicroMem_Alloc(slots, sizeof(MicroOSQueue_Message_t));
    if (!q->buffer) return MICROOS_ERROR;

    uint8_t *pool = MicroMem_Alloc(slots, conf->single_msg_size);   // 一次分配
    if (!pool) return MICROOS_ERROR;

    for (uint32_t i = 0; i < slots; i++)
    {
        q->buffer[i].data = pool + (size_t)i * conf->single_msg_size;
        q->buffer[i].len  = 0;
    }

    q->size = slots;
    q->single_msg_size = conf->single_msg_size;
    q->head = 0;
    q->tail = 0;

    *handle = q;            // 全部成功才对外可见
    return MICROOS_OK;
}

bool MicroOSQueue_IsEmpty(MicroOSQueue_Handle_t h)
{
    return (h == NULL) || (h->head == h->tail);
}

bool MicroOSQueue_IsFull(MicroOSQueue_Handle_t h)
{
    return (h == NULL) || (((h->tail + 1) % h->size) == h->head);
}

MicroOS_Status_t MicroOSQueue_Push(MicroOSQueue_Handle_t h, const void *data, size_t size)
{
    MICROOS_CHECK_PTR(h);
    if (size > 0) MICROOS_CHECK_PTR(data);
    if (size > h->single_msg_size) return MICROOS_ERROR;

    uint32_t tail = h->tail;
    uint32_t next = (tail + 1) % h->size;
    if (next == h->head) return MICROOS_QUEUE_FULL;

    if (size > 0) memcpy(h->buffer[tail].data, data, size);
    h->buffer[tail].len = size;

    h->tail = next;         // 最后才发布
    return MICROOS_OK;
}

MicroOS_Status_t MicroOSQueue_Pop(MicroOSQueue_Handle_t h, void *data, size_t *size)
{
    MICROOS_CHECK_PTR(h);
    MICROOS_CHECK_PTR(data);
    MICROOS_CHECK_PTR(size);

    uint32_t head = h->head;
    if (head == h->tail) return MICROOS_QUEUE_EMPTY;

    *size = h->buffer[head].len;
    memcpy(data, h->buffer[head].data, *size);

    h->head = (head + 1) % h->size;
    return MICROOS_OK;
}

uint32_t MicroOSQueue_Size(MicroOSQueue_Handle_t h)
{
    if (!h) return 0;
    return (h->tail + h->size - h->head) % h->size;
}
#else
MicroOS_Status_t MicroOSQueue_Init(MicroOSQueue_Obj_t *obj)
{
    MICROOS_CHECK_PTR(obj);

    memset(obj, 0, sizeof(MicroOSQueue_Obj_t));
    obj->size = MICROOS_QUEUE_DEPTH;

    return MICROOS_OK;
}

MicroOS_Status_t MicroOSQueue_Reset(MicroOSQueue_Obj_t *obj)
{
    MICROOS_CHECK_PTR(obj);

    memset(obj, 0, sizeof(MicroOSQueue_Obj_t));
    obj->size = MICROOS_QUEUE_DEPTH;

    return MICROOS_OK;
}

bool MicroOSQueue_IsEmpty(MicroOSQueue_Obj_t *obj)
{
    return (obj->head == obj->tail);
}

bool MicroOSQueue_IsFull(MicroOSQueue_Obj_t *obj)
{
    return ((obj->tail - obj->head) >= MICROOS_QUEUE_DEPTH);
}

MicroOS_Status_t MicroOSQueue_Push(MicroOSQueue_Obj_t *obj, const void *data, size_t size)
{

    MICROOS_CHECK_PTR(obj);
    MICROOS_CHECK_PTR(data);

    if (size > MICROOS_QUEUE_SINGLE_MSG_SIZE)
    {
        return MICROOS_ERROR;
    }

    if (MicroOSQueue_IsFull(obj))
    {
        return MICROOS_QUEUE_FULL;
    }

    uint32_t index = obj->tail % MICROOS_QUEUE_DEPTH;

    obj->buffer[index].len = size;

    if (data != NULL && size > 0)
    {
        memcpy(obj->buffer[index].data, data, size);
    }
    else
    {
        memset(obj->buffer[index].data, 0, sizeof(obj->buffer[index].data));
    }

    obj->tail++;
    obj->size--;

    return MICROOS_OK;
}

MicroOS_Status_t MicroOSQueue_Pop(MicroOSQueue_Obj_t *obj, void *data, size_t *size)
{

    MICROOS_CHECK_PTR(obj);
    MICROOS_CHECK_PTR(data);
    MICROOS_CHECK_PTR(size);

    if (MicroOSQueue_IsEmpty(obj))
    {
        return MICROOS_QUEUE_EMPTY;
    }

    uint32_t index = obj->head % MICROOS_QUEUE_DEPTH;

    *size = obj->buffer[index].len;
    obj->size++;

    memcpy(data, obj->buffer[index].data, *size);

    obj->head++;

    return MICROOS_OK;
}

uint32_t MicroOSQueue_Size(MicroOSQueue_Obj_t *obj)
{
    MICROOS_CHECK_PTR(obj);

    return obj->size;
}
#endif
