#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x29"); 
  __asm volatile("mov R1,#0x14"); 
  __asm volatile("ASR R2, R9, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
