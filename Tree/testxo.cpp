#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Tree{
    public : 
        int i,j;
        int size;
        int itree=0,xwin=0;
        string *table,*qu1,*qu2,*qu3,*qu4,*qu5,*qu6,*qu7,*qu8,*qu9;
        

        Tree(int maxsize){        
            size = maxsize ;
            table = new string[size];
            qu1 = new string[1000];
            qu2 = new string[10000];
            qu3 = new string[100000];
            qu4 = new string[100000];
            qu5 = new string[500000];
            qu6 = new string[1000000];
            qu7 = new string[2000000];
            qu8 = new string[2000000];
            qu9 = new string[2000000];
            for (i=0;i<size;i++){
                table[i] = "---------";
            }
        }
    void boardsx(queue<string> &xo){
        char play;
        int round=1;
        string newboard;
        xo.push("---------");
        int set,q1=0,q2=0,q3=0,q4=0,q5=0,q6=0,q7=0,q8=0,q9=0;
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
            // display(markboard);
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
        for (i=0;i<itree;i++){
            string markboard = table[i];
            int ix=0,io=0;
            for (j=0;j<9;j++){
                if(markboard[j]=='X'){ix++;}
                else if (markboard[j]=='O'){io++;}
            }
            set = ix+io;
            if (set==1){
                qu1[q1] = markboard;
                q1++;
            }
            else if (set==2){
                qu2[q2] = markboard;
                q2++;
            }
            else if (set==3){
                qu3[q3] = markboard;
                q3++;
            }
            else if (set==4){
                qu4[q4] = markboard;
                q4++;
            }
            else if (set==5){
                qu5[q5] = markboard;
                q5++;
            }
            else if (set==6){
                qu6[q6] = markboard;
                q6++;
            }
            else if (set==7){
                qu7[q7] = markboard;
                q7++;
            }
            else if (set==8){
                qu8[q8] = markboard;
                q8++;
            }
            else if(set==9){
                qu9[q9] = markboard;
                q9++;
            }
        }
        int i1,i2,i3,i4,i5,i6,i7,i8,i9;
        for (i1=0;i1<q1;i1++){
            for (i2=0;i2<q2;i2++){
                for(i3=0;i3<q3;i3++){
                    for(i4=0;i4<q4;i4++){
                        for(i5=0;i5<q5;i5++){
                            for(i6=0;i6<q6;i6++){
                                for(i7=0;i7<q7;i7++){
                                    for(i8=0;i8<q8;i8++){
                                        for(i9=0;i9<q9;i9++){
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
// string mark1 = qu1[i1],mark2 = qu2[i2],mark3 = qu3[i3],mark4 = qu4[i4],mark5 = qu5[i5],mark6 = qu6[i6],mark7 = qu7[i7],mark8 = qu8[i8],mark9 = qu9[i9];
// cout << "|"<< mark1[0] << mark1[1] << mark1[2] << "| |" << mark2[0] << mark2[1] << mark2[2] << "| |" << mark3[0] << mark3[1] << mark3[2] << "| |" << mark4[0] << mark4[1] << mark4[2] << "| |" << mark5[0] << mark5[1] << mark5[2] << "| |" << mark6[0] << mark6[1] << mark6[2] << "| |" << mark7[0] << mark7[1] << mark7[2] << "| |" << mark8[0] << mark8[1] << mark8[2] << "| |" << mark9[0] << mark9[1] << mark9[2] << "|"<<endl;
// cout << "|"<< mark1[3] << mark1[4] << mark1[5] << "| |" << mark2[3] << mark2[4] << mark2[5] << "| |" << mark3[3] << mark3[4] << mark3[5] << "| |" << mark4[3] << mark4[4] << mark4[5] << "| |" << mark5[3] << mark5[4] << mark5[5] << "| |" << mark6[3] << mark6[4] << mark6[5] << "| |" << mark7[3] << mark7[4] << mark7[5] << "| |" << mark8[3] << mark8[4] << mark8[5] << "| |" << mark9[3] << mark9[4] << mark9[5] << "|"<<endl;
// cout << "|"<< mark1[6] << mark1[7] << mark1[8] << "| |" << mark2[6] << mark2[7] << mark2[8] << "| |" << mark3[6] << mark3[7] << mark3[8] << "| |" << mark4[6] << mark4[7] << mark4[8] << "| |" << mark5[6] << mark5[7] << mark5[8] << "| |" << mark6[6] << mark6[7] << mark6[8] << "| |" << mark7[6] << mark7[7] << mark7[8] << "| |" << mark8[6] << mark8[7] << mark8[8] << "| |" << mark9[6] << mark9[7] << mark9[8] << "|"<<endl;
            // string mark1 = qu1[i];
            // cout << "|"<< mark1[0] << mark1[1] << mark1[2] << "| |";
    }
        
    bool isfull(const string &mark){
        for (i=0;i<9;i++){
            if(mark[i]=='-'){
                return false;
            }
        }
        return true;
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
    Tree tree(550000);
    tree.boardsx(ox);
    return 0;
}