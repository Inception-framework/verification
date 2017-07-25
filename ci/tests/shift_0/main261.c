#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x73"); 
  __asm volatile("mov R4,#0x17"); 
  __asm volatile("ASR R10, R11, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
