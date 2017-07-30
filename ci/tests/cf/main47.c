#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R12,#0"); 
  __asm volatile("mov R4,#-3"); 
  __asm volatile("cmp R12,R4"); 
  __asm volatile("bmi bb2"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R1,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R0,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R7,#3"); 
  __asm volatile("cmp R12,R4"); 
  __asm volatile("bmi end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
