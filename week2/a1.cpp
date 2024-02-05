#include <iostream>
#include <string>

using namespace std;


struct Node {
    string name;
    int score;
    Node *next; 
    Node *prev; 

    Node(string name, int score) {
        this->name = name;
        this->score = score;
        next = nullptr;
        prev = nullptr;
    }
};


class Scoreboard {
private:
    Node *head;
    Node *tail;
    int size;   


public:
    Scoreboard(int maxSize) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        int maxsize = maxSize;
    }
    
    void insert(string name , int score){
        Node *newNode = new Node(name,score);
        if (head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else {
            Node *current = head ;
            while (current != nullptr && score < current->score){
                current = current->next;
            }
            if (current == nullptr){
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else if (current == head){
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            else {
                // cout << current->score << endl;
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
        size++;
        if (size > maxsize){
            remove();
        }
    }
    
    void remove(){
        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        size--;
    }
    

    
    void display(){
        Node *current = head;
        int rank = 1;
        while (current != nullptr){
            cout << "Rank " << rank << " : " << current->name << " : " << current->score << endl;
            current = current->next;
            rank++;
        }
    }
};

int main(){
    string name;
    int score ; 
    Scoreboard sb(5);
    
    sb.insert("Player1",120);
    sb.insert("Player2",90);
    sb.insert("Player3",80);
    sb.insert("Player4",70);
    sb.insert("Player5",85);
    sb.insert("Player6",100);
    
    sb.display();
    cout << "Name : ";
    cin >> name ;
    cout << "Score : ";
    cin >> score ;
    
    sb.insert(name,score);
    
    cout << "Score update" << endl;
    sb.display();
    
    return 0 ;
}



