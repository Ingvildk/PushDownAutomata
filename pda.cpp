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
	stack.push_back('z');
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
		getline(myfile, temp);
		obj.sequence = temp;
		while (index < temp.length() ) {
			evaluate(obj);
		}
		cout << "The sequence is valid" << endl;
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
			cout << " Not a valid sequence of paired ifs and elses" << endl;
			exit (EXIT_FAILURE);
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
	arg.stack.erase(it);
}