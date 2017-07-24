#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x1f"); 
  __asm volatile("ASR R3, R11, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
