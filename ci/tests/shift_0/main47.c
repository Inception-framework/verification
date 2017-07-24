#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x45"); 
  __asm volatile("mov R3,#0x1f"); 
  __asm volatile("ASR R8, R4, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
