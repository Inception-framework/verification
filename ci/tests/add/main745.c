#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R0,#0"); 
  __asm volatile("add R0,R0,#0x90"); 
  __asm volatile("lsl R0,R0,#8"); 
  __asm volatile("add R0,R0,#0xe7"); 
  __asm volatile("lsl R0,R0,#8"); 
  __asm volatile("add R0,R0,#0x9b"); 
  __asm volatile("lsl R0,R0,#8"); 
  __asm volatile("add R0,R0,#0x94"); 
  __asm volatile("ADD R8, R0, #0xce");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
