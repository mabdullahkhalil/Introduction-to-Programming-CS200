#include <iostream>
#include "game.h"
#include <ctime>

using namespace std;
int main() {
	srand(time(0));
	int random;
	
	int size; cout<<"size of board: ";
	cin>>size;
	
	game ok(size,size);
	
	for (int i=0; i<size; i++) {
		for (int j=0; j<size; j++) {
			ok[i][j]='-';
		}
	}
	ok.settings(size);
	
	random=rand()%2;
	
	bool gamerunning=true;
	
	int boxes=size*size;
	int box_check=0;
	
	while(gamerunning && box_check<boxes){
		ok.printboard(ok);
		ok.start(random,ok);
		gamerunning=ok.checking_rows(ok,random,size);
		
		if (gamerunning==false) {
			ok.printboard(ok);
			break;
		}
		
		
		
		gamerunning=ok.checking_columns(ok,random,size);
		
		if (gamerunning==false) {
			ok.printboard(ok);
			break;
		}
		
		gamerunning=ok.checking_diagnolr(ok,random,size);
		
		if (gamerunning==false) {
			ok.printboard(ok);
			break;
		}
		
		gamerunning=ok.checking_diagnoll(ok,random,size);
		
		if (gamerunning==false) {
			ok.printboard(ok);
			break;
		}
		
		
		if(random==1){
			random=0;
		}
		else{
			random=1;}

		box_check++;
		//ok.printboard(ok);
	}
	
	if (box_check==boxes) {
		cout<<"GAME DRAWN."<<endl;
	}
}





