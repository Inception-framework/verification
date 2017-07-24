#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x37"); 
  __asm volatile("mov R4,#0x08"); 
  __asm volatile("ASR R1, R2, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
