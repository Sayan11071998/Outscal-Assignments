#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Circular Linked List class
class CircularLinkedList
{
private:
    Node* head_node;

public:
    CircularLinkedList() : head_node(nullptr) {}

    // Destructor to free memory
    ~CircularLinkedList()
    {
        if (!head_node) return;
        
        Node* temp = head_node;
        
        do
        {
            Node* next = temp->next;
            delete temp;
            temp = next;
        } while (temp != head_node);
    }

    // Insert at the beginning
    void insertAtBeginning(int value)
    {
        Node* new_node = new Node(value);

        if (!head_node)
        {
            head_node = new_node;
            new_node->next = head_node;
        }
        else
        {
            Node* temp = head_node;
            while (temp->next != head_node) { temp = temp->next; }
            new_node->next = head_node;
            temp->next = new_node;
            head_node = new_node;
        }
    }

    // Insert at the end
    void insertAtEnd(int value)
    {
        Node* new_node = new Node(value);

        if (!head_node)
        {
            head_node = new_node;
            new_node->next = head_node;
        }
        else
        {
            Node* temp = head_node;
            while (temp->next != head_node) { temp = temp->next; }
            temp->next = new_node;
            new_node->next = head_node;
        }
    }

    // Insert at a specified index
    void insertAtIndex(int index, int value)
    {
        if (index < 0) return;

        if (index == 0)
        {
            insertAtBeginning(value);
            return;
        }

        Node* new_node = new Node(value);
        Node* temp = head_node;

        for (int i = 0; i < index - 1; ++i)
        {
            if (temp->next == head_node) return;
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    // Delete from the beginning
    void deleteFromBeginning()
    {
        if (!head_node) return;

        if (head_node->next == head_node)
        {
            delete head_node;
            head_node = nullptr;
        }
        else
        {
            Node* temp = head_node;
            Node* last = head_node;
            while (last->next != head_node) { last = last->next; }
            head_node = head_node->next;
            last->next = head_node;
            delete temp;
        }
    }

    // Delete from the end
    void deleteFromEnd()
    {
        if (!head_node)
        {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }

        if (head_node->next == head_node)
        {
            delete head_node;
            head_node = nullptr;
        }
        else
        {
            Node* temp = head_node;

            while (temp->next->next != head_node) { temp = temp->next; }

            Node* last_node = temp->next;
            temp->next = head_node;
            delete last_node;
        }
    }

    // Delete from a specified index
    void deleteFromIndex(int index)
    {
        if (index < 0 || !head_node) return;

        if (index == 0)
        {
            deleteFromBeginning();
            return;
        }

        Node* temp = head_node;
        Node* prev = nullptr;

        for (int i = 0; i < index; ++i)
        {
            prev = temp;
            temp = temp->next;
            if (temp == head_node) return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Find the middle node
    void findTheMiddle()
    {
        if (!head_node)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* slow = head_node;
        Node* fast = head_node;

        while (fast->next != head_node && fast->next->next != head_node)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle node: " << slow->data << endl;
    }

    // Traverse the list
    void traverse()
    {
        if (!head_node)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head_node;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head_node);
        
        cout << endl;
    }

    // Reverse the circular linked list
    void reverse()
    {
        if (!head_node || head_node->next == head_node) return;

        Node* prev = nullptr, * current = head_node, * next = nullptr;
        Node* last = head_node;
        
        do
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head_node);

        head_node->next = prev;
        head_node = prev;
    }
};

int main() {
    CircularLinkedList cll;

    cout << "== Circular Linked List Operations ==" << endl;

    // Insert at the end
    cout << "Inserting 10, 20, 30 at the end:" << endl;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cout << "List: ";
    cll.traverse();

    // Insert at the beginning
    cout << "Inserting 5 at the beginning:" << endl;
    cll.insertAtBeginning(5);
    cout << "List: ";
    cll.traverse();

    // Delete from the end
    cout << "Deleting from the end:" << endl;
    cll.deleteFromEnd();
    cout << "List: ";
    cll.traverse();

    // Delete from the beginning
    cout << "Deleting from the beginning:" << endl;
    cll.deleteFromBeginning();
    cout << "List: ";
    cll.traverse();

    // Insert at a specific index
    cout << "Inserting 15 at index 1:" << endl;
    cll.insertAtIndex(1, 15);
    cout << "List: ";
    cll.traverse();

    // Delete from a specific index
    cout << "Deleting from index 1:" << endl;
    cll.deleteFromIndex(1);
    cout << "List: ";
    cll.traverse();

    // Find the middle element
    cout << "Finding the middle of the list:" << endl;
    cll.insertAtEnd(40);
    cll.insertAtEnd(50);
    cll.insertAtEnd(60);
    cout << "List: ";
    cll.traverse();
    cll.findTheMiddle();

    // Reverse the list
    cout << "Reversing the list:" << endl;
    cll.reverse();
    cout << "List after reversing: ";
    cll.traverse();

    // Demonstrating with empty list
    cout << "Clearing the list completely:" << endl;
    cll.deleteFromBeginning();
    cll.deleteFromBeginning();
    cll.deleteFromBeginning();
    cll.deleteFromBeginning();
    cout << "List after clearing: ";
    cll.traverse();

    // Reusing the list
    cout << "Adding new elements to the cleared list:" << endl;
    cll.insertAtBeginning(100);
    cll.insertAtEnd(200);
    cll.insertAtEnd(300);
    cout << "List: ";
    cll.traverse();
    cll.findTheMiddle();

    cout << "== End of Operations ==" << endl;

    return 0;
}