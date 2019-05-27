#include "heap.h"
#include <math.h>
#include <algorithm>

HEAP::HEAP()
{

}

void HEAP::push(const int &elem)
{
    heap[length++] = elem;
    heapifyUp(size() - 1);
}

void HEAP::pop()
{
    if(empty())
        throw invalid_argument("pop() on empty heap");

    heap[0] = heap[size()-1];
    --length;
    heapifyDown(0);
}

void HEAP::heapifyUp(const size_t &index)
{
    if(index > size())
        throw invalid_argument("heapifyUp() on non-valid position");

    if(index && heap[parent(index)] < heap[index]) {
        swap(heap[index], heap[parent(index)]);
        heapifyUp(parent(index));
    }
}

void HEAP::heapifyDown(const size_t index)
{
    if (index > size())
        throw invalid_argument("heapifyDown() on non-valid position");

    size_t l = left(index);
    size_t r = right(index);

    size_t max_pos = index;

    if (l < size() && heap[l] > heap[index])
        max_pos = l;

    if (r < size() && heap[r] > heap[max_pos])
        max_pos = r;

    if (max_pos != index) {
        swap(heap[index], heap[max_pos]);
        heapifyDown(max_pos);
    }

}

size_t HEAP::left(const size_t &parent)
{
    return 2 * parent + 1;
}

size_t HEAP::right(const size_t &parent)
{
    return 2 * parent + 2;;
}

size_t HEAP::parent(const size_t &child)
{
    return size_t(floor((child - 1) / 2));
}

string HEAP::spaces(const size_t n) const
{
    string s;
    for(size_t i(0); i < n; ++i)
        s += " ";

    return s;
}

size_t HEAP::height(size_t &n) const
{
    if (empty())
        throw invalid_argument("height() on empty heap");
    return size_t(ceil(log2(n + 1) - 1));
}

size_t HEAP::size() const
{
    return length;
}

void HEAP::show() const
{
    if(empty())
        throw invalid_argument("show() on empty heap");

    cout << endl << "Heap: " << endl << endl;

    size_t p = 1;
    size_t cnt = 0;

    size_t h_len = size();
    size_t h_height = height(h_len);
    string h_spaces = spaces(h_height+1);

    cout << h_spaces + "   " << heap[0] << endl << h_spaces + "  ";
    for(size_t i(1); i < size(); ++i) {
        if (i-1 == cnt + size_t(pow(2, p))) {
            cout << endl;
            cout << h_spaces;
            cnt += pow(2, p++);
            if (h_spaces.length() >= 2) {
                h_spaces.pop_back();
                h_spaces.pop_back();
            }
        }
            cout << heap[i] << " ";
    }
    cout << endl << endl;
}

bool HEAP::empty() const
{
    return length == 0;
}

int HEAP::top() const
{
    if(empty())
        throw invalid_argument("top() on empty heap");

    return heap[0];
}

