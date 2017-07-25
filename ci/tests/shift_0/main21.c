#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xc8"); 
  __asm volatile("mov R11,#0x12"); 
  __asm volatile("ASR R1, R11, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
