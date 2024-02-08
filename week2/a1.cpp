#include <iostream>
#include <string>

using namespace std;


class Node {
    public:
        string name;
        int score;
        Node *next;
        Node *prev;

        Node(string name_in, int score_in) {
            name = name_in;
            score = score_in;
            next = nullptr;
            prev = nullptr;
        }
};


class Scoreboard {
    private:
        Node *head;
        Node *tail;
        int size;   
        int max;

    public:
        Scoreboard(int maxsize) {
            head = nullptr;
            tail = nullptr;
            size = 0;
            max = maxsize;
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
                    // cout << head->score << endl;
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
            if (size > max){
                remove();
            }
        }
    
    
        void remove(){
            cout << tail->name << " was remove from the scoreboard" << endl;
            tail = tail->prev;
            tail->next = nullptr;
            size--;
        }
    

    
        void display(){
            Node *current = head;
            while (current != nullptr){
                cout << current->name << " : " << current->score << endl;
                current = current->next;
            }
        }
};

int main(){
    string name;
    int score ; 
    Scoreboard sb(4);
    
    sb.insert("Ryu",100);
    sb.insert("Chunli",95);
    sb.insert("Ken",98);
    sb.insert("Sagat",94);

    
    sb.display();
    cout << "Name : ";
    cin >> name ;
    cout << "Score : ";
    cin >> score ;
    cout << endl;
    
    sb.insert(name,score);
    
    cout << "Score update" << endl;
    sb.display();
    
    return 0 ;
}