#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0xda"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xd1"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x6c"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x2b"); 
  __asm volatile("ADD R4, R8, #0xf84");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
