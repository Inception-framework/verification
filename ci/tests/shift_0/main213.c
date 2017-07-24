#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xa5"); 
  __asm volatile("ASR R12, R5, 30");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
