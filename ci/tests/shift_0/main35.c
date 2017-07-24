#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x9a"); 
  __asm volatile("mov R5,#0x1c"); 
  __asm volatile("ASR R3, R1, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
