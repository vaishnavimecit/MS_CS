#ifndef __DYNPROG_H__
#define __DYNPROG_H__

int** bottomupSW(char*, char*, int, int, int**, int**);
void printSeqAlignX(char*,int**,int,int);
void printSeqAlignY(char*,int**,int,int);

int topdownSW(char*, char*, int, int, int**);
void printTopDownX(char*, char*, int**, int , int );
void printTopDownY(char*, char*, int**, int , int );

#endif
