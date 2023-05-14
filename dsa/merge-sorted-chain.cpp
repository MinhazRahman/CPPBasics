#include <iostream>
using namespace std;

// exception is thrown if wrong input
class BadInput
{
public:
    BadInput(){};
};
template <class E, class K>
struct Node
{
    E data;
    Node<E, K> *next;
};
template <class E, class K>
class SortedChain
{
public:
    SortedChain() { first = 0; }
    ~SortedChain();
    bool IsEmpty() { return (first == 0); }
    // int Length() const;
    // bool Search (const K& k, const E& e);
    SortedChain<E, K> &Delete(const K &k, E &e);
    SortedChain<E, K> &Insert(const K &k, const E &e);
    SortedChain<E, K> &Merge(const SortedChain<E, K> &chain);
    void Output() const;

private:
    Node<E, K> *first;
};

template <class E, class K>
SortedChain<E, K>::~SortedChain()
{
    Node<E, K> *current = first;
    while (first)
    {
        current = first->next;
        delete first;
        first = current;
    }
}
template <class E, class K>
SortedChain<E, K> &SortedChain<E, K>::Delete(const K &k, E &e)
{
    Node<E, K> *prior = first, *current = first;
    while (current && current->data.Key() < k)
    { // search until key=k or key > k
        prior = current;
        current = current->next;
    }
    if (current && current->data.Key() == k)
    { //
        e = current->data;
        if (first == current) // delete first node
            first = current->next;
        else
            prior->next = current->next;
        delete current;
        return *this;
    }
    else
        throw BadInput();
}

template <class E, class K>
SortedChain<E, K> &SortedChain<E, K>::Insert(const K &k, const E &e)
{
    Node<E, K> *prior = first, *current = first;
    while (current && (current->data).Key() < k)
    {
        prior = current;
        current = current->next;
    }
    if (current && (current->data).Key() == k)
        throw BadInput(); // another node with same key
    else
    {
        Node<E, K> *newp;
        newp = new Node<E, K>;
        if (first == current)
        { // we like to insert on first position
            first = newp;
        }
        else
            prior->next = newp;
        newp->next = current;
        newp->data = e;
        return *this;
    }
}

// Merge function merges chain2 into chain1 and
// returns chain1
template <class E, class K>
SortedChain<E, K> &SortedChain<E, K>::Merge(const SortedChain<E, K> &S2)
{
    Node<E, K> *current = S2.first;
    while (current)
    {
        this->Insert(current->data.Key(), current->data);
        current = current->next;
    }
    return *this;
}

template <class E, class K>
void SortedChain<E, K>::Output() const
{
    Node<E, K> *current = first;
    cout << endl;
    while (current)
    {
        cout << current->data.Key() << ":" << current->data.Value() << " ->";
        current = current->next;
    }
    cout << endl;
}

class TypeE
{
public:
    long key;
    long value;
    TypeE(){};
    long Key() { return key; }
    long Value() { return value; }
};

int main()
{
    try
    {

        SortedChain<TypeE, long> Chain1;
        SortedChain<TypeE, long> Chain2;
        TypeE e;

        // Insert keys and values into chain1
        e.key = 5;
        e.value = 1000;
        Chain1.Insert(e.Key(), e);

        e.key = 8;
        e.value = 500;
        Chain1.Insert(e.Key(), e);

        e.key = 9;
        e.value = 1500;
        Chain1.Insert(e.Key(), e);

        // Insert keys and values into chain1
        e.key = 6;
        e.value = 4000;
        Chain2.Insert(e.Key(), e);

        e.key = 7;
        e.value = 3000;
        Chain2.Insert(e.Key(), e);

        // print the chains
        cout << "Chain1:";
        Chain1.Output();
        cout << "Chain2:";
        Chain2.Output();

        // Merge chain2 with chain1
        Chain1.Merge(Chain2);

        // print Chain1 after merging
        cout << "After merging Chain1 becomes:";
        Chain1.Output();
    }
    catch (BadInput)
    {
        cerr << endl
             << "Bad Input" << endl;
    }

    return 0;
}
