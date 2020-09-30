#include "task.h"
#include "assignment.h"
#include "tree.h"
#include <vector>
#include <iostream>
#include <fstream>


std::vector<Task> readTasks(std::string file_location){
	
	std::vector<Task> all_tasks;

	Assignment* assignment = new Assignment();

	std::string tag;
	std::string duration;
	std::string deadline;

	int conv_duration;
	int conv_deadline;

	std::ifstream input(file_location);

	if(!input.is_open()) std::cout << "Error during file reading" << std::endl;

	while(input.good()){
		getline(input, tag, ',');
		getline(input, duration, ',');
		getline(input, deadline, '\n');

		conv_duration = std::stoi(duration);
		conv_deadline = std::stoi(deadline);

		
		Task next_task(tag,conv_duration,conv_deadline);
		all_tasks.push_back(next_task);
	}

	//optional - try tasks in the sequence they were read
	//and register their times as an assignment
	//current_best_assignment = assignment;
	//current_candidate.update_task_timing();
	assignment->calc_score();

	//current_best_score = current_candidate.delay_score;
	//current_best_assignment = current_candidate;

	//registers these tasks as pending



	//this->root = assignment;
	//current_best_score = INT_MAX;

	return all_tasks;

}

int main(){

	std::vector<Task> all_tasks = readTasks("./input/default.csv");

	/*
	Task A ("Alberto",1,1);
	Task B ("Bruna",1,2);
	Task C ("Carmen",1,3);
	Task D ("Dani",1,4);
	Task E ("Eduardo",1,5);

	all_tasks.push_back(A);
	all_tasks.push_back(B);
	all_tasks.push_back(C);
	all_tasks.push_back(D);
	all_tasks.push_back(E);
	*/
	
	Assignment assignment;
	assignment.pending_tasks = all_tasks;
	


	Tree tree;
	tree.root = assignment;
	tree.seek(&tree.root);

	tree.current_best_assignment->show();


}