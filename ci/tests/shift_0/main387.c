#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x18"); 
  __asm volatile("ASR R10, R1, 10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
