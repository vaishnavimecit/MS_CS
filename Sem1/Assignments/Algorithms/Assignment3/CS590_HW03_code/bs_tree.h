#ifndef __BS_TREE_H__
#define __BS_TREE_H__

struct bs_tree_node 
{
  int		key;
  bs_tree_node*	left;
  bs_tree_node*	right;
  bs_tree_node*	p;
  int dup1=0;
  
};

class bs_tree
{ 
  protected:
    bs_tree_node*	T_nil;
    bs_tree_node*	T_root;
    int inp1=0;
    
  public:
    bs_tree();
    ~bs_tree();

   int* a;
   int  TotalCount1 =0;

    void insert(int*, int);
    void insert(int);

    int inorder_output(int* a)
      { int h=inorder_output(T_root, 1, a);return h; }
    void output()
      { output(T_root, 1); }

  protected:
    void insert(bs_tree_node*);

    void remove_all(bs_tree_node*);

    int inorder_output(bs_tree_node*, int, int*);
    void output(bs_tree_node*, int);
};

#endif
