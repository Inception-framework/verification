#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x64"); 
  __asm volatile("ASR R12, R10, 6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
