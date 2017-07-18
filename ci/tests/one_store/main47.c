#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r12,#1"); 
  __asm volatile("str r12,[sp,#4]!");
  __asm volatile("mov r12,#2"); 
  __asm volatile("ldr r12,[sp,#4]!");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
