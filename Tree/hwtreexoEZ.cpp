#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Tree{
    public : 
        int i,j;
        int size;
        int itree=0,xwin=0;
        string *table;
        Tree(int maxsize){            
            size = maxsize ;
            table = new string[size];
        }
    void boardsx(queue<string> &xo){
        char play;
        int round=0;
        string newboard;
        xo.push("---------");

        while (!xo.empty()){
            string markboard = xo.front();
            xo.pop();
            int ix=0,io=0;
            for(i=0;i<9;i++){
                if(markboard[i]=='X'){ix++;}
                else if (markboard[i]=='O'){io++;}
            }
            cout << "round : " << round << endl;
            round++;
            display(markboard);
            if(checkxwin(markboard,'X')){
                xwin++;
                cout << "============= X Win : " << xwin << endl;
                continue;
            }
            else if(checkxwin(markboard,'O')){
                xwin--;
                cout << "============= X Loss : " << xwin << endl;
                continue;
            }
            if(io<ix){
                play = 'O';
            }
            else{
                play = 'X';
            }
            for (i=0;i<9;i++){
                if(markboard[i]=='-'){
                    newboard = markboard;
                    newboard[i] = play;
                    table[itree] = newboard;
                    itree++;
                    xo.push(newboard);
                }
            }
        }
    }
    bool checkxwin(const string &board,char play){
        for (i=0;i<3;i++){
            if (board[i*3]==play && board[i*3+1]==play && board[i*3+2]==play){
                return true;
            }
        }
        for (i=0;i<3;i++){
            if(board[i]==play && board[i+3]==play && board[i+6]==play){
                return true;
            }
        }
        if ((board[0]==play && board[4]==play && board[8]==play) || (board[2]==play && board[4]==play && board[6]==play)){
            return true;
        }
        return false;
    }
    void display(const string &board){
        cout << "___" << endl;
        for (i=0;i<9;i++){
            cout << board[i];
            if(i%3 == 2){
                cout << endl;
            }
        }
    }
};

int main(){
    queue<string> ox;
    Tree tree(600000);
    tree.boardsx(ox);
    return 0;
}