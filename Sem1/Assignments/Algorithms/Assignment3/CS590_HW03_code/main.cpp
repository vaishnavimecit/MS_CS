
#include <cstdio>
#include <cstdlib>

#include "sort.h"
#include "bs_tree.h"
#include "rb_tree.h"
#include "timer.h"
#include "random_generator.h"

int main(int argc, char* argv[])
{  
  timer t;
  int  a, n, d;

if (argc > 1)
    {
      n = atoi(argv[1]);
      n = (n < 0) ? 0 : n;
    }
  else
    n = 0;    
if (argc > 2)
{
    n = atoi(argv[1]);
    d = atoi(argv[2]);

  int* rb_arr;
  int* bs_arr;
  rb_arr = new int[n];
  bs_arr = new int[n];

//create input array sorted/reverse sorted/random depending on program argument

  t.start();
  if (d == 0)
  {
    rb_arr = create_random(n);
    bs_arr = create_random(n);
  }
  else
  {
      if (d < 0)
	{
	rb_arr = create_reverse_sorted(n);
	bs_arr = create_reverse_sorted(n);
	}
      else
	{
	rb_arr = create_sorted(n);
	bs_arr = create_sorted(n);
	}
   }
  t.stop();
  cout << "Timer (generate): " << t << endl;

//BS Tree
bs_tree bst;

t.start();
bst.insert(bs_arr,n);
t.stop();
cout<<endl;
cout<<"Inserted into BS Tree"<<endl;
cout << "Timer (Insert BST): " << t << endl;
//output the first 10 elements for debugging purposes

  for (int i = 0; (i < n) && (i < 10); i++)
    {
      cout << "[ ";
	cout << bs_arr[i] << " ";
      cout << "]" << endl;
    }
  cout << endl;
t.start();
cout<<endl;
int k1 = bst.inorder_output(bs_arr);
t.stop();
cout<<endl;
cout << endl;
cout << "Total duplicate entry: " << bst.TotalCount1 << endl;

if (check_sorted(bs_arr,0,k1))
cout<<"Binary Search Tree array is Sorted"<<endl;
else
cout<<"Error:BST Not Sorted"<<endl;

cout << "Timer (Sort BST): " << t << endl;

//RB Tree
rb_tree rbt;
t.start();
rbt.insert(rb_arr,n);
t.stop();
cout<<"Inserted in Red Black tree"<<endl;
cout << "Timer (Insert RB): " << t << endl;
cout<<endl;

//output the first 10 elements for debugging purposes
  for (int i = 0; (i < n) && (i < 10); i++)
    {
      cout << "[ ";
	cout << rb_arr[i] << " ";
      cout << "]" << endl;
    }
  cout << endl;

t.start();
int k = rbt.inorder_output(rb_arr);
t.stop();
cout<<endl;
cout << endl;
cout << "Total Duplicate entry:" << rbt.TotalCount << endl;
cout << "Left rotate count:" << rbt.leftctr << endl;
cout << "Right rotate count:" << rbt.rightctr << endl;
cout << "Case 1 count:" << rbt.case1ctr << endl;
cout << "Case 2 count:" << rbt.case2ctr << endl;
cout << "Case 3 count:" << rbt.case3ctr << endl;
cout << endl;

int isBH = rbt.isBlackHeight1();
cout << "Black Height: "  << isBH << endl;
if (isBH == 1)
cout<<"Property 5 of RB tree successs"<<endl;
else
cout<<"Property 5 of RB tree failed"<<endl;

cout << endl;
cout << endl;

if (check_sorted(rb_arr,0,k))
cout<<"Red Black tree array is Sorted"<<endl;
else
cout<<"Error: RBT Not Sorted"<<endl;
cout << "Timer (Sort RB): " << t << endl;
cout<<endl;
//rbt.output();
}
  
else
    {
      cout << "hw3: [n] [direction]" << endl;
      cout << "[n]              size of the random integer array" << endl;
      cout << "[direction]      0: random" << endl;
      cout << "                 1: sorted" << endl;
      cout << "                 -1: reverse sorted" << endl;
      cout << endl;
      return 0;
    }

  return 0;
}