#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R3,#0"); 
  __asm volatile("add R3,R3,#0xa4"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x03"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x1a"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x4c"); 
  __asm volatile("ADD R3, R3, #0x092");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
