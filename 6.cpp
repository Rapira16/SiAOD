
#include <iostream>
#include <string>

struct Node {
    int medicalNumber;
    std::string policy;
    std::string dateTreatment;
    int diagnosisCode;
    Node* prev;
    Node* next;
};

class BidirectionalList {
private:
    Node* head;
    Node* tail;

public:
    BidirectionalList() : head(nullptr), tail(nullptr) {}

    // Function to insert a new node before the first node with a given medical policy value
    void insertNode(int medicalNumber, std::string policy, std::string dateTreatment, int diagnosisCode) {
        Node* newNode = new Node{medicalNumber, policy, dateTreatment, diagnosisCode, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            Node* current = head;
            while (current != nullptr) {
                if (current->policy == policy) {
                    newNode->next = current;
                    newNode->prev = current->prev;
                    if (current->prev != nullptr) {
                        current->prev->next = newNode;
                    } else {
                        head = newNode;
                    }
                    current->prev = newNode;
                    return;
                }
                current = current->next;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to delete all nodes with a given diagnosis code value
    void deleteNodesByDiagnosisCode(int diagnosisCode) {
        Node* current = head;
        while (current != nullptr) {
            if (current->diagnosisCode == diagnosisCode) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                Node* temp = current;
                current = current->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    // Function to display the list from left to right
    void displayLeftToRight() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Medical Number: " << current->medicalNumber << ", Policy: " << current->policy << ", Date of Treatment: " << current->dateTreatment << ", Diagnosis Code: " << current->diagnosisCode << std::endl;
            current = current->next;
        }
    }

    // Function to display the list from right to left
    void displayRightToLeft() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << "Medical Number: " << current->medicalNumber << ", Policy: " << current->policy << ", Date of Treatment: " << current->dateTreatment << ", Diagnosis Code: " << current->diagnosisCode << std::endl;
            current = current->prev;
        }
    }

    // Function to search for a node with a given medical policy value
    Node* searchNodeByPolicy(std::string policy) {
        Node* current = head;
        while (current != nullptr) {
            if (current->policy == policy) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

int main() {
    BidirectionalList list;

    // Example usage of the functions
    list.insertNode(1, "Policy1", "2022-01-01", 123);
    list.insertNode(2, "Policy2", "2022-01-02", 456);
    list.insertNode(3, "Policy1", "2022-01-03", 789);

    list.displayLeftToRight();

    list.deleteNodesByDiagnosisCode(123);

    list.displayRightToLeft();

    Node* foundNode = list.searchNodeByPolicy("Policy2");
    if (foundNode != nullptr) {
        std::cout << "Node found - Medical Number: " << foundNode->medicalNumber << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }

    return 0;
}
