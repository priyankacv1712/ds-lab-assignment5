#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n, x;
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=0;i<n;i++) {
        cin >> x;
        Node* t = new Node;
        t->data = x;
        t->next = NULL;
        if(head == NULL) head = tail = t;
        else {
            tail->next = t;
            tail = t;
        }
    }
    Node* prev = NULL;
    Node* curr = head;
    while(curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
