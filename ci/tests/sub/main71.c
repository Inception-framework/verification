#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0x25"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x77"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x7c"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xf0"); 
  __asm volatile("SUB R3, R10, #0x655");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
