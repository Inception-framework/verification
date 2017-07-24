#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x1a"); 
  __asm volatile("ASR R5, R7, 2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
