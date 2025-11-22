#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    if(head == NULL) head = n;
    else {
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
    }
}

int main() {
    int n, x, key, count = 0;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x;
        insertEnd(x);
    }
    cin >> key;
    Node* temp = head;
    while(temp) {
        if(temp->data == key) count++;
        temp = temp->next;
    }
    cout << count << endl;
    while(head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
    }
    temp = head;
    while(temp && temp->next) {
        if(temp->next->data == key) {
            Node* t = temp->next;
            temp->next = t->next;
            delete t;
        } else temp = temp->next;
    }
    temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
