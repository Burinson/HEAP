#include "heap.h"
#include <math.h>
#include <algorithm>

HEAP::HEAP()
{

}

void HEAP::insert(const int &elem)
{
    heap.push_back(elem);

    if(size() > 0)
        heapifyUp(size() - 1);

}

void HEAP::pop()
{
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);

}

void HEAP::heapifyUp(const size_t &index)
{
    while (heap[parent(index)] < heap[index]) {
        int temp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = temp;

        heapifyUp(parent(index));
    }
}

void HEAP::heapifyDown(const size_t &index)
{
    int maximum = max(heap[left(index)], heap[right(index)]);
    size_t max_pos = find(heap.begin(), heap.end(), maximum) - heap.begin();

    while (heap[index] < heap[max_pos]) {
        int temp = heap[index];
        heap[index] = heap[max_pos];
        heap[max_pos] = temp;

        heapifyDown(max_pos);
    }
}

size_t HEAP::left(const size_t &parent)
{
    size_t pos = 2 * parent + 1;
    return pos;
}

size_t HEAP::right(const size_t &parent)
{
    size_t pos = 2 * parent + 2;
    return pos;
}

size_t HEAP::parent(const size_t &child)
{
    size_t pos = size_t(floor((child - 1) / 2));
    return pos;
}

size_t HEAP::size() const
{
    return heap.size();
}

void HEAP::show() const
{
    cout << "Heap: " << endl << endl;

    size_t p = 1;
    size_t cnt = 0;

    cout << heap.front() << endl;
    for(size_t i(1); i < size(); ++i) {
        if (i-1 == cnt + size_t(pow(2, p))) {
            cout << endl;
            cnt += pow(2, p++);
        }
        cout <<  heap[i] << " ";
    }
    cout << endl << endl;
}

