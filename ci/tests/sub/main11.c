#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0"); 
  __asm volatile("add R1,R1,#0xfe"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x43"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0xc4"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x9e"); 
  __asm volatile("SUB R1, R1, #0xfa8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
