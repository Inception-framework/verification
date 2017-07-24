#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x71"); 
  __asm volatile("mov R3,#0x0a"); 
  __asm volatile("ASR R3, R9, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
