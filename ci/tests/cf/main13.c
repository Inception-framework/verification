#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("start:"); 
  __asm volatile("mov R12,#5"); 
  __asm volatile("mov R9,#4"); 
  __asm volatile("cmp R12,R9"); 
  __asm volatile("ble bb3"); 
  __asm volatile("bb1:"); 
  __asm volatile("mov R1,#1"); 
  __asm volatile("b end"); 
  __asm volatile("bb2:"); 
  __asm volatile("mov R8,#2"); 
  __asm volatile("bb3:"); 
  __asm volatile("mov R5,#3"); 
  __asm volatile("cmp R12,R9"); 
  __asm volatile("ble end"); 
  __asm volatile("end:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
