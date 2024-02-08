#include <iostream>

using namespace std;

class board {
    public:
        int size;

        int a,b,c;
        int arr[20][4];
        board(int maxsize){
            size = maxsize;
        }
    
    
    void insert(int no,int a,int b,int c){
        arr[no-1][0]=no;
        arr[no-1][1]=a;
        arr[no-1][2]=b;
        arr[no-1][3]=c;
    }

    void display(){
        cout << "No.  A  B  C " << endl;
        int i;
        for (i=0;i<size;i++){
            cout << arr[i][0] << "  " << arr[i][1] << "  " << arr[i][2] << "  " << arr[i][3] << endl;
        }
    }

    void sorting(char column1,char column2,char column3){
        int no1,no2,no3,i,j;

        if (column1 == 'a'){no1 = 1;}
        else if (column1 == 'b'){no1 = 2;}
        else{no1=3;}
        if (column2 == 'a'){no1 = 1;}
        else if (column2 == 'b'){no1 = 2;}
        else{no1=3;}
        if (column3 == 'a'){no1 = 1;}
        else if (column3 == 'b'){no1 = 2;}
        else{no1=3;}

        int min_key1,min_key2,min_key3;
        for (i=1;i<size;i++){
            min_key1 = arr[i][no1];
            min_key2 = arr[i][no2];
            min_key3 = arr[i][no3];

            for (j=i ;j>0 && arr[j-1][no1]>min_key1;j--){
                arr[j][no1]=arr[j][no1];
                arr[j][no2]=arr[j][no2];
                arr[j][no3]=arr[j][no3];
            }

            arr[j][no1]=min_key1;
            arr[j][no2]=min_key2;
            arr[j][no3]=min_key3;

        }
    }
};

int main(){
    char ch1,ch2,ch3;

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

    cout << "Sorted by" << endl;
    cout << "column 1 : " << endl;
    cin >> ch1 ;
    cout << "column 2 : " << endl;
    cin >> ch2 ;
    cout << "column 3 : " << endl;
    cin >> ch3 ;

    board.sorting(ch1,ch2,ch3);

    board.display();

    return 0;
}