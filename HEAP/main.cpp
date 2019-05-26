#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    HEAP heap;

    heap.insert(20);
    heap.insert(5);
    heap.insert(3);
    heap.insert(7);
    heap.insert(9);
    heap.insert(2);
    heap.insert(1);
    heap.insert(13);
    heap.insert(8);
    heap.insert(6);

    cout << "size(): " << heap.size() << endl;
    heap.show();
    return 0;
}
