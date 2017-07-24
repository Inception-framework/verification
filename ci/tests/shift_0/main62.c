#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x65"); 
  __asm volatile("LSR R3, R1, 20");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
