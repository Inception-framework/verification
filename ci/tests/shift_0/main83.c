#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xaf"); 
  __asm volatile("ASR R5, R12, 8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
