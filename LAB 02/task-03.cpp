#include <iostream>
using namespace std;

class Student{
    int subject[5];
    int totalMarks;
    public:
        Student(){
            for(int i=0; i<5; i++) subject[i] = 0;
            totalMarks = 0;
        }

        void inputMarks(){
            totalMarks = 0; 
            for(int i=0; i<5; i++){
                cout<<"for subject "<<i+1<<": ";
                cin>>subject[i];
                totalMarks += subject[i];
            }
        }

        void display(){
            for(int i=0; i<5; i++){
                cout<<subject[i]<<" ";
            }
            cout<<"Total: "<<totalMarks<<endl;
        }

        int getMarks() const{
            return totalMarks;
        }
    
};

void calcAndDisplay(Student *depStd, int stdCount, int deptNo){
    int highest = INT_MIN;
    int lowest = INT_MAX;
    int total = 0;

    cout<<endl<<"Department "<<deptNo+1<<endl;
    for(int i=0; i<stdCount; i++){
        cout<<"Student "<<i+1<<": ";
        depStd[i].display();

        int marks = depStd[i].getMarks();
        total += marks;
        highest = max(highest, marks);
        lowest = min(lowest, marks);
    }

    cout<<"Highest: "<<highest<<endl;
    cout<<"Lowest: "<<lowest<<endl;
    cout<<"Average: "<<(double)total / stdCount<<endl;
}

int main(){
    int dep;
    cout<<"Enter no of dep: ";
    cin>>dep;

    int *stdCount  = new int[dep];
    Student **StudentMarks = new Student*[dep];

    for (int i = 0; i < dep; i++) {
        cout << "Enter number of students in department " << i + 1 << ": ";
        cin >> stdCount[i];
        StudentMarks[i] = new Student[stdCount[i]];

        for (int j = 0; j < stdCount[i]; j++) {
            cout << "Enter marks of student " << j + 1 << " in dept " << i + 1 << endl;
            StudentMarks[i][j].inputMarks();
        }
    }

    // Display results for each department using function
    for (int i = 0; i < dep; i++) {
        calcAndDisplay(StudentMarks[i], stdCount[i], i);
    }

    // cleanup
    for (int i = 0; i < dep; i++) delete[] StudentMarks[i];
    delete[] StudentMarks;
    delete[] stdCount;
}