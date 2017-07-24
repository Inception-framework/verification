#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x14"); 
  __asm volatile("mov R4,#0x16"); 
  __asm volatile("ASR R9, R9, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
