#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x47"); 
  __asm volatile("mov R3,#0x80"); 
  __asm volatile("mov R4,#0x9e"); 
  __asm volatile("mov R5,#0x25"); 
  __asm volatile("mov R6,#0xf1"); 
  __asm volatile("mov R7,#0xb5"); 
  __asm volatile("mov R8,#0xa1"); 
  __asm volatile("mov R9,#0xf4"); 
  __asm volatile("mov R12,#0x85"); 
  __asm volatile("mov R14,#0x07"); 
  __asm volatile("STR R12, [SP]");
  __asm volatile("mov R2,#0x30"); 
  __asm volatile("mov R3,#0x4b"); 
  __asm volatile("mov R4,#0x32"); 
  __asm volatile("mov R5,#0xa9"); 
  __asm volatile("mov R6,#0x33"); 
  __asm volatile("mov R7,#0xde"); 
  __asm volatile("mov R8,#0x68"); 
  __asm volatile("mov R9,#0xe2"); 
  __asm volatile("mov R12,#0x1f"); 
  __asm volatile("mov R14,#0x2f"); 
  __asm volatile("LDR R12, [SP]");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
