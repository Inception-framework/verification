#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x4b"); 
  __asm volatile("mov R8,#0x15"); 
  __asm volatile("ASR R2, R7, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
