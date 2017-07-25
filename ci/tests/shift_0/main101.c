#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x67"); 
  __asm volatile("mov R8,#0x0f"); 
  __asm volatile("ASR R10, R10, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
