#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0xd7"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x10"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x37"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xd1"); 
  __asm volatile("SUB R1, R11, #0x009");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
