#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R10,#0"); 
  __asm volatile("mov R6,#-5"); 
  __asm volatile("cmp R10,R6"); 
  __asm volatile("blo bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R7,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R1,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R2,#3"); 
  __asm volatile("cmp R10,R6"); 
  __asm volatile("blo end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
