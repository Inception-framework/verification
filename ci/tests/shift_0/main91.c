#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x70"); 
  __asm volatile("ASR R1, R5, 17");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
