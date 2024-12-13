#include <iostream>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list
};

// Function to detect a loop in a linked list
bool detectCycle(Node* head) {
    Node* slow = head; // Slow pointer
    Node* fast = head; // Fast pointer

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow pointer one step
        fast = fast->next->next;     // Move fast pointer two steps

        if (slow == fast) {
            return true;             // Loop detected
        }
    }

    return false;                    // No loop detected
}

int main() {

    // Test case 1: Linked list with a loop
    Node* head1 = new Node();
    Node* second1 = new Node();
    Node* third1 = new Node();
    Node* fourth1 = new Node();
    Node* fifth1 = new Node();

    head1->data = 1;
    head1->next = second1;
    second1->data = 2;
    second1->next = third1;
    third1->data = 3;
    third1->next = fourth1;
    fourth1->data = 4;
    fourth1->next = fifth1;
    fifth1->data = 5;
    fifth1->next = third1; // Creates a loop

    if (detectCycle(head1)) {
        cout << "Test Case 1: Loop detected in the linked list." << endl;
    } else {
        cout << "Test Case 1: No loop detected in the linked list." << endl;
    }

    // Test case 2: Linked list without a loop
    Node* head2 = new Node();
    Node* second2 = new Node();
    Node* third2 = new Node();

    head2->data = 1;
    head2->next = second2;
    second2->data = 2;
    second2->next = third2;
    third2->data = 3;
    third2->next = nullptr;

    if (detectCycle(head2)) {
        cout << "Test Case 2: Loop detected in the linked list." << endl;
    } else {
        cout << "Test Case 2: No loop detected in the linked list." << endl;
    }

    // Test case 3: Single node pointing to itself
    Node* head3 = new Node();
    head3->data = 1;
    head3->next = head3; // Creates a loop

    if (detectCycle(head3)) {
        cout << "Test Case 3: Loop detected in the linked list." << endl;
    } else {
        cout << "Test Case 3: No loop detected in the linked list." << endl;
    }

    // Clean up memory (delete allocated nodes)
    delete head1; delete second1; delete third1; delete fourth1; delete fifth1;
    delete head2; delete second2; delete third2;
    delete head3;

    return 0;
}
