#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xa6"); 
  __asm volatile("ASR R0, R7, 20");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
