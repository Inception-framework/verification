#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x13"); 
  __asm volatile("mov R10,#0x0c"); 
  __asm volatile("ASR R8, R2, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
