#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xe5"); 
  __asm volatile("mov R1,#0x06"); 
  __asm volatile("ASR R12, R8, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
