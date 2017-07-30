#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R1,#1"); 
  __asm volatile("mov R12,#-2"); 
  __asm volatile("cmp R1,R12"); 
  __asm volatile("bmi bb1"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R3,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R10,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R4,#3"); 
  __asm volatile("cmp R1,R12"); 
  __asm volatile("bmi end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
