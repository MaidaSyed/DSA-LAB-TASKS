#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int guessNo(int target, int player = 1){
	int guess;
	cout<<"Guess the No (player- "<<player<<"): ";
	cin>>guess;
	if(target == guess) {
		cout<<"correct"<<endl;
		return player;
	}
	else if(guess > target) cout<<"too high"<<endl;
	else cout<<"too low"<<endl;
	
	if(player == 1) guessNo(target, 2);
	else guessNo(target, 1);
}

int main(){
	srand(time(0));
	int target = rand() % 101;
	cout<<target<<endl;
	int winner = guessNo(target);
	cout<<"Player "<<winner<<" is the winner";
}