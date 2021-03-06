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
	else{
		root = in_node;
	}
}
void tree::search(int value){
	itr = root;
	while(itr and itr->value != value){
		if(value>itr->value){
			itr = itr->right;
		}
		else if(value < itr->value){
			itr = itr->left;
		}
	}
	if(itr){
		cout << itr->value<<endl;
	}
	else{
		cout << "Does not exist"<<endl;
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
				itr->value = in_node->left->value;
				to_delete = in_node->left;
				in_node->left = to_delete->right;
				to_delete->right = nullptr;
				delete to_delete;
			}
		
		else{
			in_node->value = in_node->right->value;
			to_delete = in_node->right;
			in_node->right = in_node->right->right;
			to_delete->right = nullptr;
			delete to_delete;
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
void tree::print_util(node * in_root, int space){
	if(!in_root){
		return;	
	}
	space+=10;
	print_util(in_root->left, space);
	cout <<endl;
	for(int i = 10; i < space;i++){
		cout <<" ";
	}
	cout<<in_root->value<<endl;
	print_util(in_root->right,space);
}
void tree::print(){
	print_util(root,0);
	cout << endl;
}
