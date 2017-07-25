#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x25"); 
  __asm volatile("mov R2,#0x1b"); 
  __asm volatile("ASR R6, R1, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
