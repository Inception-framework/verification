#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x3c"); 
  __asm volatile("mov R2,#0x15"); 
  __asm volatile("ASR R8, R5, R2");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
