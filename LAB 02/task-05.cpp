#include <iostream>
#include <iomanip>
using namespace std;

class ManageGPA{
    int departments;
    int *course;
    double **gpa;
    public:
        ManageGPA() : departments(4){
            course = new int[departments]{3, 4, 2, 1};

            gpa = new double*[departments];
            for(int i=0; i<departments; i++){
                gpa[i] = new double[course[i]];
            }
        }

        void inputDetails(){
            string deptNames[4] = {"Software Engineering (SE)", 
                                  "Artificial Intelligence (AI)", 
                                  "Computer Science (CS)", 
                                  "Data Science (DS)"};
            
            for(int i=0; i< departments; i++){
                cout<<"Enter GPA for department "<<deptNames[i]<<": "<<endl;
                for(int j=0; j<course[i]; j++){
                    cout<<"Core course "<<j+1<<": ";
                    cin>>gpa[i][j];
                }
            }
        }

        void displayDetails(){
            cout<<endl;
            string deptNames[4] = {"Software Engineering (SE)", 
                                  "Artificial Intelligence (AI)", 
                                  "Computer Science (CS)", 
                                  "Data Science (DS)"};
            
            cout<<fixed<<setprecision(2);
            for(int i=0; i< departments; i++){
                cout<<"GPA for department "<<deptNames[i]<<": "<<endl;
                for(int j=0; j<course[i]; j++){
                    cout<<"Core course "<<j+1<<": "<<gpa[i][j]<<endl;;
                }
            }
        }

        ~ManageGPA(){
            for(int i=0; i<departments; i++){
                delete[] gpa[i];
            }

            delete[] gpa;
            delete[] course;
        }
};

int main(){
    ManageGPA gpa;
    gpa.inputDetails();
    gpa.displayDetails();
}