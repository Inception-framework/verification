#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0"); 
  __asm volatile("add R3,R3,#0xdb"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xf2"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xee"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xd1"); 
  __asm volatile("SUB R9, R3, #0x5fb");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
