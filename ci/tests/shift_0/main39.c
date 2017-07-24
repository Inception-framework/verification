#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x68"); 
  __asm volatile("ASR R11, R10, 4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
