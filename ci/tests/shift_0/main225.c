#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xfa"); 
  __asm volatile("ASR R2, R3, 15");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
