#include <iostream>
using namespace std;

class Box {
	int* size;
    public:
        Box(int s) {
            size = new int(s);
        }

        Box(const Box& other) {
            size = new int(*other.size);
        }
		
		Box operator = (const Box& b){
			if(this == &b){
				return *this;
			}
			delete size;
			this->size = b.size;
			return *this;
		}
		
		int getSize(){
			return *size;
		}
		
		void setSize(int s){
			*size = s;
		}
		 
        ~Box() {
            delete size;
        }
};

int main(){
	Box box1(10);
    Box box2 = box1; // deep copy
    
    cout<<"Box-1 size: "<<box1.getSize()<<endl;
    cout<<"Box-2 size from deep copy of box-1: "<<box2.getSize()<<endl;
    
    box1.setSize(20);
    cout<<"after updating box-1 size:"<<endl;
    cout<<"Box-1 size: "<<box1.getSize()<<endl;
    cout<<"Box-2 size: "<<box2.getSize()<<endl;
}