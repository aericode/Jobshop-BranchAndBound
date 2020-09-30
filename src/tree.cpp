#define INT_MAX 2147483647

#include "tree.h"
#include "assignment.h"



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

