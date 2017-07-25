#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x06"); 
  __asm volatile("mov R2,#0x01"); 
  __asm volatile("ASR R6, R9, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
