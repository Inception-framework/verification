#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x5a"); 
  __asm volatile("mov R10,#0x16"); 
  __asm volatile("ASR R5, R4, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
