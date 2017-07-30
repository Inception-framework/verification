#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R7,#-2"); 
  __asm volatile("mov R8,#-3"); 
  __asm volatile("cmp R7,R8"); 
  __asm volatile("bvc bb1"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R1,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R3,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R10,#3"); 
  __asm volatile("cmp R7,R8"); 
  __asm volatile("bvc bb1"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
