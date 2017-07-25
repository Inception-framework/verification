#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x8f"); 
  __asm volatile("ASR R6, R12, 17");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
