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
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}
