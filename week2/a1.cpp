#include <iostream>
#include <string>

using namespace std;


struct Node {
    string name;
    int score;
    Node* next; 
    Node* prev; 

    Node(string name, int score) {
        this->name = name;
        this->score = score;
        next = nullptr;
        prev = nullptr;
    }
};

// กำหนดคลาส Scoreboard
class Scoreboard {
private:
    Node* head;
    Node* tail;
    int size;   
    int maxSize; 

public:
    // Constructor สำหรับ Scoreboard ซึ่งรับขนาดสูงสุดของ Scoreboard
    Scoreboard(int maxSize) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        this->maxSize = maxSize;
    }


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

    // เมธอดสำหรับลบคะแนนที่ตำแหน่งสุดท้ายของ Scoreboard
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

    // เมธอดสำหรับแสดงผลลัพธ์ของ Scoreboard ทั้งหมด
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
    // สร้าง Scoreboard โดยกำหนดขนาดสูงสุดของ Scoreboard เป็น 10
    Scoreboard scoreboard(5);

    // เพิ่มคะแนนตัวอย่าง
    scoreboard.insert("Player1", 100);
    scoreboard.insert("Player2", 95);
    scoreboard.insert("Player3", 80);
    scoreboard.insert("Player4", 120);
    scoreboard.insert("Player5", 90);
    scoreboard.insert("Player6", 110);

    // แสดงผลลัพธ์ของ Scoreboard ก่อนการเพิ่มคะแนนใหม่
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

    // แสดงผลลัพธ์ของ Scoreboard หลังการเพิ่มคะแนนใหม่
    cout << "\nUpdated Scoreboard:" << endl;
    scoreboard.display();

    return 0;
}
