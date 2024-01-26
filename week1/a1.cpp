#include <iostream>
#include <random>
using namespace std;

int main(){
    random_device rd;
    mt19937 rng(rd());
    
    int i,j,map[10][10];
    uniform_int_distribution<int> uni(0, 9);
    int treex = uni(rng);
    int treey = uni(rng);
    
    int herox = 4,heroy = 5;
    int monsterx = 10-4,monstery=4;
    for (i=9;i>=0;i--){
        for(j=0;j<10;j++){
            if (i==treey && j==treex){
                map[i][j]=1;
            }
            else if (i==heroy && j==herox){
                map[i][j]=2;
            }
            else if (i==monstery && j==monsterx){
                map[i][j]=3;
            }
            else{
                map[i][j]=0;
            }
        }
    }
    for (i=9;i>=0;i--){
        for(j=0;j<10;j++){
            cout << map[i][j];
        }
        cout << endl;
    }
    cout <<  endl;
    float taxicab = abs(6-4) + abs(4-5);
    float euclidean = sqrt(pow(6-4,2) + pow(4-5,2));
    int c;
    if (abs(6-4)>abs(4-5)){c = abs(6-4);}
    else{c = abs(4-5);}
    int chebyshev = c;
    cout << "Taxicab  = " << taxicab << endl;
    cout << "Euclidean = " << euclidean << endl;
    cout << "Chebyshev =  " << chebyshev << endl;

    return 0 ;
}