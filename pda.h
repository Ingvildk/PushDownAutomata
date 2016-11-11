#ifndef __PDA__H
#define __PDA__H

#include <vector>
#include <string>

class PDA {
	public:
		int q0;
		int q1;
		int *currentState;
		std::vector<int> stack;
		std::string sequence;
		static int index;
		PDA();
		void readSequence();
		void pushStack(PDA& arg);
		void popStack(PDA& arg);
		void evaluate(PDA& arg);
		int ifOrElseSequence(PDA& arg);
};

#endif