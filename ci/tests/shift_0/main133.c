#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x26"); 
  __asm volatile("mov R0,#0x03"); 
  __asm volatile("ASR R7, R5, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
