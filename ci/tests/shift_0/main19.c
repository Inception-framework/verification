#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x85"); 
  __asm volatile("ASR R0, R9, 31");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
