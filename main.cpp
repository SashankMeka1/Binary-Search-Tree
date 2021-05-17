#include "tree.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int main(){
	char input[150];
	tree *main_tree = new tree();
	while(true){
		cout << "ADD PRINT DELETE QUIT SEARCH"<<endl;
		cin.getline(input, 150);
		if(!strcmp(input,"ADD")){
			cout << "Number?"<<endl;
			cin.getline(input,150);
			main_tree->insert(new node(atoi(input)));
		}
		else if(!strcmp(input, "PRINT")){
			main_tree->print();
		}
		else if(!strcmp(input, "DELETE")){
			cout << "Number?"<<endl;
			cin.getline(input,150);
			main_tree->del(atoi(input));
		}
		else if(!strcmp(input, "QUIT")){
			delete main_tree;
			return 0;
		}
		else if(!strcmp(input,"SEARCH")){
			cout << "Number?"<<endl;
			cin.getline(input,150);
			main_tree->search(atoi(input));
		}
		else{
			cout << "Invalid"<<endl;
		}
	}

	return 0;
}
