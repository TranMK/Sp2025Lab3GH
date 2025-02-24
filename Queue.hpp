#include <array>
#pragma once
template <class Q> class Queue{
    private:
        std::array<T *, MAX_STACK_SIZE> data;
        size_t size;

    public:
        Stack(size_t size): size(size) {}
        auto Enqueue(T *to_add)->void;
        auto Dequeue()->T*;
        auto Peek()->T*;
        auto length()->size_t;
        auto empty()->void;
    
}