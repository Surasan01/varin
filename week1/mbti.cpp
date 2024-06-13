#include <iostream>
#include <string>
#include <cmath>

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
        string mytype="";
        Data data[50];
        float a[50];
        mbti(){
            data[0] = {1, "Aj.Yong", 32, 32, 27, 36, 29, 31, 28, 23, "INTP"};
            data[1] = {2, "Fluk", 31.8, 33, 22, 30, 35, 26, 24, 23, "INTJ"};
            data[2] = {3, "Euro", 12.8, 15.6, 14, 29, 21, 20, 17, 17, "ISTJ"};
            data[3] = {4, "Nun", 9.8, 14, 23, 23, 27, 30, 13, 25, "ISTP"};
            data[4] = {5, "Ploydao", 27.4, 30.4, 25, 25, 33, 28, 29, 19, "ENFJ"};
            data[5] = {6, "Phum", 41.4, 31.8, 38, 42, 25, 36, 21, 39, "INTP"};
            data[6] = {7, "Pui", 29.4, 36.4, 30, 34, 26, 28, 35, 29, "INFJ"};
            data[7] = {8, "Net", 25.4, 20.4, 33, 30, 24, 32, 24, 17, "INFJ"};
            data[8] = {9, "Num", 21.4, 20.4, 30, 31, 34, 30, 17, 22, "ISTP"};
            data[9] = {10, "Dear", 41, 30.4, 29, 45, 24, 42, 33, 31, "INTP"};
            data[10] = {11, "Mymint", 37, 37.4, 37, 30, 28, 40, 35, 29, "ISTJ"};
            data[11] = {12, "Nut", 23.4, 27, 26, 25, 27, 30, 23, 20, "ISTP"};
            data[12] = {13, "Mai", 35.8, 35.6, 18, 23, 17, 32, 26, 22, "INFJ"};
            data[13] = {14, "Fern", 28.6, 21, 23, 24, 22, 26, 26, 13, "ENTP"};
            data[14] = {15, "Jai", 29.4, 39.4, 34, 42, 32, 31, 29, 29, "INTJ"};
            data[15] = {16, "Guy", 39.2, 34.6, 30, 23, 25, 28, 36, 23, "ENFJ"};
            data[16] = {17, "Safe", 30, 18.4, 19, 31, 25, 31, 25, 15, "INTP"};
            data[17] = {18, "Kong", 22.8, 27, 31, 33, 29, 35, 26, 22, "ISTJ"};
            data[18] = {19, "Palm", 21.8, 26, 21, 34, 26, 25, 23, 22, "ISTP"};
            data[19] = {20, "Mute", 30.4, 38, 20, 30, 18, 29, 24, 14, "INFJ"};
            data[20] = {21, "Ant", 29.4, 28.6, 30, 31, 31, 34, 27, 25, "ISTJ"};
            data[21] = {22, "Namsai", 18.4, 26.6, 33, 38, 23, 41, 20, 24, "ISTJ"};
            data[22] = {23, "Puay", 21, 29.4, 23, 36, 26, 32, 16, 27, "ISTP"};
            data[23] = {24, "khawfang", 25.4, 26, 18, 28, 25, 23, 19, 23, "ISTP"};
            data[24] = {25, "Amy", 20, 14.8, 31, 37, 33, 17, 24, 27, "ESTP"};
            data[25] = {26, "Gift", 24.2, 25.6, 21, 26, 23, 28, 15, 21, "ISTP"};
            data[26] = {27, "Opal", 31.6, 29.4, 32, 21, 28, 33, 30, 21, "ENFJ"};
            data[27] = {28, "Ohm", 24.6, 32.2, 31, 39, 31, 35, 21, 29, "ISTP"};
            data[28] = {29, "Tee", 32.2, 38.8, 32, 36, 29, 35, 33, 30, "INTJ"};
            data[29] = {30, "Bigboss", 32, 32, 27, 36, 29, 31, 28, 23, "INFP"};
            data[30] = {31, "Tae", 22, 36.8, 25, 28, 24, 35, 20, 32, "ISTP"};
            data[31] = {32, "Tra", 38, 37, 36, 38, 37, 36, 39, 36, "ENTP"};
            data[32] = {33, "Frank", 36.4, 33.4, 35, 35, 36, 36, 37, 25, "ESFJ"};
            data[33] = {34, "Mind", 19.8, 25, 31, 35, 31, 30, 23, 21, "ISTJ"};
        }
    void ed(string name_new, float ne_new ,float ni_new ,float te_new,float ti_new ,float se_new ,float si_new ,float fe_new ,float fi_new){
        int i ; 
        float p1,p2,p3,p4,p5,p6,p7,p8,dpq;
        for (i=0;i<15;i++){
            p1 = (data[i].ne - ne_new);
            p1 = p1*p1;
            p2 = (data[i].ni - ni_new);
            p2 = p2*p2;
            p3 = (data[i].te - te_new);
            p3 = p3*p3;
            p4 = (data[i].ti - ti_new);
            p4 = p4*p4;
            p5 = (data[i].se - se_new);
            p5 = p5*p5;
            p6 = (data[i].si - si_new);
            p6 = p6*p6;
            p7 = (data[i].fe - fe_new);
            p7 = p7*p7;
            p8 = (data[i].fi - fi_new);
            p8 = p8*p8;
            dpq = p1+p2+p3+p4+p5+p6+p7+p8;
            a[i] = pow(dpq,0.5);
        }
    }

    void mark_set(int &k){
        int j;
        float min=99;
        for (j=0;j<15;j++){
            if (a[j] < min){
                min = a[j];
                k=j;
            }
        }
        // cout << k << endl;
        a[k] = 100;
    }

    void mark3(){
        int point[3];
        mark_set(point[0]);
        mark_set(point[1]);
        mark_set(point[2]);

        column3(data[point[0]].type[0],data[point[1]].type[0],data[point[2]].type[0]);
        column3(data[point[0]].type[1],data[point[1]].type[1],data[point[2]].type[1]);
        column3(data[point[0]].type[2],data[point[1]].type[2],data[point[2]].type[2]);
        column3(data[point[0]].type[3],data[point[1]].type[3],data[point[2]].type[3]);
    }

    void mark5(){
        int point[5];
        mark_set(point[0]);
        mark_set(point[1]);
        mark_set(point[2]);
        mark_set(point[3]);
        mark_set(point[4]);

        column5(data[point[0]].type[0],data[point[1]].type[0],data[point[2]].type[0],data[point[3]].type[0],data[point[4]].type[0]);
        column5(data[point[0]].type[1],data[point[1]].type[1],data[point[2]].type[1],data[point[3]].type[1],data[point[4]].type[1]);
        column5(data[point[0]].type[2],data[point[1]].type[2],data[point[2]].type[2],data[point[3]].type[2],data[point[4]].type[2]);
        column5(data[point[0]].type[3],data[point[1]].type[3],data[point[2]].type[3],data[point[3]].type[3],data[point[4]].type[3]);
    }

    void column3(char r1,char r2,char r3){
        int i,a1=0,a2=0;
        char r[3] = {r1,r2,r3};
        
        for (i=1;i<3;i++){
            if (r[0]==r[i]){
                a1++;
                r[i]='#';
            }
        }
        for (i=2;i<3 && r[1] != '#';i++){
            if (r[1]==r[i]){
                a2++;
            }
        }
        if (a1>a2){
            mytype += r1;
        }
        else {
            mytype += r2;
        }
    }

    void column5(char r1,char r2,char r3,char r4,char r5){
        int i,a1=0,a2=0,a3=0,a4=0;
        char r[5] = {r1,r2,r3,r4,r5};
        for (i=1;i<5;i++){
            if (r[0]==r[i]){
                a1++;
                r[i]='#';
            }
        }
        for (i=2;i<5 && r[1] != '#';i++){
            if (r[1]==r[i]){
                a2++;
                r[i]='#';
            }
        }
        for (i=3;i<5 && r[2] != '#';i++){
            if (r[2]==r[i]){
                a3++; 
                r[i]='#';
            }
        }
        for (i=4;i<5 && r[3] != '#';i++){
            if (r[3]==r[i]){
                a4++;
            }
        }
        int alist[4] = {a1,a2,a3,a4},max=0,t;
        for (i=0;i<4;i++){
            if (alist[i]>max){
                max=alist[i];
                t=i;
            }
        }
        mytype += r[t];
    }
};

