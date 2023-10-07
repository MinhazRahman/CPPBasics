// Code-
#include <iostream>
#include <string>
#define mid '$'

using namespace std;

// tree node definition
struct node
{
    char code;
    int freq;
    node *left, *right;
    node *qnext;
};

// MinHeap implementation
class MinHeap
{
    node *front, *rear;

public:
    MinHeap()
    {
        front = NULL;
        rear = NULL;
    }

    void insert(node *ins)
    {
        // inserting into minheap
        if (front == NULL)
        {
            front = ins;
            rear = ins;
            ins->qnext = NULL;
        }
        else
        {
            node *tmp = front;
            while (tmp->qnext != NULL && ins->freq > tmp->qnext->freq)
            {
                tmp = tmp->qnext;
                if (tmp->qnext == NULL)
                {
                    break;
                }
            }
            ins->qnext = tmp->qnext;
            tmp->qnext = ins;
            if (tmp == rear)
                rear = ins;
        }
    }
    node *delte()
    {
        // deleting from minheap
        node *ret = front;
        front = front->qnext;
        if (ret == rear)
        {
            rear = NULL;
        }
        return ret;
    }

    int size()
    {
        // get size of heap
        node *tmp = front;
        int count = 0;
        while (tmp != NULL)
        {
            count++;
            tmp = tmp->qnext;
        }
        return count;
    }
};

// Implement huffman code algorithm to build huffman tree
class Huff_code
{
    // root of tree
    node *root;
    // print the codes
    void print(node *n, string buffer)
    {
        if (n->code != mid)
        {
            cout << n->code << ": " << buffer << endl;
            return;
        }
        print(n->left, buffer + "0");
        print(n->right, buffer + "1");
    }

public:
    Huff_code()
    {
        root = NULL;
    }

    Huff_code(MinHeap p)
    {
        create(p);
    }

    void create(MinHeap p)
    {
        // adding the elements from heap to tree
        node *n1, *n2, *newnd;
        while (p.size() > 1)
        {
            n1 = p.delte();
            n2 = p.delte();
            newnd = new node;
            newnd->code = mid;
            newnd->freq = n1->freq + n2->freq;
            newnd->left = n1;
            newnd->right = n2;
            p.insert(newnd);
        }
        root = p.delte();
    }

    void show_codes()
    {
        // display codes
        return print(root, "");
    }
};

int main()
{
    // taking all characters in form of string
    string st;
    MinHeap p;
    // input the characters
    cout << "Enter all characters without spaces in between: ";
    cin >> st;
    cout << "Enter their frequencies: ";
    for (int j = 0; j < st.size(); j++)
    {
        // for each character in string, input the frequency of it
        node *n = new node;
        n->code = st[j];
        cin >> n->freq;
        // and insert that character to heap
        p.insert(n);
    }
    // Generate huffman codes of all characters in the heap
    Huff_code h(p);
    // show all codes
    cout << "The character with their codes are: \n";
    h.show_codes();
}