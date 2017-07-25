#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xe6"); 
  __asm volatile("mov R8,#0x07"); 
  __asm volatile("ASR R3, R11, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
