#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0xdd"); 
  __asm volatile("mov R12,#0x0a"); 
  __asm volatile("ASR R11, R12, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
