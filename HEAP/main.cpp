#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    cout << "Jesús Uriel Guzmán Mendoza" << endl;
    cout << "Proyecto final" << endl;
    cout << "Estructuras de Datos" << endl;
    cout << "27/05/2019" << endl << endl;
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
    heap.push(3);
    heap.push(4);
    heap.push(5);
    heap.push(5);
    heap.push(5);
    heap.push(5);

    heap.pop();
    heap.pop();
    heap.pop();

    cout << "size(): " << heap.size() << endl;
    cout << "empty(): " << heap.empty() << endl;
    cout << "top(): " << heap.top() << endl;
    size_t localLevel = heap.size();
    cout << "height(): " << heap.height(localLevel) << endl;

    heap.show();
    return 0;
}
