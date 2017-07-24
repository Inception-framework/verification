#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x00"); 
  __asm volatile("ASR R12, R0, 12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
