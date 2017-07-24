#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xc4"); 
  __asm volatile("mov R10,#0x12"); 
  __asm volatile("ASR R0, R1, R10");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
