#include "node.h"
node::node(int in_value){
	value = in_value;
}
node::~node(){
	if(left){
		delete left;
	}
	if(right){
		delete right;
	}
}
