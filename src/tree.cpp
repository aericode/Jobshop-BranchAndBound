#define INT_MAX 2147483647

#include "tree.h"
#include "assignment.h"
#include <fstream>
#include <iostream>

Tree::Tree(std::string file_location){
	
	Assignment assignment;
	Task* next_task;

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

		next_task = new Task(tag, conv_duration, conv_deadline);

		assignment.add_task(next_task);
	}

	//optional - try tasks in the sequence they were read
	//and register their times as an assignment
	//current_best_assignment = assignment;
	//current_candidate.update_task_timing();
	//current_candidate.calc_score();

	//current_best_score = current_candidate.delay_score;
	//current_best_assignment = current_candidate;

	//registers these tasks as pending
	
	this->root = assignment;
	current_best_score = INT_MAX;

}

Tree::Tree(){
	current_best_score = INT_MAX;
}

void Tree::seek(Assignment* seek_node){
	if(seek_node->is_leaf()){
		//father node previously called leaf's calc_score
		//TODO: fix case where root is leaf

		if(seek_node->delay_score < current_best_score){
			current_best_score = seek_node->delay_score;
			current_best_assignment = seek_node;
		}

	}else{

		seek_node->make_next_states();

		int num_states = seek_node->get_num_next_states();

		for(int i = 0; i < num_states; i++){
			seek_node->next_states[i]->calc_score();
		}

		for(int i = 0; i < num_states; i++){
			//checks if there is a possibility of generating a better state from the current
			if(seek_node->next_states[i]->delay_score < current_best_score){
				seek(seek_node->next_states[i]);
			}
		}

	}
}

