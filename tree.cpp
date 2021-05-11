#include "tree.h"
#include <queue>
#include <iostream>
using namespace std;
tree::tree(){
	root = nullptr;
}
tree::~tree(){
	if(root){
		delete root;
	}
}
void tree::insert(node * in_node){
	if(root){
		itr = root;
	}
	else{
		root = in_node;
	}
	while(itr){
		if(in_node->value > itr->value){
			if(itr->right){
				itr = itr->right;
			}
			else{
				itr->right = in_node;
				return;
			}
		}
		else{
			if(itr->left){
				itr = itr->left;
			}
			else{
				itr->left = in_node;
				return;
			}
		}
	}
}
void tree::in_succ(node * in_node){
	itr = in_node;
	if(in_node->right){
		if(in_node->right->left){
			in_node = in_node->right;
			while(in_node->left->left){
				in_node = in_node->left;
			}
			delete in_node->left;
			itr->value = in_node->left->value;
			in_node->left = nullptr;
		}
		else{
			delete in_node->right;
			itr->value = in_node->value;
			in_node->right = nullptr;
		}
	}
}
void tree::del(int value){
	itr = root;
	while(itr){
		if(value > itr->value){
			if(itr->right and itr->right->value == value){
				if(itr->right->right or itr->right->left){
					if(itr->right->left and itr->right->right){
						in_succ(itr->right);
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
					itr->right = nullptr;
				}
				return;
			}
			else{
				itr = itr->right;
			}
		}
		else if(value < itr->value){
			if(itr->left and itr->left->value == value){
				if(itr->left->right or itr->left->left){
					if(itr->left->right and itr->left->left){
						in_succ(itr->left);
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
					itr->left = nullptr;
				}
				return;
			}
			else{
				itr = itr->left;
			}
		}
		else{
			if(itr->left or itr->right){
				if(itr->left and !(itr->right)){
					to_delete = itr;
					root = to_delete->left;
					to_delete->left = nullptr;
					delete to_delete;
				}
				else if(itr->right and !(itr->left)){
					to_delete = itr;
					root = to_delete->right;
					to_delete->right = nullptr;
					delete to_delete;
				}
				else{
					in_succ(itr);
				}
			}
			else{
				delete itr;
				root = nullptr;
			}
			return;
		}
	}	
}
void tree::print_util(node * in_root){
	if(in_root and in_root->left){
		print_util(in_root->left);
	}
	if(in_root){
		cout << in_root->value;
	}
	if(in_root and in_root->right){
		print_util(in_root->right);
	}
}
void tree::print(){
	print_util(root);
}
