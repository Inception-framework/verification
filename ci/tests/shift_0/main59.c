#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x07"); 
  __asm volatile("mov R6,#0x1b"); 
  __asm volatile("ASR R11, R2, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
