#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x49"); 
  __asm volatile("mov R3,#0x01"); 
  __asm volatile("LSR R1, R9, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
