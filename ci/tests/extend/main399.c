#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0xfd"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x05"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xa5"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xf5"); 
  __asm volatile("UXTB R10, R10, ror #8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
