#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x3b"); 
  __asm volatile("mov R4,#0x09"); 
  __asm volatile("ASR R7, R12, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
