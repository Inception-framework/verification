#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xd9"); 
  __asm volatile("ASR R1, R8, 18");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
