#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xa9"); 
  __asm volatile("mov R7,#0x07"); 
  __asm volatile("ASR R11, R1, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
