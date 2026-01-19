/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : c_source.c                                            */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include "c_header.h"
#include <stdint.h>
#include "runtime_error.h"

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

struct circular_buffer_struct {
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
static uint32_t private_function_name(uint32_t parameter_name);

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
circular_buffer init_circular_buffer(void)
{
    circular_buffer buffer = malloc(sizeof(struct circular_buffer_struct));
    if (!buffer) {
        RUNTIME_ERROR("init: NULL buffer", buffer);
    }

    init_circular_buffer_elements(buffer);
    return buffer;
}

void deinit_circular_buffer(circular_buffer buffer)
{
    if (!buffer) {
        RUNTIME_ERROR("deinit: NULL buffer", buffer);
    }

    free(buffer);
}

void push_to_circular_buffer(circular_buffer buffer, uint32_t item)
{
    if (!buffer) {
        RUNTIME_ERROR("push: NULL buffer", buffer);
    }

    if (buffer->count >= CIRCULAR_BUFFER_CAPACITY) {
        RUNTIME_ERROR("push: buffer full", buffer->count);
    }

    buffer->buffer[buffer->tail] = private_function_name(item);
    buffer->tail = (buffer->tail + 1) % CIRCULAR_BUFFER_CAPACITY;
    buffer->count++;
}

uint32_t pop_from_circular_buffer(circular_buffer buffer)
{
    if (!buffer) {
        RUNTIME_ERROR("pop: NULL buffer", buffer);
    }

    if (buffer->count == 0u) {
        RUNTIME_ERROR("pop: buffer empty", buffer->count);
    }

    uint32_t item = buffer->buffer[buffer->head];
    buffer->head = (buffer->head + 1) % CIRCULAR_BUFFER_CAPACITY;
    buffer->count--;
    return item;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
static void init_circular_buffer_elements(circular_buffer buffer)
{
    if (!buffer) {
        RUNTIME_ERROR("init parameters: NULL buffer", buffer);
    }

    buffer->head = 0u;
    buffer->tail = 0u;
    buffer->count = 0u;

    for (uint32_t i = 0; i < CIRCULAR_BUFFER_CAPACITY; i++) {
        buffer->buffer[i] = 0u;
    }
}

static uint32_t private_function_name(uint32_t parameter_name)
{
    uint32_t some_value = 0u;

    /* ...some helper logic here */
    
    return some_value;
}
