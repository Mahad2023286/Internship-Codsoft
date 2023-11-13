
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
	srand((unsigned int)time(NULL));
	int number = (rand()%100)+1;
	int guess=0;
	do{
		cout<<"Enter Guess between 1 and 100! \n";
		cin>>guess;
		
		if(guess>number)
		cout<<"Guess Lower \n";
		
		else if(guess<number)
		cout<<"Guess Higher \n";
		
		else
		cout<<"You won! \n";
		
	}while(guess!=number);
	
	return 0;
}
