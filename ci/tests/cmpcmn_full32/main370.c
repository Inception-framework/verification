#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#4"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R9,#0"); 
  __asm volatile("add R9,R9,#0xdf"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xa2"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xe5"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x2b"); 
  __asm volatile("mov R2,#0"); 
  __asm volatile("add R2,R2,#0x9e"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x3f"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x4f"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x15"); 
  __asm volatile("CMP R9, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
