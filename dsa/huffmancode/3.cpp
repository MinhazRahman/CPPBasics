#include <iostream>
using namespace std;

// define the structure of each node on the Huffman tree
template <class T>
struct Node
{
    T name;
    int frequency;
    struct Node<T> *leftChild;
    struct Node<T> *rightChild;
};

// define the array of min heap nodes
template <class T>
struct MinHeap
{
    int size;
    int capacity;
    struct Node<T> **array;
};

// create min heap node with given name and frequency of the letter
template <class T>
struct Node<T> *createNode(T name, int frequency)
{
    struct Node<T> *node = (struct Node<T> *)malloc(sizeof(struct Node<T>));

    node->leftChild = node->rightChild = NULL;
    node->name = name;
    node->frequency = frequency;

    return node;
}

// Create min heap using given capacity
template <class T>
struct MinHeap<T> *createMinHeap(int capacity)
{
    struct MinHeap<T> *minHeap = (struct MinHeap<T> *)malloc(sizeof(struct MinHeap<T>));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node<T> **)malloc(minHeap->capacity * sizeof(struct Node<T> *));
    return minHeap;
}

// swap two minimum heap nodes
template <class T>
void swap(struct Node<T> **a, struct Node<T> **b)
{
    struct Node<T> *temp = *a;
    *a = *b;
    *b = temp;
}

// performs heapify operation on the min-heap
template <class T>
void minHeapify(struct MinHeap<T> *minHeap, int index)
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
        swap(&minHeap->array[smallest],
             &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

// checks if the min-heap has only one node
template <class T>
int checkSizeOne(struct MinHeap<T> *minHeap)
{
    return (minHeap->size == 1);
}

// delete the smallest node from the MinHeap
template <class T>
struct Node<T> *deleteSmallest(struct MinHeap<T> *minHeap)
{
    struct Node<T> *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// insert a node into the MinHeap
template <class T>
void insert(struct MinHeap<T> *minHeap, struct Node<T> *node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->frequency < minHeap->array[(i - 1) / 2]->frequency)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
        minHeap->array[i] = node;
    }
}
// build the min heap
template <class T>
void buildMinHeap(struct MinHeap<T> *minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// checks if the given node is a leaf node
template <class T>
int isLeaf(struct Node<T> *root)
{
    return !(root->leftChild) && !(root->rightChild);
}

// creates and builds a new min-heap from the given arrays of letters and their frequencies
template <class T>
struct MinHeap<T> *createAndBuildMinHeap(T letters[], int frequencies[], int size)
{
    // Create min heap using given capacity
    struct MinHeap<T> *minHeap = createMinHeap<T>(size);

    // for each letter create a node
    for (int i = 0; i < size; ++i)
    {
        minHeap->array[i] = createNode<T>(letters[i], frequencies[i]);
    }

    minHeap->size = size;
    // build the min heap
    buildMinHeap<T>(minHeap);

    return minHeap;
}

// builds the Huffman tree from the given arrays of letters and their frequencies
template <class T>
struct Node<T> *buildHuffmanTree(T letters[], int frequencies[], int size)
{
    struct Node<T> *left, *right, *top;
    struct MinHeap<T> *minHeap = createAndBuildMinHeap<T>(letters, frequencies, size);

    while (!checkSizeOne<T>(minHeap))
    {
        // get two nodes with smallest frequencies from the min heap
        left = deleteSmallest<T>(minHeap);
        right = deleteSmallest<T>(minHeap);

        // create a new node whose frequency is equal to the sum of the frequencies
        // of the two smallest nodes.
        // '$' is a special value for internal nodes, not used
        top = createNode<T>('$', left->frequency + right->frequency);

        top->leftChild = left;
        top->rightChild = right;

        insert<T>(minHeap, top);
    }
    return deleteSmallest<T>(minHeap);
}

// print the elements of the given array that contains the code for each letter
template <class T>
void displayCode(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
    }

    cout << "\n";
}

// prints the Huffman codes for each character in the Huffman tree
template <class T>
void traverseHuffmanTree(struct Node<T> *root, int arr[], int top)
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
    if (isLeaf<T>(root))
    {
        cout << root->name << "  | ";
        displayCode<T>(arr, top);
    }
}

// calculate the height of a binary tree
template <class T>
int treeHeight(Node<T> *node)
{
    if (node == NULL)
        return 0;
    else
    {
        // calculate the height of each subtree
        int leftHeight = treeHeight<T>(node->leftChild);
        int rightHeight = treeHeight<T>(node->rightChild);

        // use the larger one
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

// build the Huffman tree and print the code of each letter
template <class T>
void displayHuffmanCodes(T letters[], int frequencies[], int size)
{
    // build the huffman tree
    struct Node<T> *root = buildHuffmanTree<T>(letters, frequencies, size);

    // calculating height of Huffman Tree
    int maxTreeHeight = treeHeight<T>(root);

    int arr[maxTreeHeight], top = 0;

    // traverse the huffman tree to display the code for each character
    traverseHuffmanTree<T>(root, arr, top);
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

    // check if the sum of all the frequencies equals 100
    if (sumOfFrequency != totalFrequency)
    {
        cout << "Error: The total frequency must equal 100." << endl;
        return 0;
    }

    int size = sizeof(letters) / sizeof(letters[0]);

    cout << "Letter | Huffman code ";
    cout << "\n----------------------\n";
    displayHuffmanCodes<char>(letters, frequencies, size);

    return 0;
}
