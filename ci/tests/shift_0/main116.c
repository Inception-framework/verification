#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x82"); 
  __asm volatile("mov R5,#0x05"); 
  __asm volatile("LSR R8, R9, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
