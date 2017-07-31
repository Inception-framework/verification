#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0"); 
  __asm volatile("add R4,R4,#0x2a"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0xa5"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x0f"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x4e"); 
  __asm volatile("SUB R3, R4, #0x624");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
