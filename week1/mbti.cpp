#include <iostream>
#include <string>

using namespace std;

class Data {
    public:
        int number;
        string name;
        float ne,ni,te,ti,se,si,fe,fi;
        string type;
};

class mbti{
    public:
        Data data[50];
        mbti(){
            data[0] = {1,"kuuga",35.4,31,33,30,38,31,34,31,"ENTP"};
            data[1] = {2,"Agito",26,31,33,30,26,33,30,24,"INTJ"};
            data[2] = {3,"Ryuki",24.4,30.2,31,34,28,36,22,17,"ENTP"};
            data[3] = {4,"n1",35.4,31,33,30,38,31,34,31,"ENTP"};
            data[4] = {5,"n2",35.4,31,33,30,38,31,34,31,"ENTP"};
            data[5] = {6,"n3",35.4,31,33,30,38,31,34,31,"ENTP"};
            data[6] = {7,"n4",35.4,31,33,30,38,31,34,31,"ENTP"};
            data[7] = {8,"n5",35.4,31,33,30,38,31,34,31,"ENTP"};
            data[8] = {9,"n6",35.4,31,33,30,38,31,34,31,"ENTP"};
            data[9] = {10,"n7",35.4,31,33,30,38,31,34,31,"ENTP"};
            data[10]= {11,"n8",35.4,31,33,30,38,31,34,31,"ENTP"};
            data[11]= {12,"n9",35.4,31,33,30,38,31,34,31,"ENTP"};
        }

};


int main() {

    mbti myMbti;

    cout << "Number: " << myMbti.data[1].number << endl;
    cout << "Name: " << myMbti.data[1].name << endl;
    cout << "Name: " << myMbti.data[1].se << endl;


    return 0;
}