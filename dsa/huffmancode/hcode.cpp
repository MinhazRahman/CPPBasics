#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

// define a struct for node
struct Node
{
    char letter;
    int frequency;
    Node *left;
    Node *right;
    Node(char letter, int frequency) : letter(letter), frequency(frequency), left(NULL), right(NULL) {}
};

// define a comparator function for min heap
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

// function to build the Huffman Tree
Node *buildHuffmanTree(priority_queue<Node *, vector<Node *>, Compare> &minHeap)
{
    while (minHeap.size() > 1)
    {
        // delete the first two nodes
        Node *leftNode = minHeap.top();
        minHeap.pop();
        Node *rightNode = minHeap.top();
        minHeap.pop();

        // create a new node with the sum of frequencies
        Node *newNode = new Node('\0', leftNode->frequency + rightNode->frequency);
        newNode->left = leftNode;
        newNode->right = rightNode;

        // add the address of the father node to the deleted nodes
        leftNode->letter = '0';
        leftNode->right = NULL;
        leftNode->left = newNode;
        rightNode->letter = '1';
        rightNode->right = newNode;
        rightNode->left = NULL;

        // insert the new node into the min heap
        minHeap.push(newNode);
    }

    // return the final node which is the root of the Huffman Tree
    return minHeap.top();
}

// function to determine the code for each letter
void determineCode(Node *root, string code)
{
    if (!root)
        return;

    // if a leaf node is found, print the letter and its code
    if (root->letter != '\0')
    {
        cout << root->letter << ": " << code << endl;
    }

    // recursively traverse the left and right subtrees
    determineCode(root->left, code + "0");
    determineCode(root->right, code + "1");
}

int main()
{
    // prompt the user to enter up to 10 letters and their corresponding frequencies
    vector<Node *> nodes;
    int sum = 0;
    int numLetters;
    cout << "Enter the number of letters: ";
    cin >> numLetters;
    for (int i = 0; i < numLetters; i++)
    {
        char letter;
        int frequency;
        cout << "Enter the letter and its frequency (out of 100): ";
        cin >> letter >> frequency;
        nodes.push_back(new Node(letter, frequency));
        sum += frequency;
    }

    // check if the total frequency equals 100
    if (sum != 100)
    {
        cout << "Error: The total frequency must equal 100." << endl;
        return 0;
    }

    // build the min heap
    priority_queue<Node *, vector<Node *>, Compare> minHeap(nodes.begin(), nodes.end());

    // build the Huffman Tree
    Node *root = buildHuffmanTree(minHeap);

    // determine the code for each letter
    determineCode(root, "");

    return 0;
}
