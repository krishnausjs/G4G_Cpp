#include <iostream>
using namespace std;

typedef struct node {
        int data;
        struct node *next;
}Node;

class linkedList {
    Node *head;
public:
    linkedList() {
        head = NULL;
    }
    int push(int val);
    int get(int index);
    void addAtTail(int val);
    void display();
};

int linkedList::push(int val) {
    Node *newNode = new Node;
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void linkedList::addAtTail(int val) {
        Node *newNode = new Node;
        Node *cur = head;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        newNode->data = val;
        newNode ->next = NULL;
        cur->next = newNode;
        newNode = cur;
}

void linkedList::display() {
    while(head != NULL) {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{
    linkedList ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    ll.addAtTail(4);
    ll.display();
    return 0;
}