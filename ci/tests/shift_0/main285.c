#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0x4f"); 
  __asm volatile("ASR R9, R0, 23");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
