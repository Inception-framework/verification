#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R5,#-1"); 
  __asm volatile("mov R9,#-4"); 
  __asm volatile("cmp R5,R9"); 
  __asm volatile("bmi bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R11,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R0,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R6,#3"); 
  __asm volatile("cmp R5,R9"); 
  __asm volatile("bmi bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
