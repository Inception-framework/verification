#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x5d"); 
  __asm volatile("ASR R10, R0, 20");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
