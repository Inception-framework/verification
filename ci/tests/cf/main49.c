#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R11,#5"); 
  __asm volatile("mov R6,#5"); 
  __asm volatile("cmp R11,R6"); 
  __asm volatile("bcs bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R10,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R2,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R4,#3"); 
  __asm volatile("cmp R11,R6"); 
  __asm volatile("bcs bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
