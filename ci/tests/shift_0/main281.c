#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x6a"); 
  __asm volatile("mov R12,#0x16"); 
  __asm volatile("ASR R10, R12, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
