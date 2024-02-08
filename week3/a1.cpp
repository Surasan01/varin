#include <iostream>

using namespace std;

class board {
    public:
        int size;
        int no=0;
        int aar[14],bar[14],car[14];
        board(int maxsize){
            size = maxsize;
        }
    
        
    
    void insert(int no,int a,int b,int c){
        aar[no-1]=a;
        bar[no-1]=b;
        car[no-1]=c;
    }

    void display(){
        cout << "No.  A  B  C " << endl;
        
        while(no < size){
            cout << no+1 << "  " << aar[no] << "  " << bar[no] << "  " << car[no] << endl;
            no++;
        }
    }
};


int main(){
    board board(14);
    
    board.insert(1,1,1,4);
    board.insert(2,3,1,1);
    board.insert(3,4,4,4);
    board.insert(4,2,4,4);
    board.insert(5,3,5,3);
    board.insert(6,4,3,3);
    board.insert(7,1,3,3);
    board.insert(8,2,4,3);
    board.insert(9,3,3,5);
    board.insert(10,1,5,3);
    board.insert(11,1,1,4);
    board.insert(12,4,1,1);
    board.insert(13,5,2,3);
    board.insert(14,3,5,2);

    board.display();

    return 0;
}