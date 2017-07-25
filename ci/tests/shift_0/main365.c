#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x92"); 
  __asm volatile("mov R0,#0x01"); 
  __asm volatile("ASR R2, R8, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
