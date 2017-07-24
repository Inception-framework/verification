#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x67"); 
  __asm volatile("ASR R7, R10, 15");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
