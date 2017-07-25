#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xb0"); 
  __asm volatile("ASR R1, R0, 28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
