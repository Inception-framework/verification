#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R8,#4"); 
  __asm volatile("mov R5,#-5"); 
  __asm volatile("cmp R8,R5"); 
  __asm volatile("bvs bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R2,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R7,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R3,#3"); 
  __asm volatile("cmp R8,R5"); 
  __asm volatile("bvs end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
