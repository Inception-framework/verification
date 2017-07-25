#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x98"); 
  __asm volatile("ASR R0, R3, 8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
