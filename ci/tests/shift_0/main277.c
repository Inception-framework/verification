#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xda"); 
  __asm volatile("mov R9,#0x07"); 
  __asm volatile("ASR R11, R1, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
