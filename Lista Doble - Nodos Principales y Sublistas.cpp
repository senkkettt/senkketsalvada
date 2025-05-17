#include <iostream>
#include <list> 

using namespace std;

struct Node {
    int data;
    list<int> sublist;
    Node* next;
    Node* prev;

    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class SoftAndWet {
private:
    Node* head;
    Node* tail;

public:
    SoftAndWet() : head(nullptr), tail(nullptr) {}


    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool appendToSublist(int NodeValue, int sublistValue) {
        Node* current = head;
        while (current) {
            if (current->data == NodeValue) {
                current->sublist.push_back(sublistValue);
                return true;
            }
            current = current->next;
        }
        return false; 
    }

    void print() const {
        Node* current = head;
        while (current) {
            cout << "Nodo Principal: " << current->data;
            if (!current->sublist.empty()) {
                cout << " | Sublista: ";
                for (int val : current->sublist) {
                    cout << val << " ";
                }
            }
            cout << endl;
            current = current->next;
        }
    }

    ~SoftAndWet() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }
};

int main() {
    SoftAndWet dll;

    dll.append(1);
    dll.append(2);
    dll.append(3);

    dll.appendToSublist(1, 10);
    dll.appendToSublist(1, 11);
    dll.appendToSublist(2, 20);

    cout << "Estructura de la lista doblemente enlazada con sublistas:\n";
    dll.print();

    return 0;
}