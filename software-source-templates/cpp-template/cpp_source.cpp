/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : circular_buffer.cpp                                   */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                               Include Files                                */
/*----------------------------------------------------------------------------*/
#include "circular_buffer.hpp"
#include <cstdint>
#include <string>
#include <vector>
#include "runtime_error.hpp"

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
    constexpr std::string_view SOME_STRING = "a constant string";
}

/*----------------------------------------------------------------------------*/
/*                         Interrupt Service Routines                         */
/*----------------------------------------------------------------------------*/
/* none */

/*----------------------------------------------------------------------------*/
/*                            Private Declarations                            */
/*----------------------------------------------------------------------------*/
static uint32_t transform_item(uint32_t input);

/*----------------------------------------------------------------------------*/
/*                             Public Definitions                             */
/*----------------------------------------------------------------------------*/
circular_buffer::circular_buffer()
    : buffer_(CIRCULAR_BUFFER_CAPACITY, 0u),
      head_(0),
      tail_(0),
      count_(0)
{
    // No RUNTIME_ERROR here because constructor cannot fail in C++
}

void circular_buffer::push(uint32_t item)
{
    if (count_ >= CIRCULAR_BUFFER_CAPACITY) {
        RUNTIME_ERROR("push: buffer full", static_cast<int>(count_));
    }

    buffer_[tail_] = transform_item(item);
    tail_ = (tail_ + 1) % CIRCULAR_BUFFER_CAPACITY;
    ++count_;
}

uint32_t circular_buffer::pop()
{
    if (count_ == 0u) {
        RUNTIME_ERROR("pop: buffer empty", static_cast<int>(count_));
    }

    uint32_t item = buffer_[head_];
    head_ = (head_ + 1) % CIRCULAR_BUFFER_CAPACITY;
    --count_;
    return item;
}

/*----------------------------------------------------------------------------*/
/*                             Private Definitions                            */
/*----------------------------------------------------------------------------*/
static uint32_t transform_item(uint32_t input)
{
    // Stub for helper logic
    return input; // Identity transform by default
}
