#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* current = head;
        while (current->next) { current = current->next; }
        current->next = newNode;
    }

    void sortAscending() {
        if (!head || !head->next) return;
        bool swapped;
        Node* ptr1;
        Node* lptr = nullptr;
        do {
            swapped = false;
            ptr1 = head;
            while (ptr1->next != lptr) {
                if (ptr1->data > ptr1->next->data) {
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data;
            if (current->next) cout << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        list.push_back(val);
    }
    list.sortAscending();
    list.printList();
    return 0;
}
