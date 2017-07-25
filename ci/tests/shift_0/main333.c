#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xce"); 
  __asm volatile("mov R4,#0x04"); 
  __asm volatile("ASR R9, R2, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
