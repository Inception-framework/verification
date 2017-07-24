#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x83"); 
  __asm volatile("mov R9,#0x0a"); 
  __asm volatile("ASR R8, R2, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
