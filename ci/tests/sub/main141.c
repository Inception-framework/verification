#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0"); 
  __asm volatile("add R3,R3,#0x92"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xa6"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x51"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xd7"); 
  __asm volatile("SUB R11, R3, #0x61");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
