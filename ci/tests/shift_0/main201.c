#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x19"); 
  __asm volatile("ASR R7, R3, 25");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
