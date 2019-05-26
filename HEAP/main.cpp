#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    HEAP heap;

    heap.push(1);
    heap.push(2);
    heap.push(3);
    heap.push(4);
    heap.push(5);
    heap.push(1);
    heap.push(2);
    heap.push(3);
    heap.push(4);
    heap.push(5);


    heap.pop();


    cout << "size(): " << heap.size() << endl;
    cout << "empty(): " << heap.empty() << endl;
    cout << "top(): " << heap.top() << endl;
    size_t localLevel = heap.size();
    cout << "height(): " << heap.height(localLevel) << endl;

    heap.show();
    return 0;
}
