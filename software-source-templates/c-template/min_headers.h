/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : min_headers.h                                         */
/*                                                                            */
/* Fake interface for a circular buffer w/ minimum comment headers            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef MIN_HEADERS_H_
#define MIN_HEADERS_H_

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
struct circular_buffer;

/*----------------------------------------------------------------------------*/
/*                         Public Function Prototypes                         */
/*----------------------------------------------------------------------------*/
struct circular_buffer *init_circular_buffer(void);
void deinit_circular_buffer(struct circular_buffer *buffer);
void push_to_circular_buffer(struct circular_buffer *buffer, uint32_t item);
uint32_t pop_from_circular_buffer(struct circular_buffer *buffer);

#endif /* MIN_HEADERS_H_ */