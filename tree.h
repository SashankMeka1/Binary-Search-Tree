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
	void print();
	void search(int value);
	void print_util(node * in_root, int value);
	void in_succ(node * in_node);
};
