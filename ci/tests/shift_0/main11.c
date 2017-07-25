#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x20"); 
  __asm volatile("ASR R11, R5, 13");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
