#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0x79"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xc4"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x5c"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x38"); 
  __asm volatile("ADD R4, R11, #0xaca");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
