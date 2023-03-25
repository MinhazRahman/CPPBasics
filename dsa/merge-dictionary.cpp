using namespace std;

#include <iostream>
#include <vector>

//exception is thrown if wrong input
class BadInput {
public:
    BadInput() {};
};

template<class E, class K>
struct Node {
    E data;
    Node<E, K> *next;
};

template<class E, class K>
class SortedChain {
public:
    SortedChain() { first = 0; }

    ~SortedChain();

    bool IsEmpty() { return (first == 0); }

    //int Length() const;
    //bool Search (const K& k, const E& e);
    SortedChain<E, K> &Delete(const K &k, E &e);

    SortedChain<E, K> &Insert(const K &k, const E &e);

    SortedChain<E, K> &Merge(const SortedChain<E, K> &S2);

    void Output() const;

private:
    Node<E, K> *first;
};

template<class E, class K>
SortedChain<E, K>::~SortedChain() {
    Node<E, K> *current = first;
    while (first) {
        current = first->next;
        delete first;
        first = current;
    }
}

template<class E, class K>
SortedChain<E, K> &SortedChain<E, K>::Delete(const K &k, E &e) {
    Node<E, K> *prior = first, *current = first;
    while (current && current->data.Key() < k) {  //search until key=k or key > k
        prior = current;
        current = current->next;
    }
    if (current && current->data.Key() == k) {  //
        e = current->data;
        if (first == current) //delete first node
            first = current->next;
        else
            prior->next = current->next;
        delete current;
        return *this;
    } else
        throw BadInput();
}

//Merge function Implementation : Ibrahim Avci
template<class E, class K>
SortedChain<E, K> &SortedChain<E, K>::Merge(const SortedChain<E, K> &S2) {
    SortedChain<E, K> *result = new SortedChain<E, K>();

    Node<E, K> *current1 = this->first;
    Node<E, K> *current2 = S2.first;

    while (current1 != nullptr && current2 != nullptr) {
        if ((current1->data).Key() <= (current2->data).Key()) {
            result->Insert(current1->data.Key(), current1->data);
            current1 = current1->next;
        }
        else {
            result->Insert(current2->data.Key(), current2->data);
            current2 = current2->next;
        }
    }

    while (current1 != nullptr) {
        result->Insert(current1->data.Key(), current1->data);
        current1 = current1->next;
    }

    while (current2 != nullptr) {
        result->Insert(current2->data.Key(), current2->data);
        current2 = current2->next;
    }

    this->first = result->first;
    delete current1;
    delete current2;
    return *this;
}
//============ Ibrahim Avci =====================================

template<class E, class K>
SortedChain<E, K> &SortedChain<E, K>::Insert(const K &k, const E &e) {
    Node<E, K> *prior = first, *current = first;
    while (current && (current->data).Key() < k) {
        prior = current;
        current = current->next;
    }
    if (current && (current->data).Key() == k)
        throw BadInput(); //another node with same key
    else {
        Node<E, K> *newp;
        newp = new Node<E, K>;
        if (first == current) { //we like to insert on first position
            first = newp;
        } else
            prior->next = newp;
        newp->next = current;
        newp->data = e;
        return *this;

    }
}

template<class E, class K>
void SortedChain<E, K>::Output() const {
    Node<E, K> *current = first;
    cout << endl;
    while (current) {
        cout << "(" << current->data.Key() << ", "<<current->data.Value() << ") "<< " -> ";
        current = current->next;
    }
}

class TypeE {
public:
    long key;
    long value;

    TypeE() {};

    long Key() { return key; }

    long Value() { return value; }
};

int main() {
    try {
        SortedChain<TypeE, long> Chain1, Chain2;

        //intializing the chain1
        TypeE e;
        e.key = 5;
        e.value = 1000;
        Chain1.Insert(e.Key(), e);
        e.key = 8;
        e.value = 500;
        Chain1.Insert(e.Key(), e);
        e.key = 9;
        e.value = 1500;
        Chain1.Insert(e.Key(), e);

        //initializing the chain2
        e.key = 4;
        e.value = 3000;
        Chain2.Insert(e.Key(), e);
        e.key = 10;
        e.value = 3000;
        Chain2.Insert(e.Key(), e);

        //data in chain1 before calling merge function
        cout << "Chain 1 is :";
        Chain1.Output();
        //data in chain2 before calling merge function
        cout << "\nChain 2 is :";
        Chain2.Output();
        //now call the merge function
        Chain1.Merge(Chain2);
        cout << "\nAfter the merge function";
        //data in chain1 after calling merge function
        //you can run the program and see that it is been merged correctly
        cout << "\nChain 1 is :";
        Chain1.Output();
        //data in chain2 after calling merge function
        //you can run the program and see that it remains unchanged
        cout << "\nChain 2 is :";
        Chain2.Output();
    }
    catch (BadInput) {
        cerr << endl << "Bad Input";
    }
}