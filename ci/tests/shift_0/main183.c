#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x3d"); 
  __asm volatile("ASR R1, R11, 25");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
