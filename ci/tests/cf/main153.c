#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R5,#-1"); 
  __asm volatile("mov R8,#-1"); 
  __asm volatile("cmp R5,R8"); 
  __asm volatile("bgt bb2"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R7,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R3,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R6,#3"); 
  __asm volatile("cmp R5,R8"); 
  __asm volatile("bgt bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
