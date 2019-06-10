#ifndef __SORT_H__
#define __SORT_H__

/*
 * check functions
 */
bool check_sorted(char**, int, int);

/*
 * character sort
 */
int string_compare(char*, char*);
void insertion_sort_ori(char**, int, int);
void insertion_sort(char**, int, int, int, int*);
void radix_sort(char**, int, int, int*);
void radix_sort_count(char**,char**, int, int,int*);
void counting_sort(char**, char**, int, int, int, int*);

#endif
