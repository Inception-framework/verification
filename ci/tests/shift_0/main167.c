#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x03"); 
  __asm volatile("mov R3,#0x14"); 
  __asm volatile("ASR R9, R7, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
