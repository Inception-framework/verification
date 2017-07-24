#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xe5"); 
  __asm volatile("ASR R4, R0, 22");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
