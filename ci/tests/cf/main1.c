#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R6,#2"); 
  __asm volatile("mov R7,#0"); 
  __asm volatile("cmp R6,R7"); 
  __asm volatile("bmi bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R0,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R5,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R12,#3"); 
  __asm volatile("cmp R6,R7"); 
  __asm volatile("bmi bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
