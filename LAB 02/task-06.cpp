#include <iostream>
#include <string>
using namespace std;

class SeatingChart{
    int rows;
    int *seats;
    string **chart;
    public:
        SeatingChart(int r) : rows(r){
            seats = new int[rows];

            for(int i=0; i<rows; i++){
                cout<<"Enter no of seats for row "<<i+1<<": ";
                cin>>seats[i];
            }

            chart = new string*[rows];
            for(int i=0; i<rows; i++){
                chart[i] = new string[seats[i]];
            }
        }

        void inputNames(){
            cin.ignore();
            for(int i=0; i<rows; i++){
                for(int j=0; j<seats[i]; j++){
                    cout<<"Enter name of row "<<i+1<<" seat "<<j+1<<": ";
                    getline(cin, chart[i][j]);
                }
            }
        }

        void display(){
            cout<<endl<<"Seating Chart"<<endl;
            for(int i=0; i<rows; i++){
                cout<<"Row "<<i+1<<": ";
                for(int j=0; j<seats[i]; j++){
                    cout<<chart[i][j]<<", ";
                }
                cout<<endl;
            }
        }

        ~SeatingChart(){
            for(int i=0; i<rows; i++){
                delete[] chart[i];
            }

            delete[] chart;
            delete[] seats;
        }
};

int main(){
    int rows;
    cout<<"Enter total rows for chart: ";
    cin>>rows;

    SeatingChart s(rows);
    s.inputNames();
    s.display();
}