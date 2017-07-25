#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x84"); 
  __asm volatile("mov R2,#0x02"); 
  __asm volatile("ASR R5, R11, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
