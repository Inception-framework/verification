#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0x37"); 
  __asm volatile("mov R9,#0x02"); 
  __asm volatile("ASR R10, R7, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
