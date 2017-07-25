#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x94"); 
  __asm volatile("ASR R4, R10, 14");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
