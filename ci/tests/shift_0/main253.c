#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x9e"); 
  __asm volatile("mov R0,#0x0f"); 
  __asm volatile("ASR R7, R7, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
