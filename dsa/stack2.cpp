#include <iostream> //example of operator overloading
using namespace std;

template <class T>
class Stack
{
public:
    Stack(int n);
    Stack(Stack<T> &s);                           // copy constructor
    ~Stack() { delete[] stackPtr; }               // destructor
    Stack<T> operator+(const Stack<T> &s2) const; // overloading + (concatenation + operator)
    Stack<T> &operator=(const Stack<T> &s);       // overloading + (assignment = operator)
    bool push(const T &element);                  // Push element onto stack
    bool pop(T &element);                         // Pop element off stack
private:
    int size;    // size of stack
    int top;     // location of the top element
    T *stackPtr; // pointer to stack
    bool isEmpty() { return (top == -1); }
    bool isFull() { return (top == size - 1); }
};

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &s) // overloading = (assignment = operator)
{
    if (&s != this)
    {
        delete[] stackPtr;
        size = s.size;
        top = s.top;
        stackPtr = new T[size];
        for (int i = 0; i < size; i++)
            stackPtr[i] = s.stackPtr[i];
    }

    return *this;
}

/*
 * + operator what it does is to concatenate two stacks
 * s1 and s2
 * example s1={1,3} and s2={4,6,7,8}, suppose that size s1=3, and size s2=7
 * top of stack1 = 1 (top element = 3}, top of stack2 = 3 (top element = 8)
 * totalSize= 10 (that is size of s1 + size of s2)
 * temp={1,3,4,6,7,8}, where the top is 5 and the top element is 8
 */

template <class T>
Stack<T> Stack<T>::operator+(const Stack<T> &s2) const // overloading + (concatenation + operator)
{
    // totalSize = size of stack1 + size of stack2
    int totalSize = this->size + s2.size;

    Stack<T> temp(totalSize); 
    // do the concatenation
    int i = 0;
    while (temp.push(stackPtr[i++]) && i < size);

    i = 0;
    while (temp.push(s2.stackPtr[i++]) && i < s2.size);

    return temp;
}

template <class T>
Stack<T>::Stack(Stack<T> &s) // copy constructor
{
    size = s.size;
    stackPtr = new T[size];
    top = s.top;
    for (int i = 0; i < size; i++)
        stackPtr[i] = s.stackPtr[i]; // allocate space for size elements of type T
}

template <class T>
Stack<T>::Stack(int n)
{
    size = n > 0 ? n : 10;
    top = -1;               // empty stack
    stackPtr = new T[size]; // allocate space for size elements of type T
}

template <class T>
bool Stack<T>::push(const T &element)
{
    if (!isFull())
    {
        stackPtr[++top] = element;
        return (true);
    }
    return (false);
}

template <class T>
bool Stack<T>::pop(T &element)
{
    if (!isEmpty())
    {
        element = stackPtr[top--];
        return true;
    }
    return false;
}

int main()
{
    int size1, size2, element;

    cout << endl
         << "Enter size of stack1: ";
    cin >> size1;
    cout << endl
         << "Enter size of stack2: ";
    cin >> size2;

    Stack<int> intS1(size1), intS2(size2), intS3(1);

    // create stack1
    do
    {
        cout << endl
             << "Enter element of stack1: ";
        cin >> element;
    } while (intS1.push(element));

    // create stack2
    do
    {
        cout << endl
             << "Enter element of stack2: ";
        cin >> element;
    } while (intS2.push(element));

    // concatenate two stacks
    intS3 = intS1 + intS2;

    cout << endl
         << "displaying S3";
    cout << endl
         << "=============";
    while (intS3.pop(element))
        cout << endl
             << "element: " << element;
    cout << endl;

    return 0;
}
