#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x84"); 
  __asm volatile("ASR R11, R1, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
