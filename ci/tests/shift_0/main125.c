#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xef"); 
  __asm volatile("mov R9,#0x16"); 
  __asm volatile("ASR R9, R11, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
