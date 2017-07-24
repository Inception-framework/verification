#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x4f"); 
  __asm volatile("mov R2,#0x19"); 
  __asm volatile("ASR R4, R5, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
