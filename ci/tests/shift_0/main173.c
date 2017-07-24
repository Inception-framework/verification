#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xca"); 
  __asm volatile("mov R7,#0x07"); 
  __asm volatile("ASR R8, R9, R7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
