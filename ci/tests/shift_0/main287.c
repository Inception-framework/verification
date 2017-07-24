#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xdc"); 
  __asm volatile("mov R2,#0x01"); 
  __asm volatile("ASR R12, R6, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
