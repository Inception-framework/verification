#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0"); 
  __asm volatile("add R1,R1,#0x62"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x88"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0xe1"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0xa5"); 
  __asm volatile("SUB R7, R1, #0x7bf");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
