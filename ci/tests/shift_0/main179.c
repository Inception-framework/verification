#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x44"); 
  __asm volatile("mov R9,#0x0e"); 
  __asm volatile("ASR R4, R8, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
