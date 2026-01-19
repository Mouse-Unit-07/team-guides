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
typedef struct circular_buffer_struct *circular_buffer;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
circular_buffer init_circular_buffer(void);
void deinit_circular_buffer(circular_buffer buffer);
void push_to_circular_buffer(circular_buffer buffer, uint32_t item);
uint32_t pop_from_circular_buffer(circular_buffer buffer);

#endif /* C_HEADER_H_ */