int main() {
    mbti mbti;
    string name_new,type_new ;
    float ne_new,ni_new,te_new,ti_new,se_new,si_new,fe_new,fi_new;
    int mark;
    cout << "Name : ";
    cin >> name_new;
    cout << "Ne : ";
    cin >> ne_new;
    cout << "Ni : ";
    cin >> ni_new;
    cout << "Te : ";
    cin >> te_new;
    cout << "Ti : ";
    cin >> ti_new;
    cout << "Se : ";
    cin >> se_new;
    cout << "Si : ";
    cin >> si_new;
    cout << "Fe : ";
    cin >> fe_new;
    cout << "Fi : ";
    cin >> fi_new;

    mbti.ed(name_new,ne_new,ni_new,te_new,ti_new,se_new,si_new,fe_new,fi_new);
    // mbti.ed("Puiza",32,32,27,36,29,31,28,23);

    cout << "Mark size (3 or 5): ";
    cin >> mark ;
    while (mark != 3 && mark != 5) {
        cout << "Mark size (3 or 5): ";
        cin >> mark;
    }
    if (mark == 3){
        mbti.mark3();
    }
    else if (mark == 5){
        mbti.mark5();
    }
    cout << name_new << " Type : " << mbti.mytype ;
    return 0;
}

// O(n) นะจาร