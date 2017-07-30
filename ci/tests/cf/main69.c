#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("mov R5,#-4"); 
  __asm volatile("cmp R8,R5"); 
  __asm volatile("blt bb2"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R11,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R0,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R4,#3"); 
  __asm volatile("cmp R8,R5"); 
  __asm volatile("blt end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
