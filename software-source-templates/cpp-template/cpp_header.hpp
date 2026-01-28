/*-------------------------------- FILE INFO ---------------------------------*/
/* Filename           : cpp_header.hpp                                        */
/*                                                                            */
/* File description here...                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#ifndef CIRCULAR_BUFFER_HPP
#define CIRCULAR_BUFFER_HPP

/*----------------------------------------------------------------------------*/
/*                             Public Declarations                            */
/*----------------------------------------------------------------------------*/
class circular_buffer {
public:
    circular_buffer();
    ~circular_buffer() = default;

    void push(uint32_t item);
    uint32_t pop();

private:
    std::vector<uint32_t> buffer_;
    std::size_t head_;
    std::size_t tail_;
    std::size_t count_;
};

#endif // CIRCULAR_BUFFER_HPP
