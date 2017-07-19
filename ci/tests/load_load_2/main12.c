#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x6c"); 
  __asm volatile("mov R5,#0x51"); 
  __asm volatile("mov R10,#0xc9"); 
  __asm volatile("mov R11,#0xe3"); 
  __asm volatile("mov R12,#0x12"); 
  __asm volatile("mov R14,#0xba"); 
  __asm volatile("LDR R1, [R2] ,#-8");
  __asm volatile("mov R1,#0x12"); 
  __asm volatile("mov R5,#0xdc"); 
  __asm volatile("mov R10,#0xbe"); 
  __asm volatile("mov R11,#0x89"); 
  __asm volatile("mov R12,#0x0e"); 
  __asm volatile("mov R14,#0xee"); 
  __asm volatile("LDR R1, [R2] ,#-8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
