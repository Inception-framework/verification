#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R1,#0"); 
  __asm volatile("add R1,R1,#0xd9"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x60"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0xaf"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x85"); 
  __asm volatile("UXTB R10, R1, ror #8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}