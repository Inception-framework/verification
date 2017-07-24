#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x53"); 
  __asm volatile("ASR R0, R4, 10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
