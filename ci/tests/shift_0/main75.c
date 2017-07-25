#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0xbc"); 
  __asm volatile("ASR R5, R5, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
