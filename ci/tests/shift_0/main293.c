#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xa8"); 
  __asm volatile("mov R12,#0x10"); 
  __asm volatile("ASR R3, R1, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
