#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x31"); 
  __asm volatile("ASR R0, R10, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
