#include <iostream>
using namespace std;

template <class T>
class HuffmanCoding
{
private:
    // define the structure of each node on the Huffman tree
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

    // define the array of min heap nodes
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
    Node *deleteSmallestFromHeap(MinHeap *minHeap);
    void insertIntoHeap(MinHeap *minHeap, Node *node);
    void buildMinHeap(MinHeap *minHeap);
    bool isLeaf(Node *root);
    MinHeap *createAndBuildMinHeap(T letters[], int frequencies[], int size);
    Node *buildHuffmanTree(T letters[], int frequencies[], int size);
    void displayLetterCode(int arr[], int n);
    void traverseHuffmanTree(Node *root, int arr[], int top);
    int treeHeight(Node *node);

public:
    void determineHuffmanCode(T letters[], int frequencies[], int size);
};

// create min heap node with given name and frequency of the letter
template <class T>
typename HuffmanCoding<T>::Node *HuffmanCoding<T>::createNode(T name, int frequency)
{
    Node *node = new Node(name, frequency);
    return node;
}

// swap two minimum heap nodes
template <class T>
void HuffmanCoding<T>::swap(Node **a, Node **b)
{
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

// performs heapify operation on the min-heap
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

// checks if the min-heap has only one node
template <class T>
bool HuffmanCoding<T>::checkSizeOne(MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

// delete the smallest node from the MinHeap
template <class T>
typename HuffmanCoding<T>::Node *HuffmanCoding<T>::deleteSmallestFromHeap(MinHeap *minHeap)
{
    Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// insert a node into the MinHeap
template <class T>
void HuffmanCoding<T>::insertIntoHeap(MinHeap *minHeap, Node *node)
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

// build the min heap
template <class T>
void HuffmanCoding<T>::buildMinHeap(MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// checks if the given node is a leaf node
template <class T>
bool HuffmanCoding<T>::isLeaf(Node *root)
{
    return !(root->leftChild) && !(root->rightChild);
}

// creates and builds a new min-heap from the given arrays of letters and their frequencies
template <class T>
typename HuffmanCoding<T>::MinHeap *HuffmanCoding<T>::createAndBuildMinHeap(T letters[], int frequencies[], int size)
{
    // Create min heap using given capacity
    MinHeap *minHeap = new MinHeap(size);

    // for each letter create a node
    for (int i = 0; i < size; ++i)
    {
        minHeap->array[i] = createNode(letters[i], frequencies[i]);
    }

    minHeap->size = size;
    // build the min heap
    buildMinHeap(minHeap);

    return minHeap;
}

// builds the Huffman tree from the given arrays of letters and their frequencies
template <class T>
typename HuffmanCoding<T>::Node *HuffmanCoding<T>::buildHuffmanTree(T letters[], int frequencies[], int size)
{
    Node *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(letters, frequencies, size);

    while (!checkSizeOne(minHeap))
    {
        // get two nodes with smallest frequencies from the min heap
        left = deleteSmallestFromHeap(minHeap);
        right = deleteSmallestFromHeap(minHeap);

        // create a new node whose frequency is equal to the sum of the frequencies
        // of the two smallest nodes.
        top = createNode(T(), left->frequency + right->frequency);
        top->leftChild = left;
        top->rightChild = right;

        insertIntoHeap(minHeap, top);
    }

    return deleteSmallestFromHeap(minHeap);
}

// print the elements of the  given array that contains the code for each letter
template <class T>
void HuffmanCoding<T>::displayLetterCode(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
    }

    cout << "\n";
}

// prints the Huffman codes for each character in the Huffman tree
template <class T>
void HuffmanCoding<T>::traverseHuffmanTree(Node *root, int arr[], int top)
{
    // assign 0 to the left edge
    if (root->leftChild)
    {
        arr[top] = 0;
        traverseHuffmanTree(root->leftChild, arr, top + 1);
    }

    // assign 1 to the right edge
    if (root->rightChild)
    {
        arr[top] = 1;
        traverseHuffmanTree(root->rightChild, arr, top + 1);
    }

    if (isLeaf(root))
    {
        cout << root->name << "  | ";
        displayLetterCode(arr, top);
    }
}

// calculate the height of a binary tree
template <class T>
int HuffmanCoding<T>::treeHeight(Node *node)
{
    if (node == nullptr)
        return 0;
    else
    {
        // calculate the height of each subtree
        int leftHeight = treeHeight(node->leftChild);
        int rightHeight = treeHeight(node->rightChild);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

// build the Huffman tree and print the code of each letter
template <class T>
void HuffmanCoding<T>::determineHuffmanCode(T letters[], int frequencies[], int size)
{
    // build the huffman tree
    Node *root = buildHuffmanTree(letters, frequencies, size);
    // calculating height of Huffman Tree
    int maxTreeHeight = treeHeight(root);
    int arr[maxTreeHeight];
    int top = 0;

    // traverse the huffman tree to display the code for each character
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
        cout << "Enter letter number " << (i + 1) << " and its frequency (out of " << (totalFrequency - sumOfFrequency) << ")" << endl;
        cin >> letters[i] >> frequencies[i];
        sumOfFrequency += frequencies[i];
    }

    // check if the sum of all the frequencies equals 100
    if (sumOfFrequency != totalFrequency)
    {
        cout << "Error: The total frequency must equal 100." << endl;
        return 0;
    }

    cout << "\nLetter | Huffman code ";
    cout << "\n----------------------\n";

    // create an object reference and call the method to display the letter codes
    HuffmanCoding<char> huffman;
    huffman.determineHuffmanCode(letters, frequencies, n);

    return 0;
}