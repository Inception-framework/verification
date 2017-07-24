#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x9b"); 
  __asm volatile("mov R12,#0x1b"); 
  __asm volatile("ASR R7, R4, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
