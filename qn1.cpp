#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}

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

void insertBefore(int val, int x) {
    if(head == NULL) return;
    if(head->data == val) insertBegin(x);
    else {
        Node* temp = head;
        while(temp->next && temp->next->data != val) temp = temp->next;
        if(temp->next) {
            Node* n = new Node;
            n->data = x;
            n->next = temp->next;
            temp->next = n;
        }
    }
}

void insertAfter(int val, int x) {
    Node* temp = head;
    while(temp && temp->data != val) temp = temp->next;
    if(temp) {
        Node* n = new Node;
        n->data = x;
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteBegin() {
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if(head == NULL) return;
    if(head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while(temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
}

void deleteValue(int val) {
    if(head == NULL) return;
    if(head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* temp = head;
        while(temp->next && temp->next->data != val) temp = temp->next;
        if(temp->next) {
            Node* t = temp->next;
            temp->next = t->next;
            delete t;
        }
    }
}

void searchNode(int val) {
    Node* temp = head;
    int pos = 1;
    while(temp) {
        if(temp->data == val) {
            cout << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << -1 << endl;
}

void display() {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int ch, x, v;
    while(1) {
        cout << "1 InsertBegin\n2 InsertEnd\n3 InsertBefore\n4 InsertAfter\n5 DeleteBegin\n6 DeleteEnd\n7 DeleteValue\n8 Search\n9 Display\n10 Exit\n";
        cin >> ch;
        switch(ch) {
            case 1: cin >> x; insertBegin(x); break;
            case 2: cin >> x; insertEnd(x); break;
            case 3: cin >> v >> x; insertBefore(v,x); break;
            case 4: cin >> v >> x; insertAfter(v,x); break;
            case 5: deleteBegin(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> x; deleteValue(x); break;
            case 8: cin >> x; searchNode(x); break;
            case 9: display(); break;
            case 10: return 0;
        }
    }
}
