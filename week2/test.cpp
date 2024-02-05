#include <iostream>
using namespace std;

// กำหนดโครงสร้างข้อมูลของ Node
struct Node {
    int data;
    Node* next;
    Node* prev;
    
    // Constructor สำหรับ Node
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// กำหนดคลาส Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor สำหรับ Doubly Linked List
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // เมธอดสำหรับเพิ่มโหนดใหม่ที่ต่ำสุดของลิสต์
    void insertFront(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // เมธอดสำหรับแสดงข้อมูลของลิสต์จากหัวไปท้าย
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// ฟังก์ชันหลักของโปรแกรม
int main() {
    DoublyLinkedList dll;

    // เพิ่มโหนดใหม่ที่ต่ำสุดของลิสต์
    dll.insertFront(3);
    dll.insertFront(7);
    dll.insertFront(1);

    // แสดงข้อมูลของลิสต์จากหัวไปท้าย
    dll.display();

    return 0;
}
