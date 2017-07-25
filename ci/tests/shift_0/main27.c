#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x70"); 
  __asm volatile("ASR R1, R11, 24");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
