#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R9,#0xcf"); 
  __asm volatile("ASR R2, R9, 28");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
