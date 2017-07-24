#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x94"); 
  __asm volatile("ASR R6, R8, 29");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
