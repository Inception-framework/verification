#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x85"); 
  __asm volatile("mov R9,#0x0b"); 
  __asm volatile("ASR R5, R3, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
