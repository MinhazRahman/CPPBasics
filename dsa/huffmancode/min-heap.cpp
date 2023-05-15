#include <iostream>
#include <new>
using namespace std;

class NoMem
{
public:
    NoMem() {}
};

void my_new_handler()
{
    throw NoMem();
}

class OutOfBounds
{
public:
    OutOfBounds() {}
};

template <class T>
struct Node
{
    char name;
    int frequency;
    Node<T> *leftChild;
    Node<T> *rightChild;
};

template <class T>
class MinHeap
{
public:
    MinHeap(int MSize)
    {
        MaxSize = MSize;
        heap = new T[MaxSize + 1];
        Size = 0;
    }
    ~MinHeap() { delete[] heap; }
    MinHeap<T> &Insert(T &x);
    MinHeap<T> &Delete(T &x);
    void Output() const;
    int Size;

private:
    int MaxSize;
    T *heap;
};

template <class T>
MinHeap<T> &MinHeap<T>::Insert(T &x)
{
    if (Size == MaxSize)
        throw NoMem();
    else
    {
        int i = ++Size;
        while (i != 1 && x < heap[i / 2])
        {
            heap[i] = heap[i / 2];
            i /= 2;
        }
        heap[i] = x;
        return *this;
    }
}

template <class T>
MinHeap<T> &MinHeap<T>::Delete(T &x)
{
    if (Size == 0)
        throw OutOfBounds();
    x = heap[1];        // root has the smallest key
    T y = heap[Size--]; // last element
    int vacant = 1;
    int child = 2; // make child = left child
    while (child <= Size)
    {
        if (child < Size && heap[child] > heap[child + 1])
            ++child;
        // right child < left child
        if (y <= heap[child])
            break;
        heap[vacant] = heap[child]; // move smaller child
        vacant = child;             // new vacant
        child = child * 2;          // new child of vacant
    }
    heap[vacant] = y;
    return *this;
}

// outputs list
template <class T>
void MinHeap<T>::Output() const
{
    for (int i = 1; i <= this->Size; i++)
    {
        cout << this->heap[i] << " ";
    }
    cout << endl;
}

int main()
{

    set_new_handler(my_new_handler); // when new fails, new call my_new_handler
                                     //  which in return throws a NoMem exception
    try
    {
        MinHeap<int> myHeap(10);
        Node<int> *node = new Node<int>;
        node->name = 'a';
        int arr[] = {30, 20, 15, 5, 10, 12, 6, 40};
        int size = sizeof(arr) / sizeof(arr[0]);
        for (int i = 0; i < size; i++)
        {
            myHeap.Insert(arr[i]);
        }

        myHeap.Output();
    }
    catch (NoMem)
    {
        cerr << "Not enough memory" << endl;
    }
    catch (OutOfBounds)
    {
        cerr << "Out of bounds " << endl;
    }

    return 0;
}
