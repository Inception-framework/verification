#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R7,#0"); 
  __asm volatile("add R7,R7,#0xae"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x8d"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0xe4"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x29"); 
  __asm volatile("TEQ R11, R7, rrx");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
