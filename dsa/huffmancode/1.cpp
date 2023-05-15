#include <iostream>
using namespace std;

class HuffmanCoding
{
private:
    struct Node
    {
        char name;
        int frequency;
        Node *leftChild;
        Node *rightChild;

        Node(char name, int frequency)
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

    Node *createNode(char name, int frequency)
    {
        Node *node = new Node(name, frequency);
        return node;
    }

    void swap(Node **a, Node **b)
    {
        Node *temp = *a;
        *a = *b;
        *b = temp;
    }

    void minHeapify(MinHeap *minHeap, int index)
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

    bool checkSizeOne(MinHeap *minHeap)
    {
        return (minHeap->size == 1);
    }

    Node *deleteSmallest(MinHeap *minHeap)
    {
        Node *temp = minHeap->array[0];
        minHeap->array[0] = minHeap->array[minHeap->size - 1];

        --minHeap->size;
        minHeapify(minHeap, 0);

        return temp;
    }

    void insert(MinHeap *minHeap, Node *node)
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

    void buildMinHeap(MinHeap *minHeap)
    {
        int n = minHeap->size - 1;
        int i;

        for (i = (n - 1) / 2; i >= 0; --i)
            minHeapify(minHeap, i);
    }

    bool isLeaf(Node *root)
    {
        return !(root->leftChild) && !(root->rightChild);
    }

    MinHeap *createAndBuildMinHeap(char letters[], int frequencies[], int size)
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

    Node *buildHuffmanTree(char letters[], int frequencies[], int size)
    {
        Node *left, *right, *top;
        MinHeap *minHeap = createAndBuildMinHeap(letters, frequencies, size);

        while (!checkSizeOne(minHeap))
        {
            left = deleteSmallest(minHeap);
            right = deleteSmallest(minHeap);

            top = createNode('$', left->frequency + right->frequency);
            top->leftChild = left;
            top->rightChild = right;

            insert(minHeap, top);
        }

        return deleteSmallest(minHeap);
    }

    void displayCode(int arr[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << arr[i];
        }

        cout << "\n";
    }

    void traverseHuffmanTree(Node *root, int arr[], int top)
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

    int treeHeight(Node *node)
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

public:
    void displayHuffmanCodes(char letters[], int frequencies[], int size)
    {
        Node *root = buildHuffmanTree(letters, frequencies, size);
        int maxTreeHeight = treeHeight(root);
        int arr[maxTreeHeight];
        int top = 0;

        traverseHuffmanTree(root, arr, top);
    }
};

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

    HuffmanCoding huffman;
    huffman.displayHuffmanCodes(letters, frequencies, n);

    return 0;
}
