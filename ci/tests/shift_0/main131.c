#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xf8"); 
  __asm volatile("mov R4,#0x02"); 
  __asm volatile("ASR R0, R0, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
