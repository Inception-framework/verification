#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x5b"); 
  __asm volatile("mov R3,#0x19"); 
  __asm volatile("ASR R5, R8, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
