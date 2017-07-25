#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0x82"); 
  __asm volatile("ASR R9, R9, 20");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
