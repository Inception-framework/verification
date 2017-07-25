#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0xbe"); 
  __asm volatile("mov R8,#0x19"); 
  __asm volatile("ASR R10, R7, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
