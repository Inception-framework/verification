#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xef"); 
  __asm volatile("ASR R6, R9, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
