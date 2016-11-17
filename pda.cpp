#include "pda.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <stdlib.h>

using namespace std;

int PDA::index = 0;

PDA::PDA() {
	currentState = &q0;
	sequence = "";
}

void PDA::readSequence() {
	//the pda which we will pass through object
	PDA obj;
	ifstream myfile;
	string temp;
	myfile.open("sequence.txt");
	if (myfile.is_open()) {
		//reads the sequence from the file into the private member sequence
		while (getline(myfile, temp)){
		obj.stack.push_back('z');
		obj.sequence = temp;
		while (index < temp.length() ) {
			evaluate(obj);
		}
		cout << "Correct sequence" << endl;
	  obj.stack.erase(obj.stack.begin(), obj.stack.end());
	  obj.index = 0;
	  //for (int i = 0; i < obj.stack.size(); i++) {
	  //	cout << obj.stack[i] << endl;
	  //}
	}
	}else {
		cout << "The file could not be opend" << endl;
	}
	return ;
}

int PDA::ifOrElseSequence(PDA& arg) {
	//check if the current element is if
	char first = arg.sequence[arg.index];
	char second = arg.sequence[arg.index + 1];
	if ((first == 'i') && (second == 'f')) {
		return 0;
	} else {
		return 1;
	}
}

void PDA::evaluate(PDA& arg) {
	// temp = 0 (if)  temp = 1 (else) 
	int temp = arg.ifOrElseSequence(arg);
	if (temp == 0 ) {
	//push if onto the stack	
		arg.pushStack(arg);
		arg.index = arg.index + 2;
	//the next element is else	
	} else {
	//pop the top element from stack
		if (arg.stack[0] == 'z') {
			cout << "Sequence is syntactically incorrect" << endl;
			exit (EXIT_FAILURE);
			arg.stack.clear();
			arg.index = 0;
			return;
			//exit( "exit_code" );
		}	
		arg.popStack(arg);
		//increment index by 4
		arg.index = arg.index + 4;
	}
}

void PDA::pushStack(PDA& arg) {
	vector<int>::iterator it = stack.begin();
	it = arg.stack.begin();
	arg.stack.insert(it,0);
	return;
}

void PDA::popStack(PDA& arg) {
	vector<int>::iterator it;
	it = arg.stack.begin();
	int len = arg.stack.size();
	if (len == 0 && len == 1) {
		cout << " Sequence is syntactically incorrect" << endl;
		exit (EXIT_FAILURE);
		arg.stack.clear();
		arg.index = 0;
		return;
	}	
	arg.stack.erase(arg.stack.begin(), arg.stack.begin() + 1);
}