/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : c_source.c                                            */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include "circular_buffer.h"
#include "runtime_error.h"

#include <stdint.h>

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
enum {
    CIRCULAR_BUFFER_CAPACITY = 64u
};

struct CircularBufferStruct {
    uint32_t buffer[CIRCULAR_BUFFER_CAPACITY];
    uint32_t head;
    uint32_t tail;
    uint32_t count;
};

static const double PI = 3.14;
static const char SOME_STRING[] = "a constant string";

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
static uint32_t transformItem(uint32_t input);

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
CircularBuffer initCircularBuffer(void)
{
    CircularBuffer buffer = malloc(sizeof(struct CircularBufferStruct));
    if (!buffer) {
        RUNTIME_ERROR("init: NULL buffer", 0, __FILE__, __LINE__);
    }

    initParametersCircularBuffer(buffer);
    return buffer;
}

void deinitCircularBuffer(CircularBuffer buffer)
{
    if (!buffer) {
        RUNTIME_ERROR("deinit: NULL buffer", 0, __FILE__, __LINE__);
    }

    free(buffer);
}

void addItemCircularBuffer(CircularBuffer buffer, uint32_t item)
{
    if (!buffer) {
        RUNTIME_ERROR("add item: NULL buffer", 0, __FILE__, __LINE__);
    }

    if (buffer->count >= CIRCULAR_BUFFER_CAPACITY) {
        RUNTIME_ERROR("add item: buffer full", 
            buffer->count, __FILE__, __LINE__);
    }

    buffer->buffer[buffer->tail] = transformItem(item);
    buffer->tail = (buffer->tail + 1) % CIRCULAR_BUFFER_CAPACITY;
    buffer->count++;
}

uint32_t removeItemCircularBuffer(CircularBuffer buffer)
{
    if (!buffer) {
        RUNTIME_ERROR("remove item: NULL buffer", 0, __FILE__, __LINE__);
    }

    if (buffer->count == 0u) {
        RUNTIME_ERROR("remove item: buffer empty", 0, __FILE__, __LINE__);
    }

    uint32_t item = buffer->buffer[buffer->head];
    buffer->head = (buffer->head + 1) % CIRCULAR_BUFFER_CAPACITY;
    buffer->count--;
    return item;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
static void initParametersCircularBuffer(CircularBuffer buffer)
{
    if (!buffer) {
        RUNTIME_ERROR("init parameters: NULL buffer", 0, __FILE__, __LINE__);
    }

    buffer->head = 0u;
    buffer->tail = 0u;
    buffer->count = 0u;

    for (uint32_t i = 0; i < CIRCULAR_BUFFER_CAPACITY; ++i) {
        buffer->buffer[i] = 0u;
    }
}

static uint32_t privateFunctionName(uint32_t argumentName)
{
    uint32_t returnValue = 0u;

    /* ...some helper logic here */
    
    return returnValue;
}
