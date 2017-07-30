#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R6,#2"); 
  __asm volatile("mov R4,#3"); 
  __asm volatile("cmp R6,R4"); 
  __asm volatile("bhi bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R5,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R11,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R3,#3"); 
  __asm volatile("cmp R6,R4"); 
  __asm volatile("bhi end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
