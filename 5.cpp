#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void pushBack(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void insertBeforeFirst(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}


void deleteByKey(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    prev->next = temp->next;
    delete temp;
}

void splitList(Node* L, Node*& L1, Node*& L2) {
    Node* curr = L;
    Node* currL1 = nullptr;
    Node* currL2 = nullptr;

    while (curr != nullptr) {
        if (curr->data > 0) {
            if (L1 == nullptr) {
                L1 = new Node(curr->data);
                currL1 = L1;
            } else {
                currL1->next = new Node(curr->data);
                currL1 = currL1->next;
            }
        } else {
            if (L2 == nullptr) {
                L2 = new Node(curr->data);
                currL2 = L2;
            } else {
                currL2->next = new Node(curr->data);
                currL2 = currL2->next;
            }
        }
        curr = curr->next;
    }
}

void removeNegatives(Node*& L2) {
    Node* prev = nullptr;
    Node* curr = L2;

    while (curr != nullptr) {
        if (curr->data < 0) {
            if (prev == nullptr) {
                L2 = curr->next;
                delete curr;
                curr = L2;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void placeMaxNodeBeforeFirst(Node*& L1) {
    if (L1 == nullptr || L1->next == nullptr) {
        return;
    }

    Node* maxNode = L1;
    Node* curr = L1->next;

    while (curr != nullptr) {
        if (curr->data > maxNode->data) {
            maxNode = curr;
        }
        curr = curr->next;
    }

    if (maxNode != L1) {
        curr = L1;
        while (curr->next != maxNode) {
            curr = curr->next;
        }
        curr->next = maxNode->next;
        maxNode->next = L1;
        L1 = maxNode;
    }
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node* enterElements() {
    Node* head = nullptr;
    int val;
    char choice;

    do {
        cout << "Enter element for the list: ";
        cin >> val;
        pushBack(head, val);

        cout << "Do you want to enter another element? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return head;
}

int main() {
    Node* L;
    char choice;
    cout << "Do you want to make a list or use a default one(1/2)?" << endl;
    cin >> choice;
    if(choice == '2'){
        pushBack(L,3);
        pushBack(L,-5);
        pushBack(L,0);
        pushBack(L,7);
        pushBack(L,10);
        pushBack(L,-6);
    } else {
        L = enterElements();
    }

    cout << "L: ";
    printList(L);
    Node* L1 = nullptr;
    Node* L2 = nullptr;
    splitList(L, L1, L2);

    cout << "L1 before: ";
    printList(L1);

    cout << "L2 before: ";
    printList(L2);

    removeNegatives(L2);
    placeMaxNodeBeforeFirst(L1);

    cout << "L1 after: ";
    printList(L1);

    cout << "L2 after: ";
    printList(L2);

    return 0;
}
