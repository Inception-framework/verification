#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x15"); 
  __asm volatile("ASR R5, R9, 32");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
