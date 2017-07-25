#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x5a"); 
  __asm volatile("ASR R5, R3, 16");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
