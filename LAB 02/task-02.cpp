#include <iostream>
using namespace std;

class Exam{
    int students;
    int subjects;
    int **marks;
    public:
        Exam(int s, int sub) : students(s), subjects(sub) {
            marks = new int*[students];
            for (int i = 0; i < students; i++) {
                marks[i] = new int[subjects];
            }
        }

        void inputMarks(){
            for(int i=0; i<students; i++){
                cout<<"Marks for Student"<<i+1<<endl;
                for(int j=0; j<subjects; j++){
                    cout<<"subject "<<j+1<<": ";
                    cin>>marks[i][j];
                }
            }
        }

        void displayTotal(){
            cout<<"Total marks for all students:"<<endl;
            for(int i=0; i<students; i++){
                int total = 0;
                for(int j=0; j<subjects; j++){
                    total += marks[i][j];
                }
                cout<<"Marks for Student"<<i+1<<": "<<total<<endl;
            }
        }


        void displayAvg(){
            cout << "Average Marks of Each Subject:"<<endl;
            for (int j = 0; j < subjects; j++) {
                double sum = 0;
                for (int i = 0; i < students; i++) {
                    sum += marks[i][j];
                }
            cout<<"Subject "<<j + 1<<": "<<sum / students<<endl;
            }
        }

        void topStd(){
            int topperIdx = 0;
            int topperMarks = 0;
            for(int i=0; i<students; i++){
                int total = 0;
                for(int j=0; j<subjects; j++){
                    total += marks[i][j];
                }
                if (total > topperMarks) {
                    topperMarks = total;
                    topperIdx = i;
                }
            }
            cout<<"Topper is Student "<<topperIdx+1<<" with "<<topperMarks<<" marks"<<endl;
        }

        ~Exam() {
            for (int i = 0; i < students; i++) {
                delete[] marks[i];
            }
            delete[] marks;
        }

};

int main(){
    Exam exam(5, 4);   // 5 students, 4 subjects
    exam.inputMarks();
    exam.displayTotal();
    exam.displayAvg();
    exam.topStd();
}