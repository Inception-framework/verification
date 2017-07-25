#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xdd"); 
  __asm volatile("mov R1,#0x1e"); 
  __asm volatile("ASR R11, R6, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
