#include <iostream>
using namespace std;

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int v){
		val = v;
		left = right = nullptr;
	}
};

class BinarySearchTree{
	Node* root;
	public:
		BinarySearchTree(){
			root = nullptr;
		}
		
		Node* insertion(Node* n, int val){
			if(n == nullptr){	
		        return new Node(val);
		    }
		    else if(val < n->val){
		    	n->left = insertion(n->left, val);
			}
			else if(val > n->val){
				n->right = insertion(n->right, val);
			}
			return n;
		}
		
		Node* deleteNode(Node* n, int val){
			if(n == nullptr) return n;
			else if(val < n->val){
				n->left = deleteNode(n->left, val);
			}
			else if(val > n->val){
				n->right = deleteNode(n->right, val);
			}
			else{
				if(n->left == nullptr && n->right == nullptr){
					delete n;
					return nullptr;
				}
				else if(n->left == nullptr){
					Node* temp = n->right;
					delete n;
					return temp;
				}
				else if(n->right == nullptr){
					Node* temp = n->left;
					delete n;
					return temp;
				}
				else{
					Node* temp = findMin(n->right);
					n->val = temp->val;
					n->right = deleteNode(n->right, temp->val);
				}
			}
		}
		
		Node* findMin(Node* n){
			while(n->left != nullptr) n = n->left;
			return n;
		}
		
		Node* search(Node* n, int val){
			if(n == nullptr  || n->val == val) return n;
			if(val < n->val){
				return search(n->left, val);
			}
			return search(n->right, val);
	    }
	    
	    void preOrder(Node* n){
	    	if(n == nullptr) return;
	    	cout<<n->val<<" ";
	    	preOrder(n->left);
	    	preOrder(n->right);
	    }
	    
	    void inOrder(Node* n){
	    	if(n == nullptr) return;
	    	inOrder(n->left);
	    	cout<<n->val<<" ";
	    	inOrder(n->right);
	    }
	    
	    void postOrder(Node* n){
	    	if(n == nullptr) return;
	    	postOrder(n->left);
	    	postOrder(n->right);
	    	cout<<n->val<<" ";
	    }
	    
	    Node* getRoot(){
	    	return root;
		}
};

int main(){
	BinarySearchTree b;
	Node* root = b.getRoot();
	root = b.insertion(root, 6);
	root = b.insertion(root, 7);
	root = b.insertion(root, 4);
	root = b.insertion(root, 5);
	root = b.insertion(root, 3);
	
	b.inOrder(root);
	cout<<endl;
	b.postOrder(root);
	cout<<endl;
	b.preOrder(root);
	
	
}