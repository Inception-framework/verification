#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0xce"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xf9"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x80"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xce"); 
  __asm volatile("SUB R1, R11, #0x0e");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
