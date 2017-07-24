#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x9a"); 
  __asm volatile("LSL R1, R12, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
