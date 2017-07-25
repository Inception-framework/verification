#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0xd2"); 
  __asm volatile("mov R4,#0x19"); 
  __asm volatile("ASR R0, R10, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
