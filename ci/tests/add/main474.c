#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0x45"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x56"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x8d"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x6d"); 
  __asm volatile("ADD R8, R10, #0x8ef");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
