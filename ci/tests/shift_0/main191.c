#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xca"); 
  __asm volatile("mov R0,#0x18"); 
  __asm volatile("ASR R10, R1, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
