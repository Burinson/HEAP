#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

class HEAP
{
private:
    int heap [1000005];
    size_t length = 0;
    void heapifyUp(const size_t &index);
    void heapifyDown(const size_t index);
    size_t left(const size_t &parent);
    size_t right(const size_t &parent);
    size_t parent(const size_t &child);
    string spaces(const size_t n) const;

public:
    HEAP();
    void push(const int &elem);
    void pop();
    size_t size() const;
    void show() const;
    bool empty() const;
    int top() const;
    size_t height(size_t &n) const;

};

#endif // HEAP_H
