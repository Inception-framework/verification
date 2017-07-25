#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x13"); 
  __asm volatile("ASR R0, R3, 21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
