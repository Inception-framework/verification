#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xc5"); 
  __asm volatile("ASR R12, R6, 28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
