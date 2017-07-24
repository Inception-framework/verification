#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x25"); 
  __asm volatile("ASR R4, R8, 1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
