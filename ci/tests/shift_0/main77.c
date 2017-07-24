#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xf4"); 
  __asm volatile("mov R11,#0x10"); 
  __asm volatile("ASR R4, R1, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
