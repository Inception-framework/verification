#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x95"); 
  __asm volatile("ASR R12, R2, 24");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
