#include <iostream>
#include <string>
using namespace std;
struct Node {
    string board;
    Node* next;
    
    Node(string boarda){
        board = boarda;
        next = NULL;

    }
};

// คลาส Queue
class Queue {
    
public:
    Node* fronta; // โหนดหน้าของคิว
    Node* rear;
    Queue() : fronta(NULL), rear(NULL) {}

    // เมธอดสำหรับเพิ่มสถานะของบอร์ดเกมเข้าไปในคิว
    void push(const string& board) {
        Node* newNode = new Node(board);
        if (empty()) {
            fronta = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // เมธอดสำหรับลบสถานะของบอร์ดเกมออกจากคิว
    void pop() {
        if (!empty()) {
            Node* temp = fronta;
            fronta = fronta->next;
            delete temp;
            if (fronta == NULL) {
                rear = NULL;
            }
        }
    }

    // เมธอดสำหรับตรวจสอบว่าคิวว่างหรือไม่
    bool empty() const {
        return fronta == NULL;
    }

    // เมธอดสำหรับดึงสถานะของบอร์ดเกมที่อยู่หน้าคิว
    string& front() {
        return fronta->board;
    }
};
int node=0;
class Tree{
    public : 
        int i,j;
        int size;
        int itree=0,xwin=0;
        Queue q1,q2,q3,q4,q5,q6,q7,q8,q9;
        int set;
        string *table;
        Tree(int maxsize){            
            size = maxsize ;
            table = new string[size];
        }
    void boardsx(Queue &xo){
        char play;
        int round=0;
        string newboard;
        xo.push("_________");

        while (!xo.empty()){
            string markboard = xo.front();
            xo.pop();
            int ix=0,io=0;
            for(i=0;i<9;i++){
                if(markboard[i]=='x'){ix++;}
                else if (markboard[i]=='o'){io++;}
            }
            if(checkxwin(markboard,'x')){
                continue;
            }
            else if(checkxwin(markboard,'o')){
                continue;
            }
            if(io<ix){
                play = 'o';
            }
            else{
                play = 'x';
            }
            for (i=0;i<9;i++){
                if(markboard[i]=='_'){
                    newboard = markboard;
                    newboard[i] = play;
                    table[itree] = newboard;
                    itree++;
                    xo.push(newboard);
                    set = ix+io;
                    if (set==0){q1.push(table[itree-1]);}
                    else if (set==1){q2.push(table[itree-1]);}
                    else if (set==2){q3.push(table[itree-1]);}
                    else if (set==3){q4.push(table[itree-1]);}
                    else if (set==4){q5.push(table[itree-1]);}
                    else if (set==5){q6.push(table[itree-1]);}
                    else if (set==6){q7.push(table[itree-1]);}
                    else if (set==7){q8.push(table[itree-1]);}
                    else if (set==8){q9.push(table[itree-1]);}
                    node++;
                }
            }
        }
        while (!q1.empty()){
            round++;
            while(!q2.empty()){
                if (check(q1.front(),q2.front(),1)){
                    round++;
                    while(!q3.empty()){
                        if(check(q2.front(),q3.front(),2)){
                            round++;
                            while(!q4.empty()){
                                if(check(q3.front(),q4.front(),3)){
                                    round++;
                                    while(!q5.empty()){
                                        if(check(q4.front(),q5.front(),4)){
                                            round++;
                                            if (checkxwin(q5.front(),'x')){
                                                cout << "|" << q1.front()[0] << q1.front()[1] << q1.front()[2] << "|" << q2.front()[0] << q2.front()[1] << q2.front()[2] << "|" << q3.front()[0] << q3.front()[1] << q3.front()[2] << "|" << q4.front()[0] << q4.front()[1] << q4.front()[2] << "|" << q5.front()[0] << q5.front()[1] << q5.front()[2] <<  endl;
                                                cout << "|" << q1.front()[3] << q1.front()[4] << q1.front()[5] << "|" << q2.front()[3] << q2.front()[4] << q2.front()[5] << "|" << q3.front()[3] << q3.front()[4] << q3.front()[5] << "|" << q4.front()[3] << q4.front()[4] << q4.front()[5] << "|" << q5.front()[3] << q5.front()[4] << q5.front()[5] <<  endl;
                                                cout << "|" << q1.front()[6] << q1.front()[7] << q1.front()[8] << "|" << q2.front()[6] << q2.front()[7] << q2.front()[8] << "|" << q3.front()[6] << q3.front()[7] << q3.front()[8] << "|" << q4.front()[6] << q4.front()[7] << q4.front()[8] << "|" << q5.front()[6] << q5.front()[7] << q5.front()[8] ;
                                                cout << endl << "Node number x win : " << round << endl;
                                                q5.pop();
                                            }
                                            else{
                                                while(!q6.empty()){
                                                    if(check(q5.front(),q6.front(),5)){
                                                        round++;
                                                        if (checkxwin(q6.front(),'o')){
                                                            cout << "|" << q1.front()[0] << q1.front()[1] << q1.front()[2] << "|" << q2.front()[0] << q2.front()[1] << q2.front()[2] << "|" << q3.front()[0] << q3.front()[1] << q3.front()[2] << "|" << q4.front()[0] << q4.front()[1] << q4.front()[2] << "|" << q5.front()[0] << q5.front()[1] << q5.front()[2] << "|" << q6.front()[0] << q6.front()[1] << q6.front()[2] << endl;
                                                            cout << "|" << q1.front()[3] << q1.front()[4] << q1.front()[5] << "|" << q2.front()[3] << q2.front()[4] << q2.front()[5] << "|" << q3.front()[3] << q3.front()[4] << q3.front()[5] << "|" << q4.front()[3] << q4.front()[4] << q4.front()[5] << "|" << q5.front()[3] << q5.front()[4] << q5.front()[5] << "|" << q6.front()[3] << q6.front()[4] << q6.front()[5] << endl;
                                                            cout << "|" << q1.front()[6] << q1.front()[7] << q1.front()[8] << "|" << q2.front()[6] << q2.front()[7] << q2.front()[8] << "|" << q3.front()[6] << q3.front()[7] << q3.front()[8] << "|" << q4.front()[6] << q4.front()[7] << q4.front()[8] << "|" << q5.front()[6] << q5.front()[7] << q5.front()[8] << "|" << q6.front()[6] << q6.front()[7] << q6.front()[8] ;
                                                            cout << endl << "Node number x lose : " << round << endl;
                                                            q6.pop();
                                                        }
                                                        else{
                                                            while(!q7.empty()){
                                                                if(check(q6.front(),q7.front(),6)){
                                                                    round++;
                                                                    if (checkxwin(q7.front(),'x')){
                                                                        cout << "|" << q1.front()[0] << q1.front()[1] << q1.front()[2] << "|" << q2.front()[0] << q2.front()[1] << q2.front()[2] << "|" << q3.front()[0] << q3.front()[1] << q3.front()[2] << "|" << q4.front()[0] << q4.front()[1] << q4.front()[2] << "|" << q5.front()[0] << q5.front()[1] << q5.front()[2] << "|" << q6.front()[0] << q6.front()[1] << q6.front()[2] << "|" << q7.front()[0] << q7.front()[1] << q7.front()[2] <<  endl;
                                                                        cout << "|" << q1.front()[3] << q1.front()[4] << q1.front()[5] << "|" << q2.front()[3] << q2.front()[4] << q2.front()[5] << "|" << q3.front()[3] << q3.front()[4] << q3.front()[5] << "|" << q4.front()[3] << q4.front()[4] << q4.front()[5] << "|" << q5.front()[3] << q5.front()[4] << q5.front()[5] << "|" << q6.front()[3] << q6.front()[4] << q6.front()[5] << "|" << q7.front()[3] << q7.front()[4] << q7.front()[5] <<  endl;
                                                                        cout << "|" << q1.front()[6] << q1.front()[7] << q1.front()[8] << "|" << q2.front()[6] << q2.front()[7] << q2.front()[8] << "|" << q3.front()[6] << q3.front()[7] << q3.front()[8] << "|" << q4.front()[6] << q4.front()[7] << q4.front()[8] << "|" << q5.front()[6] << q5.front()[7] << q5.front()[8] << "|" << q6.front()[6] << q6.front()[7] << q6.front()[8] << "|" << q7.front()[6] << q7.front()[7] << q7.front()[8] ;
                                                                        cout << endl << "Node number x win : " << round << endl;
                                                                        q7.pop();
                                                                    }
                                                                    else{
                                                                        while(!q8.empty()){
                                                                            if(check(q7.front(),q8.front(),7)){
                                                                                round++;
                                                                                if (checkxwin(q8.front(),'o')){
                                                                                    cout << "|" << q1.front()[0] << q1.front()[1] << q1.front()[2] << "|" << q2.front()[0] << q2.front()[1] << q2.front()[2] << "|" << q3.front()[0] << q3.front()[1] << q3.front()[2] << "|" << q4.front()[0] << q4.front()[1] << q4.front()[2] << "|" << q5.front()[0] << q5.front()[1] << q5.front()[2] << "|" << q6.front()[0] << q6.front()[1] << q6.front()[2] << "|" << q7.front()[0] << q7.front()[1] << q7.front()[2] << "|" << q8.front()[0] << q8.front()[1] << q8.front()[2] << endl;
                                                                                    cout << "|" << q1.front()[3] << q1.front()[4] << q1.front()[5] << "|" << q2.front()[3] << q2.front()[4] << q2.front()[5] << "|" << q3.front()[3] << q3.front()[4] << q3.front()[5] << "|" << q4.front()[3] << q4.front()[4] << q4.front()[5] << "|" << q5.front()[3] << q5.front()[4] << q5.front()[5] << "|" << q6.front()[3] << q6.front()[4] << q6.front()[5] << "|" << q7.front()[3] << q7.front()[4] << q7.front()[5] << "|" << q8.front()[3] << q8.front()[4] << q8.front()[5] << endl;
                                                                                    cout << "|" << q1.front()[6] << q1.front()[7] << q1.front()[8] << "|" << q2.front()[6] << q2.front()[7] << q2.front()[8] << "|" << q3.front()[6] << q3.front()[7] << q3.front()[8] << "|" << q4.front()[6] << q4.front()[7] << q4.front()[8] << "|" << q5.front()[6] << q5.front()[7] << q5.front()[8] << "|" << q6.front()[6] << q6.front()[7] << q6.front()[8] << "|" << q7.front()[6] << q7.front()[7] << q7.front()[8] << "|" << q8.front()[6] << q8.front()[7] << q8.front()[8] ;
                                                                                    cout << endl << "Node number x lose : " << round << endl;
                                                                                    q8.pop();
                                                                                }
                                                                                else{
                                                                                    while(!q9.empty()){
                                                                                        if(check(q8.front(),q9.front(),8)){
                                                                                            round++;
                                                                                            cout << "|" << q1.front()[0] << q1.front()[1] << q1.front()[2] << "|" << q2.front()[0] << q2.front()[1] << q2.front()[2] << "|" << q3.front()[0] << q3.front()[1] << q3.front()[2] << "|" << q4.front()[0] << q4.front()[1] << q4.front()[2] << "|" << q5.front()[0] << q5.front()[1] << q5.front()[2] << "|" << q6.front()[0] << q6.front()[1] << q6.front()[2] << "|" << q7.front()[0] << q7.front()[1] << q7.front()[2] << "|" << q8.front()[0] << q8.front()[1] << q8.front()[2] << "|" << q9.front()[0] << q9.front()[1] << q9.front()[2] <<  endl;
                                                                                            cout << "|" << q1.front()[3] << q1.front()[4] << q1.front()[5] << "|" << q2.front()[3] << q2.front()[4] << q2.front()[5] << "|" << q3.front()[3] << q3.front()[4] << q3.front()[5] << "|" << q4.front()[3] << q4.front()[4] << q4.front()[5] << "|" << q5.front()[3] << q5.front()[4] << q5.front()[5] << "|" << q6.front()[3] << q6.front()[4] << q6.front()[5] << "|" << q7.front()[3] << q7.front()[4] << q7.front()[5] << "|" << q8.front()[3] << q8.front()[4] << q8.front()[5] << "|" << q9.front()[3] << q9.front()[4] << q9.front()[5] <<  endl;
                                                                                            cout << "|" << q1.front()[6] << q1.front()[7] << q1.front()[8] << "|" << q2.front()[6] << q2.front()[7] << q2.front()[8] << "|" << q3.front()[6] << q3.front()[7] << q3.front()[8] << "|" << q4.front()[6] << q4.front()[7] << q4.front()[8] << "|" << q5.front()[6] << q5.front()[7] << q5.front()[8] << "|" << q6.front()[6] << q6.front()[7] << q6.front()[8] << "|" << q7.front()[6] << q7.front()[7] << q7.front()[8] << "|" << q8.front()[6] << q8.front()[7] << q8.front()[8] << "|" << q9.front()[6] << q9.front()[7] << q9.front()[8] ;
                                                                                            cout << endl << "Node number " ;
                                                                                            if (checkxwin(q9.front(),'x')){
                                                                                                cout << "x win ";
                                                                                            }
                                                                                            cout << ":" << round << endl;
                                                                                            q9.pop();
                                                                                        }
                                                                                        else{break;}
                                                                                    }
                                                                                    q8.pop();
                                                                                }
                                                                            }
                                                                            else{break;}
                                                                        }
                                                                        q7.pop();
                                                                    }
                                                                }
                                                                else{break;}
                                                            }
                                                            q6.pop();
                                                        }
                                                    }
                                                    else{break;}
                                                }
                                                q5.pop();
                                            }
                                        }
                                        else{break;}
                                    }
                                    q4.pop();
                                }
                                else{break;}
                            }
                            q3.pop();
                        }
                        else{break;}
                    }
                    q2.pop();
                }
                else{break;}
            }
            q1.pop();
        }
    }
    bool check(const string &board1,const string &board2,int sub){
        int sumcheck=0;
        for (i=0;i<9;i++){
            if(board1[i]==board2[i] && board1[i]!='_'){
                sumcheck++;
            }
        }
        if (sumcheck==sub){
            return true;
        }
        else{
            return false;
        }
    }
    bool checkxwin(const string &board,char play){
        char p = play;
        if ((board[0]==p&&board[1]==p&&board[2]==p) ||
            (board[3]==p&&board[4]==p&&board[5]==p) ||
            (board[6]==p&&board[7]==p&&board[8]==p) ||
            (board[0]==p&&board[3]==p&&board[6]==p) ||
            (board[1]==p&&board[4]==p&&board[7]==p) ||
            (board[2]==p&&board[5]==p&&board[8]==p) ||
            (board[0]==p&&board[4]==p&&board[8]==p) ||
            (board[2]==p&&board[4]==p&&board[6]==p) ){
            return true;
        }
        return false;
    }
};

int main(){
    Queue ox;
    Tree tree(550000);
    tree.boardsx(ox);
    cout << endl << node ; 
    return 0;
}