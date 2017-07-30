#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("mov R2,#-1"); 
  __asm volatile("cmp R8,R2"); 
  __asm volatile("blt bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R1,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R6,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R7,#3"); 
  __asm volatile("cmp R8,R2"); 
  __asm volatile("blt end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
