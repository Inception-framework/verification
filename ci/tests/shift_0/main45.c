#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x06"); 
  __asm volatile("ASR R8, R11, 30");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
