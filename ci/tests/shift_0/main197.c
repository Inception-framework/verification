#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x48"); 
  __asm volatile("mov R12,#0x13"); 
  __asm volatile("ASR R11, R3, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
