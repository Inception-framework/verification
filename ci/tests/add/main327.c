#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0x80"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x18"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x41"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xf4"); 
  __asm volatile("ADDS R6, R8, #0x36");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
