#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x6f"); 
  __asm volatile("mov R7,#0x20"); 
  __asm volatile("ASR R11, R6, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
