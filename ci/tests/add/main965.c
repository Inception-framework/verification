#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R4,#0"); 
  __asm volatile("add R4,R4,#0xf0"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x1c"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0xcc"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0xc7"); 
  __asm volatile("ADD R9, R4, #0x78");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
