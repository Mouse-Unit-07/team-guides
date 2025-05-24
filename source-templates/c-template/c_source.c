/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : c_source.c                                            */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include <stdint.h>
#include "c_header.h"
#include "xyz/types.h"
#include "xyz/lib.h"
#include "xyz/defs.h"

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
enum triangularBufferConstants {
    SPECIAL_INDEX = 0u,
    BUFFER_SIZE = 64u,
};

struct TriangularBufferStruct {
    uint32_t buffer[BUFFER_SIZE];
    uint32_t size;
    uint32_t head;
    uint32_t tail;
    uint32_t bellyButton;
};

static const double PI = 3.14;
static const char[] SOME_STRING = "a constant string";

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                         Private Function Prototypes                        */
/*----------------------------------------------------------------------------*/
static uint32_t privateFunctionName(uint32_t argumentName);

/*----------------------------------------------------------------------------*/
/*                         Public Function Definitions                        */
/*----------------------------------------------------------------------------*/
void addItemTriangularBuffer(TriangularBuffer bufferInstance, uint32_t newItem)
{
    bufferInstance->buffer[bufferInstance->bellyButton] \
        = privateFunctionName(newItem);
    
    bufferInstance->bellyButton = (bufferInstance + 1) % BUFFER_SIZE;
}

uint32_t removeItemTriangularBuffer(TriangularBuffer bufferInstance)
{
    uint32_t returnValue = 0u;

    /* ...some logic to remove an item here */

    return returnValue;
}

/*----------------------------------------------------------------------------*/
/*                        Private Function Definitions                        */
/*----------------------------------------------------------------------------*/
static uint32_t privateFunctionName(uint32_t argumentName)
{
    uint32_t returnValue = 0u;

    /* ...some helper logic here */
    
    return returnValue;
}
