#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xf2"); 
  __asm volatile("mov R11,#0x1b"); 
  __asm volatile("ASR R5, R10, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
