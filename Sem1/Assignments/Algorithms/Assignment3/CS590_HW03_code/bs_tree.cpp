
#include "bs_tree.h"
#include <list>
#include <iostream>

using namespace std;

bs_tree::bs_tree()
{ 
  T_nil = new bs_tree_node();
  T_nil->p = T_nil;
  T_nil->left = T_nil;
  T_nil->right = T_nil;

  T_root = T_nil;
}

bs_tree::~bs_tree()
{ 
  remove_all(T_root);

  delete T_nil;
}

void bs_tree::insert(int* key_array, int n)
{
  for (int i = 0; i < n; i++)
    insert(key_array[i]);
} 

void bs_tree::insert(int key)
{ 
  bs_tree_node* z;

  z = new bs_tree_node;
  z->key = key;
  z->dup1=1;
  insert(z);
}

void bs_tree::insert(bs_tree_node* z)
{ 
  bs_tree_node* x;
  bs_tree_node* y;

  y = T_nil;
  x = T_root;
  while (x != T_nil)
    {

	if(z->key == x->key)
	{
		TotalCount1++;
    x->dup1++;
		return;
	}
      y = x;

      if (z->key < x->key)
	x = x->left;
      else
	x = x->right;
    }

  z->p = y;
  if (y == T_nil)
    T_root = z;
  else
    {
      if (z->key < y->key)
	y->left = z;
      else
	y->right = z;
    }

  z->left = T_nil;
  z->right = T_nil;
}

int bs_tree::inorder_output(bs_tree_node* x, int level, int* inparr1)
{ 
  if (x != T_nil)
    {
      inorder_output(x->left, level+1, inparr1);
      inparr1[inp1] = x->key;
       inp1++;
      if(inp1 < 20)
      {
       cout << "(" << x->key << "," << level << "," << inp1 << ")" << endl;
      
      }
      
      inorder_output(x->right, level+1, inparr1); 
    }
    return inp1;
}

void bs_tree::output(bs_tree_node* x, int r_level)
{ 
  list< pair<bs_tree_node*,int> > l_nodes;
  pair<bs_tree_node*,int> c_node;
  int c_level;

  c_level = r_level;
  l_nodes.insert(l_nodes.end(), pair<bs_tree_node*,int>(x, r_level));

  while (!l_nodes.empty())
    {
      c_node = *(l_nodes.begin());

      if (c_level < c_node.second)
	{
	  cout << endl;
	  c_level = c_node.second;
	}

      if (c_node.first->p == T_nil)
	cout << ",ROOT) ";
      else
        cout << ",P:" << c_node.first->p->key << ") ";

      if (c_node.first->left != T_nil)
	l_nodes.insert(l_nodes.end(), pair<bs_tree_node*,int>(c_node.first->left, 
							      c_node.second+1));
      if (c_node.first->right != T_nil)
	l_nodes.insert(l_nodes.end(), pair<bs_tree_node*,int>(c_node.first->right, 
							      c_node.second+1));
      l_nodes.erase(l_nodes.begin());
    }

  cout << endl;
}

void bs_tree::remove_all(bs_tree_node* x)
{
  if (x != T_nil)
    {
      remove_all(x->left);
      remove_all(x->right);

      delete x;
    }
}