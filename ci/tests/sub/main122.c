#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0"); 
  __asm volatile("add R12,R12,#0x34"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x21"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xbe"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xaf"); 
  __asm volatile("SUB R7, R12, #0x00f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
