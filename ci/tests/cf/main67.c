#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R9,#3"); 
  __asm volatile("mov R2,#-3"); 
  __asm volatile("cmp R9,R2"); 
  __asm volatile("bhi bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R12,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R4,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R6,#3"); 
  __asm volatile("cmp R9,R2"); 
  __asm volatile("bhi end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
