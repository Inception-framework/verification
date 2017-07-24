#include <stdlib.h>
int STACK[2050];__attribute__((naked))
void foo(void){
  __asm volatile("mov R1,#0x47"); 
  __asm volatile("mov R2,#0x80"); 
  __asm volatile("mov R3,#0x9e"); 
  __asm volatile("mov R4,#0x25"); 
  __asm volatile("mov R5,#0xf1"); 
  __asm volatile("mov R6,#0xb5"); 
  __asm volatile("mov R7,#0xa1"); 
  __asm volatile("mov R8,#0xf4"); 
  __asm volatile("mov R9,#0x85"); 
  __asm volatile("mov R12,#0x07"); 
  __asm volatile("mov R14,#0xcc"); 
  __asm volatile("STRB R12, [SP] ,#-36");
  __asm volatile("mov R1,#0x30"); 
  __asm volatile("mov R2,#0x4b"); 
  __asm volatile("mov R3,#0x32"); 
  __asm volatile("mov R4,#0xa9"); 
  __asm volatile("mov R5,#0x33"); 
  __asm volatile("mov R6,#0xde"); 
  __asm volatile("mov R7,#0x68"); 
  __asm volatile("mov R8,#0xe2"); 
  __asm volatile("mov R9,#0x1f"); 
  __asm volatile("mov R12,#0x2f"); 
  __asm volatile("mov R14,#0x00"); 
  __asm volatile("LDRB R12, [SP] ,#-36");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
void main(void){
  foo();
}
