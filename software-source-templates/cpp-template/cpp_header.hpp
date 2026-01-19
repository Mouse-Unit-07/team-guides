/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : CircularBuffer.hpp                                    */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef CIRCULAR_BUFFER_HPP
#define CIRCULAR_BUFFER_HPP

/*----------------------------------------------------------------------------*/
/*                             Public Declarations                            */
/*----------------------------------------------------------------------------*/
class CircularBuffer {
public:
    CircularBuffer();
    ~CircularBuffer() = default;

    void push(uint32_t item);
    uint32_t pop();

private:
    std::vector<uint32_t> buffer_;
    std::size_t head_;
    std::size_t tail_;
    std::size_t count_;
};

#endif // CIRCULAR_BUFFER_HPP
