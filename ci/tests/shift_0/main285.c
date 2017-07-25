#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xc9"); 
  __asm volatile("mov R0,#0x14"); 
  __asm volatile("ASR R12, R7, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
