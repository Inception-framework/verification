#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0xbe"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xb6"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x53"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x3a"); 
  __asm volatile("ADD R12, R11, #0x079");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
