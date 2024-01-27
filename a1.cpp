#include <iostream>
#include <string>

using namespace std;

// โครงสร้างข้อมูลของ Node ที่มีชื่อและคะแนนและชี้ไปยัง Node ถัดไปและก่อนหน้า
struct Node {
    string name;
    int score;
    Node* next;
    Node* prev;
    
    // Constructor สำหรับ Node
    Node(string name, int score) {
        this->name = name;
        this->score = score;
        next = nullptr;
        prev = nullptr;
    }
};

// คลาส Scoreboard ที่มีฟังก์ชันสำหรับการจัดการ Scoreboard
class Scoreboard {
private:
    Node* head;
    Node* tail;
    int size;
    int maxSize;

public:
    // Constructor สำหรับ Scoreboard
    Scoreboard(int maxSize) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        this->maxSize = maxSize;
    }

    // เพิ่มคะแนนใหม่ลงใน Scoreboard
    void insert(string name, int score) {
        Node* newNode = new Node(name, score);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            Node* current = head;
            while (current != nullptr && score < current->score) {
                current = current->next;
            }
            if (current == head) {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            } else if (current == nullptr) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
        size++;
        if (size > maxSize) {
            removeTail();
        }
    }

    // ลบคะแนนท้ายสุดของ Scoreboard
    void removeTail() {
        if (tail != nullptr) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            delete temp;
            size--;
        }
    }

    // แสดงผล Scoreboard ทั้งหมด
    void display() {
        Node* current = head;
        int rank = 1;
        while (current != nullptr) {
            cout << "Rank " << rank << ": " << current->name << " - " << current->score << endl;
            current = current->next;
            rank++;
        }
    }
};

// ฟังก์ชันหลักของโปรแกรม
int main() {
    Scoreboard scoreboard(5); // กำหนดขนาดสูงสุดของ scoreboard เป็น 10
    
    // เพิ่มคะแนนตัวอย่าง
    scoreboard.insert("Player1", 100);
    scoreboard.insert("Player2", 95);
    scoreboard.insert("Player3", 80);
    scoreboard.insert("Player4", 120);
    scoreboard.insert("Player5", 90);
    scoreboard.insert("Player6", 110);
    
    cout << "Current Scoreboard:" << endl;
    scoreboard.display();
    char name[20];
    int score;
    cout << "Name : ";
    cin >> name;
    cout << "Score : ";
    cin >> score;
    cout << endl;
    
    scoreboard.insert(name, score);

    cout << "\nUpdated Scoreboard:" << endl;
    scoreboard.display();

    return 0;
}
