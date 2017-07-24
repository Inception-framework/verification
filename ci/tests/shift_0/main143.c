#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x3f"); 
  __asm volatile("mov R11,#0x01"); 
  __asm volatile("ASR R3, R10, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
