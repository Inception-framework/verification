#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0xeb"); 
  __asm volatile("ASR R1, R6, 22");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
