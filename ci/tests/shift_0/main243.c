#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x43"); 
  __asm volatile("ASR R3, R11, 15");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
