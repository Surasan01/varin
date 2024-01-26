#include <iostream>
#include <random>
using namespace std;

int main(){
    random_device rd;
    mt19937 rng(rd());
    
    int i,j;
    uniform_int_distribution<int> uni(0, 9);
    int treex = uni(rng);
    int treey = uni(rng);
    
    cout << treex << " " << treey;
    
}