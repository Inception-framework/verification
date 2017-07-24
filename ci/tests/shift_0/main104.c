#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x42"); 
  __asm volatile("LSR R1, R3, 3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
