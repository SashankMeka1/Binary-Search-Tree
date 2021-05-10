#include "tree.h"
#include <queue>
#include <iostream>
using namespace std;
tree::tree(){
	root = nullptr;
}
tree::~tree(){
	if(root->left){
		delete root->left;
	}
	if(root->right){
		delete root->right;
	}
	if(root){
		delete root;
	}
}
void tree::insert(node * in_node){
	itr = root;
	while(itr){
		if(in_node->value > itr->value){
			itr = itr->right;
		}
		else{
			itr = itr->left;
		}
	}
	itr = in_node;
}
node * tree::in_succ(node * in_node){
	if(in_node->right){
		in_node = in_node->right;
		while(in_node->left){
			in_node = in_node->left;
		}
		return in_node;
	}
	return nullptr;
}
void tree::del(int value){
	itr = root;
	while(itr){
		if(value > itr->value){
			if(itr->right and itr->right->value == value){
				if(itr->right->right or itr->right->left){
					if(itr->right->left and itr->right->right){
						to_delete = in_succ(itr->right);
						itr->right->value = to_delete->value;
						delete to_delete;
					}
					else{
						to_delete = itr->right;
						itr->right = itr->right->left ? itr->right->left:itr->right->right;
						to_delete->left = to_delete->right = nullptr;
						delete to_delete;
					}	
				}
				else{
					delete itr->right;
				}
			}
			else{
				itr = itr->right;
			}
		}
		else if(value < itr->value){
			if(itr->left and itr->left->value == value){
				if(itr->left->right or itr->left->left){
					if(itr->left->right and itr->left->left){
						to_delete = in_succ(itr->left);
						itr->left->value = to_delete->value;
						delete to_delete;
					}
					else{
						to_delete = itr->left;
						itr->left = itr->left->right ? itr->left->right:itr->left->left;
						to_delete->left = to_delete->right = nullptr;
						delete to_delete;
					}
				}
				else{
					delete itr->left;
				}
			}
			else{
				itr = itr->left;
			}
		}
	}
}
void tree::print(char * to_print){
	queue<node> * print_queue;
	print_queue->push(root);
	while(print_queue->front()){
		print_queue->front()
	}
}
