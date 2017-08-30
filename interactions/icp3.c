#include "stdlib.h"
#include "stdio.h"

#ifdef NOPRINT
void inception_enable_trace();
void inception_disable_trace();
#endif

int R0;

void test(int* array,int size){
	int i;
	for(i=0;i<size;i++){
		#ifndef NOPRINT
		printf("read array : %d\n", array[i]);
		#endif
	}
}

void main(void) {
	__asm volatile("mov r0,r0");
	int x[3] = {1,2,3};
	test(&x[0],3);
}
