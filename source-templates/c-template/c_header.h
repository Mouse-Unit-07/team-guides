/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : c_header.h                                            */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef C_HEADER_H_
#define C_HEADER_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
typedef struct CircularBufferStruct *CircularBuffer;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
CircularBuffer initCircularBuffer(void);
void deinitCircularBuffer(CircularBuffer buffer);
void addItemCircularBuffer(CircularBuffer buffer, uint32_t item);
uint32_t removeItemCircularBuffer(CircularBuffer buffer);

#endif /* C_HEADER_H_ */