#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R3,#0"); 
  __asm volatile("add R3,R3,#0x48"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xdf"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x48"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x0e"); 
  __asm volatile("ADD R4, R3, #0x48");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
