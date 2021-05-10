#include "node.h"
class tree{
	private:
	node* root;
	node * itr;
	node * to_delete;
	public:
	tree();
	~tree();
	void insert(node *in_node);
	void del(int value);
	void print(char * to_print);
	node * in_succ(node * in_node);
};
