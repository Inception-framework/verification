#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x0d"); 
  __asm volatile("ASR R9, R3, 23");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
