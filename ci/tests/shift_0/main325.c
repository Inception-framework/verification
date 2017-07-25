#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xb5"); 
  __asm volatile("mov R9,#0x09"); 
  __asm volatile("ASR R9, R7, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
