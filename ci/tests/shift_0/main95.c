#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0xea"); 
  __asm volatile("mov R6,#0x18"); 
  __asm volatile("ASR R1, R3, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
