#ifndef assignment_h
#define assignment_h

#include <list>
#include "task.h"
#include <vector>

class Assignment{
public:

	std::list<Task*> task_list;

	std::vector<Task> pending_tasks;	
	std::vector<Assignment*> next_states;


	int delay_score;

	int get_num_next_states();

	void calc_score();

	//adds a task to the assignment
	//attention: doesn't removes pending tasks
	void add_task(Task*);

	void make_next_states();

	void show();
	void show_next();

	bool is_leaf();

	Assignment();
};


#endif