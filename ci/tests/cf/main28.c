#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r1,#2"); 
  __asm volatile("cmp r1,#0"); 
  __asm volatile("bne compute"); 
  __asm volatile("mov r0,#0"); 
  __asm volatile("b return"); 
  __asm volatile("compute:"); 
  __asm volatile("mov r2,#2"); 
  __asm volatile("mov r3,#3"); 
  __asm volatile("add r0,r2,r3"); 
  __asm volatile("return:"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
