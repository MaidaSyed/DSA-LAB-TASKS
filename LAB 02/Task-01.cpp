#include <iostream>
using namespace std;

class Matrix{
    int rows;
    int cols;
    int **arr;
    public:
        Matrix(int r, int c) : rows(r), cols(c){
            arr = new int*[rows];
            for(int i=0; i<rows; i++){
                arr[i] = new int[cols];
            }
        }

        void define(){
            cout<<"define Matrix: "<<endl;
            for(int i=0; i<rows; i++){
                cout<<"For row "<<i+1<<": "<<endl;
                for(int j=0; j<cols; j++){
                    cout<<"matrix["<<i+1<<"]["<<j+1<<"]: ";
                    cin>>arr[i][j];
                }
            }
        }

        void resize(){
            int newR;
            int newC;
            cout<<"Enter new size of matrix: ";
            cin>>newR>>newC;

            int **newArr = new int*[newR];
            for(int i=0; i<newR; i++){
                newArr[i] = new int[newC];
            }

            for(int i=0; i<min(rows,newR); i++){
                for(int j=0; j<min(cols, newC); j++){
                    newArr[i][j] = arr[i][j];
                }
            }

            // for if new values are there
            cout<<"New values for resize Matrix: "<<endl;
            for(int i=0; i<newR; i++){
                for(int j=0; j<newC; j++){
                    if(i >= rows || j >= cols){
                        cout<<"matrix["<<i+1<<"]["<<j+1<<"]: ";
                        cin>>newArr[i][j];
                    }
                }
            }

            for (int i = 0; i < rows; i++) {
                delete[] arr[i];
            }
            delete[] arr;

            arr = newArr;
            rows = newR;
            cols = newC;
        }

        Matrix transpose(){
            Matrix result(cols, rows);
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    result.arr[j][i] = arr[i][j];
                }
            }
            return result;
        }

        void display(){
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        void displayAfterAddingTwo(){
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++){
                    if(j%2 != 0){
                        cout<<arr[i][j]+2<<" ";
                    }
                    else{
                        cout<<arr[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
        }

        ~Matrix(){
            for(int i=0; i<rows; i++){
                delete[] arr[i];
            }
            delete[] arr;
        }
};

#include <iostream>
using namespace std;

int main() {
    //Create matrix
    int r, c;
    cout << "Enter rows and cols of matrix: ";
    cin >> r >> c;

    Matrix m(r, c);

    //Define (input values)
    m.define();

    //Display original matrix
    cout << "\nOriginal Matrix:\n";
    m.display();

    //Resize matrix
    cout << "\n--- Resize Matrix ---\n";
    m.resize();
    cout << "\nMatrix after resize:\n";
    m.display();

    //Transpose
    cout << "\n--- Transpose Matrix ---\n";
    Matrix t = m.transpose();   // new transposed matrix
    cout << "\nMatrix after transpose:\n";
    t.display();

    //Display after adding +2 to odd indices
    cout << "\n--- Matrix after adding +2 to odd column indices ---\n";
    m.displayAfterAddingTwo();

    return 0;
}
