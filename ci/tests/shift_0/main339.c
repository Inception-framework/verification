#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0x81"); 
  __asm volatile("ASR R11, R11, 17");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
