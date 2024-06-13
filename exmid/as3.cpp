#include <iostream>
#include <cmath>

using namespace std;
struct area {
    char AreaID[50];
    int Latitude;
    int Longitude;
    int HasGold;
};

class Board {
public:
    int i;
    float a[15];
    area areas[15]; // ประกาศอาร์เรย์ areas ของ Area

    Board(){
        areas[0]= {"1", 54, 97, 1};
        areas[1]= {"2", 99, 91, 0};
        areas[2]= {"3", 61, 53, 1};
        areas[3]= {"4", 43, 95, 0};
        areas[4]= {"5", 60, 10, 1};
        areas[5]= {"6", 40, 74, 0};
        areas[6]= {"7", 16, 92, 1};
        areas[7]= {"8", 8, 8, 0};
        areas[8]= {"9", 90, 37, 1};
        areas[9]= {"10", 13, 32, 0};
        areas[10]= {"11", 85, 75, 1};
        areas[11]= {"12", 98, 23, 0};
        areas[12]= {"13", 94, 74, 1};
        areas[13]= {"14", 54, 38, 0};
        areas[14]= {"15", 36, 42, 1};
    }
    
    void knn(int la, int lo){
        for (i=0;i<15;i++){
            a[i] = pow(pow((areas[i].Latitude - la),2) + pow((areas[i].Longitude - lo),2),0.5);
        }

    }
    void markset(int &k){
        int min = 100;
        for(i=0;i<15;i++){
            if (a[i]<min){
                min = a[i];
                k=i;
            }
        }
        a[k]=101;
    }
    void mark3(){
        int poin[3];
        int check=0;
        markset(poin[0]);
        markset(poin[1]);
        markset(poin[2]);
        int arr[3] = {poin[0],poin[1],poin[2]};
        for (i=0;i<3;i++){
            if (areas[arr[i]].HasGold==1){
                check++;
            }
        }
        cout << "HasGold : ";
        if (check>=2){
            cout << "Yes";
        }
        else {
            cout << "NO";
        }
    }
};

int main() {
    Board board;
    int la, lo;
    cout << "Latitude = ";
    cin >> la;
    cout << "Longitude = ";
    cin >> lo;
    board.knn(la, lo); // เรียกใช้ฟังก์ชัน knn ผ่านอ็อบเจกต์ board
    board.mark3();
}
