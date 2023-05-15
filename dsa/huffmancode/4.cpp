#include <iostream>
using namespace std;

template <class T>
class HuffmanCoding
{
private:
    struct Node
    {
        T name;
        int frequency;
        Node *leftChild;
        Node *rightChild;

        Node(T name, int frequency)
        {
            this->name = name;
            this->frequency = frequency;
            leftChild = rightChild = nullptr;
        }
    };

    struct MinHeap
    {
        int size;
        int capacity;
        Node **array;

        MinHeap(int capacity)
        {
            size = 0;
            this->capacity = capacity;
            array = new Node *[capacity];
        }
    };

    Node *createNode(T name, int frequency);
    void swap(Node **a, Node **b);
    void minHeapify(MinHeap *minHeap, int index);
    bool checkSizeOne(MinHeap *minHeap);
    Node *deleteSmallest(MinHeap *minHeap);
    void insert(MinHeap *minHeap, Node *node);
    void buildMinHeap(MinHeap *minHeap);
    bool isLeaf(Node *root);
    MinHeap *createAndBuildMinHeap(T letters[], int frequencies[], int size);
    Node *buildHuffmanTree(T letters[], int frequencies[], int size);
    void displayCode(int arr[], int n);
    void traverseHuffmanTree(Node *root, int arr[], int top);
    int treeHeight(Node *node);

public:
    void displayHuffmanCodes(T letters[], int frequencies[], int size);
};

template <class T>
typename HuffmanCoding<T>::Node *HuffmanCoding<T>::createNode(T name, int frequency)
{
    Node *node = new Node(name, frequency);
    return node;
}

template <class T>
void HuffmanCoding<T>::swap(Node **a, Node **b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>
void HuffmanCoding<T>::minHeapify(MinHeap *minHeap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index)
    {
        swap(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

template <class T>
bool HuffmanCoding<T>::checkSizeOne(MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

template <class T>
typename HuffmanCoding<T>::Node *HuffmanCoding<T>::deleteSmallest(MinHeap *minHeap)
{
    Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

template <class T>
void HuffmanCoding<T>::insert(MinHeap *minHeap, Node *node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

template <class T>
void HuffmanCoding<T>::buildMinHeap(MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

template <class T>
bool HuffmanCoding<T>::isLeaf(Node *root)
{
    return !(root->leftChild) && !(root->rightChild);
}

template <class T>
typename HuffmanCoding<T>::MinHeap *HuffmanCoding<T>::createAndBuildMinHeap(T letters[], int frequencies[], int size)
{
    MinHeap *minHeap = new MinHeap(size);

    for (int i = 0; i < size; ++i)
    {
        minHeap->array[i] = createNode(letters[i], frequencies[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

template <class T>
typename HuffmanCoding<T>::Node *HuffmanCoding<T>::buildHuffmanTree(T letters[], int frequencies[], int size)
{
    Node *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(letters, frequencies, size);

    while (!checkSizeOne(minHeap))
    {
        left = deleteSmallest(minHeap);
        right = deleteSmallest(minHeap);

        top = createNode(T(), left->frequency + right->frequency);
        top->leftChild = left;
        top->rightChild = right;

        insert(minHeap, top);
    }

    return deleteSmallest(minHeap);
}

template <class T>
void HuffmanCoding<T>::displayCode(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
    }

    cout << "\n";
}

template <class T>
void HuffmanCoding<T>::traverseHuffmanTree(Node *root, int arr[], int top)
{
    if (root->leftChild)
    {
        arr[top] = 0;
        traverseHuffmanTree(root->leftChild, arr, top + 1);
    }

    if (root->rightChild)
    {
        arr[top] = 1;
        traverseHuffmanTree(root->rightChild, arr, top + 1);
    }

    if (isLeaf(root))
    {
        cout << root->name << "  | ";
        displayCode(arr, top);
    }
}

template <class T>
int HuffmanCoding<T>::treeHeight(Node *node)
{
    if (node == nullptr)
        return 0;
    else
    {
        int leftHeight = treeHeight(node->leftChild);
        int rightHeight = treeHeight(node->rightChild);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

template <class T>
void HuffmanCoding<T>::displayHuffmanCodes(T letters[], int frequencies[], int size)
{
    Node *root = buildHuffmanTree(letters, frequencies, size);
    int maxTreeHeight = treeHeight(root);
    int arr[maxTreeHeight];
    int top = 0;

    traverseHuffmanTree(root, arr, top);
}

int main()
{
    int n;
    int totalFrequency = 100;

    cout << "Enter the number of total characters: ";
    cin >> n;

    char letters[n];
    int frequencies[n];
    int sumOfFrequency = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter letter number " << (i + 1) << " and its frequency (not greater than " << (totalFrequency - sumOfFrequency) << ")" << endl;
        cin >> letters[i] >> frequencies[i];
        sumOfFrequency += frequencies[i];
    }

    if (sumOfFrequency != totalFrequency)
    {
        cout << "Error: The total frequency must equal 100." << endl;
        return 0;
    }

    HuffmanCoding<char> huffman;
    huffman.displayHuffmanCodes(letters, frequencies, n);

    return 0;
}