#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x35"); 
  __asm volatile("ASR R12, R1, 28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
