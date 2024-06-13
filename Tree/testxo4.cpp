#include <iostream>
#include <string>

using namespace std;

// Node สำหรับเก็บข้อมูลของสถานะบอร์ดเกม
struct Node {
    string board;
    Node* next;
    
    Node(string board) : board(board), next(NULL) {}
};

// คลาส Queue
class Queue {
private:
    Node* front; // โหนดหน้าของคิว
    Node* rear;  // โหนดท้ายของคิว
    
public:
    Queue() : front(NULL), rear(NULL) {}

    // เมธอดสำหรับเพิ่มสถานะของบอร์ดเกมเข้าไปในคิว
    void push(const string& board) {
        Node* newNode = new Node(board);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // เมธอดสำหรับลบสถานะของบอร์ดเกมออกจากคิว
    void pop() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == NULL) {
                rear = NULL;
            }
        }
    }

    // เมธอดสำหรับตรวจสอบว่าคิวว่างหรือไม่
    bool isEmpty() const {
        return front == NULL;
    }

    // เมธอดสำหรับดึงสถานะของบอร์ดเกมที่อยู่หน้าคิว
    string& frontBoard() {
        return front->board;
    }
};

// คลาส Tree
class Tree {
private:
    int xwin = 0;
    int itree = 0;
    string* table;
    
public:
    Tree(int maxsize) {
        table = new string[maxsize];
    }

    // เมธอดสำหรับสร้างสถานะของบอร์ดเกม Tic Tac Toe ทั้งหมด
    void boardsx(Queue& xo) {
        char play;
        int round = 0;
        xo.push("---------");

        while (!xo.isEmpty()) {
            string markboard = xo.frontBoard();
            xo.pop();
            int ix = 0, io = 0;
            for (int i = 0; i < 9; i++) {
                if (markboard[i] == 'X') {
                    ix++;
                } else if (markboard[i] == 'O') {
                    io++;
                }
            }
            cout << "round : " << round << endl;
            round++;
            display(markboard);
            if (checkxwin(markboard, 'X')) {
                xwin++;
                cout << "============= X Win : " << xwin << endl;
                continue;
            } else if (checkxwin(markboard, 'O')) {
                xwin--;
                cout << "============= X Loss : " << xwin << endl;
                continue;
            }
            if (io < ix) {
                play = 'O';
            } else {
                play = 'X';
            }
            for (int i = 0; i < 9; i++) {
                if (markboard[i] == '-') {
                    string newboard = markboard;
                    newboard[i] = play;
                    table[itree] = newboard;
                    itree++;
                    xo.push(newboard);
                }
            }
        }
    }

    // เมธอดสำหรับตรวจสอบว่ามีผู้ชนะด้วย X หรือไม่
    bool checkxwin(const string& board, char play) {
        for (int i = 0; i < 3; i++) {
            if (board[i * 3] == play && board[i * 3 + 1] == play && board[i * 3 + 2] == play) {
                return true;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (board[i] == play && board[i + 3] == play && board[i + 6] == play) {
                return true;
            }
        }
        if ((board[0] == play && board[4] == play && board[8] == play) || (board[2] == play && board[4] == play && board[6] == play)) {
            return true;
        }
        return false;
    }

    // เมธอดสำหรับแสดงบอร์ดเกม
    void display(const string& board) {
        cout << "___" << endl;
        for (int i = 0; i < 9; i++) {
            cout << board[i];
            if (i % 3 == 2) {
                cout << endl;
            }
        }
    }
};

int main() {
    Queue ox;
    Tree tree(600000);
    tree.boardsx(ox);
    return 0;
}
