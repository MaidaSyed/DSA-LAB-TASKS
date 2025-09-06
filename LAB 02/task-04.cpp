#include <iostream>
using namespace std;

class Friends{
    bool matrix[5][5];
    public:
        Friends(){
            bool temp[5][5] = {
            {0, 1, 0, 1, 1},  // 0 is friends with 1,3,4
            {1, 0, 1, 0, 1},  // 1 is friends with 0,2,4
            {0, 1, 0, 0, 0},  // 2 is friends with 1
            {1, 0, 0, 0, 1},  // 3 is friends with 0,4
            {1, 1, 0, 1, 0}   // 4 is friends with 0,1,3
            };

            for(int i=0; i<5; i++){
                for(int j=0; j<5; j++){
                    matrix[i][j] = temp[i][j];
                }
            }
        }

        bool hasCommonFrnd(int f1, int f2){
            for(int i=0; i<5; i++){
                if(i != f1 && i != f2){
                    if(matrix[f1][i] && matrix[f2][i]) {
                        return true;
                    }
                }
            }
            return false;
        }

        void displayMatrix() {
            cout << "Friendship Matrix (1 = friends, 0 = not friends):\n";
            for(int i=0;i<5;i++) {
                for(int j=0;j<5;j++) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    Friends f;
    f.displayMatrix();
    cout<<endl;

    cout<<"0, 4 has common friend: "<<(f.hasCommonFrnd(0,4) ? "Yes" : "No")<<endl;
    cout<<"1, 2 has common friend: "<<(f.hasCommonFrnd(1,2) ? "Yes" : "No")<<endl;
}