#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x83"); 
  __asm volatile("mov R11,#0x0d"); 
  __asm volatile("ASR R10, R10, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
