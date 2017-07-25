#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xc1"); 
  __asm volatile("mov R11,#0x1b"); 
  __asm volatile("ASR R10, R7, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
