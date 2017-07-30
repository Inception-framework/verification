#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R11,#-3"); 
  __asm volatile("mov R10,#-5"); 
  __asm volatile("cmp R11,R10"); 
  __asm volatile("blt bb2"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R2,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R5,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R1,#3"); 
  __asm volatile("cmp R11,R10"); 
  __asm volatile("blt bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
