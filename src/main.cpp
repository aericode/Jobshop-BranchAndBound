#include "task.h"
#include "assignment.h"
#include "tree.h"
#include <vector>
#include <iostream>

int main(){

	std::vector<Task> all_tasks;

	Task A ("Alberto",1,3);
	Task B ("Bruna",1,2);
	Task C ("Carmen",1,1);
	Task D ("Dani",1,4);
	Task E ("Eduardo",1,5);

	all_tasks.push_back(A);
	all_tasks.push_back(B);
	all_tasks.push_back(C);
	all_tasks.push_back(D);
	all_tasks.push_back(E);

	
	Assignment assignment;
	assignment.pending_tasks = all_tasks;

	Tree tree;

	tree.root = assignment;
	tree.seek(&tree.root);

	tree.current_best_assignment->show();


}