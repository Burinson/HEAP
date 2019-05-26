#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    HEAP heap;

    heap.insert(40);
    heap.insert(18);
    heap.insert(20);
    heap.insert(15);
    heap.insert(13);
    heap.insert(9);
    heap.insert(19);
    heap.insert(1);
    heap.insert(3);
    heap.insert(8);

    heap.pop();
    heap.pop();

    cout << "size(): " << heap.size() << endl;
    heap.show();
    return 0;
}
