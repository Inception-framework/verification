#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R2,#-2"); 
  __asm volatile("mov R8,#2"); 
  __asm volatile("cmp R2,R8"); 
  __asm volatile("bhi bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R10,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R5,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R11,#3"); 
  __asm volatile("cmp R2,R8"); 
  __asm volatile("bhi end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
