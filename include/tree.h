#ifndef tree_h
#define tree_h

#include "assignment.h"

class Tree{
public:
	Assignment root;

	Assignment* current_best_assignment;
	int current_best_score;
	
	Tree();
	Tree(std::string);

	void initialize();
	void seek(Assignment*);
};


#endif