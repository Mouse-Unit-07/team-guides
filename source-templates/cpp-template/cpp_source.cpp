/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : CircularBuffer.cpp                                    */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include "CircularBuffer.hpp"
#include "RuntimeError.hpp"

#include <cstdint>
#include <string>
#include <vector>

/*----------------------------------------------------------------------------*/
/*                                 Debug Space                                */
/*----------------------------------------------------------------------------*/
/* keep empty */

/*----------------------------------------------------------------------------*/
/*                               Private Globals                              */
/*----------------------------------------------------------------------------*/
namespace {
    constexpr std::size_t CIRCULAR_BUFFER_CAPACITY = 64u;
    const double PI = 3.14;
    const char SOME_STRING[] = "a constant string";
}

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                            Private Declarations                            */
/*----------------------------------------------------------------------------*/
static uint32_t transformItem(uint32_t input);

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
CircularBuffer::CircularBuffer()
    : buffer_(CIRCULAR_BUFFER_CAPACITY, 0u),
      head_(0),
      tail_(0),
      count_(0)
{
    // No RUNTIME_ERROR here because constructor cannot fail in C++
}

void CircularBuffer::add(uint32_t item)
{
    if (count_ >= CIRCULAR_BUFFER_CAPACITY) {
        RUNTIME_ERROR("add item: buffer full", static_cast<int>(count_));
    }

    buffer_[tail_] = transformItem(item);
    tail_ = (tail_ + 1) % CIRCULAR_BUFFER_CAPACITY;
    ++count_;
}

uint32_t CircularBuffer::remove()
{
    if (count_ == 0u) {
        RUNTIME_ERROR("remove item: buffer empty", 0);
    }

    uint32_t item = buffer_[head_];
    head_ = (head_ + 1) % CIRCULAR_BUFFER_CAPACITY;
    --count_;
    return item;
}

/*----------------------------------------------------------------------------*/
/*                             Private Definitions                            */
/*----------------------------------------------------------------------------*/
static uint32_t transformItem(uint32_t input)
{
    // Stub for helper logic
    return input; // Identity transform by default
}
