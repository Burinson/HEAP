#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>

using namespace std;

class HEAP
{
private:
    vector<int> heap;
    void heapify(const size_t &index);
    size_t left(const size_t &parent);
    size_t right(const size_t &parent);
    size_t parent(const size_t &child);

public:
    HEAP();
    void insert(const int &elem);
    size_t size() const;
    void show() const;

};

#endif // HEAP_H
