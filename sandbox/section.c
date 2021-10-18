#include<stdio.h>
#include<stdlib.h>
 
int global_var;	//bss
int global_var2=100; //data
 
int main(void){
	static int local;	//bss
	static int local2=100; //data
	int i; //stack
	char *c;
	c = (char*)malloc(100); //heap
 
	return 0;
}
