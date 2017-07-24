#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xc3"); 
  __asm volatile("mov R8,#0x03"); 
  __asm volatile("ASR R5, R8, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
