#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x17"); 
  __asm volatile("mov R0,#0x0f"); 
  __asm volatile("ASR R0, R3, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
