#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x43"); 
  __asm volatile("mov R10,#0x15"); 
  __asm volatile("ASR R0, R0, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
