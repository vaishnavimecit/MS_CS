#ifndef __RB_TREE_H__
#define __RB_TREE_H__

enum rb_tree_color 
{
  RB_RED,
  RB_BLACK
};

struct rb_tree_node 
{
  int		key;
  int		color;
  rb_tree_node*	left;
  rb_tree_node*	right;
  rb_tree_node*	p;
  int dup;
};

class rb_tree
{ 
  protected:
    rb_tree_node*	T_nil;
    rb_tree_node*	T_root;
int inp=0;

  public:
    rb_tree();
    ~rb_tree();

    void insert(int*, int);
    void insert(int);

    
    int  TotalCount = 0;
    
	  int leftctr=0;
	  int rightctr=0;
	  int case1ctr=0;
	  int case2ctr=0;
	  int case3ctr=0;

    int inorder_output(int* a)
      { int h = inorder_output(T_root, 1, a);return h; }
    void output()
      { output(T_root, 1); }
      int isBlackHeight1()
      {
        int k =isBlackHeight(T_root);
        return k;
    }

  protected:
    void insert(rb_tree_node*);
    void insert_fixup(rb_tree_node*&);

    void remove_all(rb_tree_node*);

    void left_rotate(rb_tree_node*);
    void right_rotate(rb_tree_node*);

    int inorder_output(rb_tree_node*, int, int*);
    void output(rb_tree_node*, int);
    int isBlackHeight(rb_tree_node*);
};


#endif
