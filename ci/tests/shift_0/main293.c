#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xc4"); 
  __asm volatile("mov R12,#0x1c"); 
  __asm volatile("ASR R9, R1, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
