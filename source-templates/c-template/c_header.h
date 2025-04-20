/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : c_header.h                                            */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef C_HEADER_H_
#define C_HEADER_H_

/*----------------------------------------------------------------------------*/
/*                                Definitions                                 */
/*----------------------------------------------------------------------------*/
typedef struct TriangularBufferStruct * TriangularBuffer;

/*----------------------------------------------------------------------------*/
/*                       Exportable Function Prototypes                       */
/*----------------------------------------------------------------------------*/
void addItemTriangularBuffer(TriangularBuffer bufferInstance, uint32_t newItem);
uint32_t removeItemTriangularBuffer(TriangularBuffer bufferInstance);

#endif /* C_HEADER_H_ */