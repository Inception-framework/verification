#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0x07"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x85"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x48"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xd7"); 
  __asm volatile("SUB R5, R11, #0xb21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
