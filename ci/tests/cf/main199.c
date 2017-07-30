#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R6,#-4"); 
  __asm volatile("mov R7,#-1"); 
  __asm volatile("cmp R6,R7"); 
  __asm volatile("bge bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R3,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R12,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R2,#3"); 
  __asm volatile("cmp R6,R7"); 
  __asm volatile("bge bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
