#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xc9"); 
  __asm volatile("mov R1,#0x05"); 
  __asm volatile("LSR R9, R0, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
