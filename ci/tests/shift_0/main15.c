#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x93"); 
  __asm volatile("ASR R8, R3, 29");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
