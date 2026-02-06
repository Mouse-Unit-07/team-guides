/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : min_headers.c                                         */
/*                                                                            */
/* Fake implementation of a circular buffer w/ minimum comment headers        */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include "min_headers.h"
#include <stdint.h>
#include <string.h>
#include "runtime_diagnostics.h"

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
static uint32_t private_function_name(uint32_t parameter_name);

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
enum {
    CIRCULAR_BUFFER_CAPACITY = 64
};

struct circular_buffer {
    uint32_t buffer[CIRCULAR_BUFFER_CAPACITY];
    uint32_t head;
    uint32_t tail;
    uint32_t count;
};

static const double PI = 3.14;
static const char SOME_STRING[] = "a constant string";

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
struct circular_buffer *init_circular_buffer(void)
{
    struct circular_buffer *buffer = malloc(sizeof(struct circular_buffer));
    memset(buffer, 0, sizeof(struct circular_buffer));

    return buffer;
}

void deinit_circular_buffer(struct circular_buffer *buffer)
{
    free(buffer);
}

void push_to_circular_buffer(struct circular_buffer *buffer, uint32_t item)
{
    if (buffer->count >= CIRCULAR_BUFFER_CAPACITY) {
        RUNTIME_TELEMETRY(0, "push: buffer full", buffer->count);
        return;
    }

    buffer->buffer[buffer->tail] = private_function_name(item);
    buffer->tail = (buffer->tail + 1) % CIRCULAR_BUFFER_CAPACITY;
    buffer->count++;
}

uint32_t pop_from_circular_buffer(struct circular_buffer *buffer)
{
    if (buffer->count == 0u) {
        RUNTIME_TELEMETRY("pop: buffer empty", buffer->count);
        return;
    }

    uint32_t item = buffer->buffer[buffer->head];
    buffer->head = (buffer->head + 1) % CIRCULAR_BUFFER_CAPACITY;
    buffer->count--;
    return item;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
static uint32_t private_function_name(uint32_t parameter_name)
{
    uint32_t some_value = 0u;

    /* ...some special helper logic here */
    
    return some_value;
}
