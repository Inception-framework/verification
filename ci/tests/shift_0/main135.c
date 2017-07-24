#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xd4"); 
  __asm volatile("ASR R1, R1, 5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
