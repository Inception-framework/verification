#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0xca"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x92"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x72"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x0a"); 
  __asm volatile("SBCS R11, R8, #0x23");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
