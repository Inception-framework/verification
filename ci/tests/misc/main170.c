#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#4"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R3,#0"); 
  __asm volatile("add R3,R3,#0xb5"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xc2"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x5d"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x42"); 
  __asm volatile("CLZ R12, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
