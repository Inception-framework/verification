#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x87"); 
  __asm volatile("mov R3,#0x19"); 
  __asm volatile("ASR R0, R7, R3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
