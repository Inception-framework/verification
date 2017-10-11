#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#4"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("ADDS R12, R15, #0xcb");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
