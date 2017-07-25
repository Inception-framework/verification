#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x94"); 
  __asm volatile("mov R5,#0x1a"); 
  __asm volatile("ASR R2, R2, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
