#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x4f"); 
  __asm volatile("ASR R0, R12, 25");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
