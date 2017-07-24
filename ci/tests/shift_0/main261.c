#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xa8"); 
  __asm volatile("ASR R4, R2, 27");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
