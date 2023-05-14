
#include <iostream>
using namespace std;

// define the structure of each node on the Huffman tree
struct Node
{
    char name;
    int frequency;
    struct Node *leftChild;
    struct Node *rightChild;
};

// define the array of min heap nodes
struct MinHeap
{
    int size;
    int capacity;
    struct Node **array;
};

// create min heap node with given name and frequency of the letter
struct Node *createNode(char name, int frequency)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->leftChild = node->rightChild = NULL;
    node->name = name;
    node->frequency = frequency;

    return node;
}

// Create min heap using given capacity
struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node **)malloc(minHeap->capacity * sizeof(struct Node *));
    return minHeap;
}

// swap two minimum heap nodes
void swap(struct Node **a, struct Node **b)
{
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

// performs heapify operation on the min-heap
void minHeapify(struct MinHeap *minHeap, int index)
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
int checkSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

// delete the smallest node from the MinHeap
struct Node *deleteSmallest(struct MinHeap *minHeap)
{
    struct Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// insert a node into the MinHeap
void insert(struct MinHeap *minHeap, struct Node *node)
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
void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// checks if the given node is a leaf node
int isLeaf(struct Node *root)
{
    return !(root->leftChild) && !(root->rightChild);
}

// creates and builds a new min-heap from the given arrays of letters and their frequencies
struct MinHeap *createAndBuildMinHeap(char letters[], int frequencies[], int size)
{
    // Create min heap using given capacity
    struct MinHeap *minHeap = createMinHeap(size);

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
struct Node *buildHuffmanTree(char letters[], int frequencies[], int size)
{
    struct Node *left, *right, *top;
    struct MinHeap *minHeap = createAndBuildMinHeap(letters, frequencies, size);

    while (!checkSizeOne(minHeap))
    {
        left = deleteSmallest(minHeap);
        right = deleteSmallest(minHeap);

        // '$' is a special value for internal nodes, not used
        top = createNode('$', left->frequency + right->frequency);

        top->leftChild = left;
        top->rightChild = right;

        insert(minHeap, top);
    }
    return deleteSmallest(minHeap);
}

// print the elements of the  given array
void displayCode(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
    }

    cout << "\n";
}

// prints the Huffman codes for each character in the Huffman tree
void traverseHuffmanTree(struct Node *root, int arr[], int top)
{
    // assign 0 to left edge and traverse
    if (root->leftChild)
    {
        arr[top] = 0;
        traverseHuffmanTree(root->leftChild, arr, top + 1);
    }

    // assign 1 to right edge and traverse
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

// calculate the height of a binary tree
int treeHeight(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        // calculate the height of each subtree
        int leftHeight = treeHeight(node->leftChild);
        int rightHeight = treeHeight(node->rightChild);

        // use the larger one
        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

// build the Huffman tree and print the code of each letter
void displayHuffmanCodes(char letters[], int frequencies[], int size)
{
    // build the huffman tree
    struct Node *root = buildHuffmanTree(letters, frequencies, size);

    // calculating height of Huffman Tree
    int maxTreeHeight = treeHeight(root);

    int arr[maxTreeHeight], top = 0;

    // traverse the huffman tree to display the code for each character
    traverseHuffmanTree(root, arr, top);
}

int main()
{
    int n;
    int totalFrequency = 100;

    cout << "Enter the number of the total characters: ";
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
    displayHuffmanCodes(letters, frequencies, size);

    return 0;
}