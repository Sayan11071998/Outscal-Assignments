#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = head;
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
    }

    void traverse() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void findTheMiddle() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle node data: " << slow->data << endl;
    }

    void insertAtIndex(int index, int value) {
        if (index < 0) {
            cout << "Invalid index!\n";
            return;
        }

        if (index == 0) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node{value, nullptr};
        Node* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            if (temp->next == head) {
                cout << "Index out of bounds!\n";
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromIndex(int index) {
        if (index < 0 || !head) {
            cout << "Invalid index or empty list!\n";
            return;
        }

        if (index == 0) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            if (temp->next == head) {
                cout << "Index out of bounds!\n";
                return;
            }
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        if (toDelete == head) {
            cout << "Index out of bounds!\n";
            return;
        }
        temp->next = toDelete->next;
        delete toDelete;
    }

    void reverse() {
        if (!head || head->next == head) {
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        Node* tail = head;

        do {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        tail->next = prev;
        head = prev;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.traverse();

    cll.insertAtBeginning(5);
    cll.traverse();

    cll.findTheMiddle();

    cll.insertAtIndex(2, 15);
    cll.traverse();

    cll.deleteFromIndex(3);
    cll.traverse();

    cll.reverse();
    cll.traverse();

    cll.deleteFromBeginning();
    cll.deleteFromEnd();
    cll.traverse();

    return 0;
}
