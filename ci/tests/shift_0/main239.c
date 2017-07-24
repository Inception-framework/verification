#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xa7"); 
  __asm volatile("mov R5,#0x02"); 
  __asm volatile("ASR R8, R8, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
