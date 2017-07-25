#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xb6"); 
  __asm volatile("ASR R3, R8, 11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
