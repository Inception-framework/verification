#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x6e"); 
  __asm volatile("ASR R2, R5, 26");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
