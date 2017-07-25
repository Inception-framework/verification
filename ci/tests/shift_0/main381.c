#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xdf"); 
  __asm volatile("mov R3,#0x1f"); 
  __asm volatile("ASR R1, R6, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
