#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x85"); 
  __asm volatile("ASR R8, R10, 18");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
