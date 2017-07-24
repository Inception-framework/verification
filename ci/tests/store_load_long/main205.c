#include <stdlib.h>
int STACK[2050];__attribute__((naked))
void foo(void){
  #ifndef KLEE
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("add r1,r1,#1025");
  __asm volatile("mov r2,sp");
  __asm volatile("loop:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("add r2,#1025");
  __asm volatile("lsl r2,#2");
  __asm volatile("add r2,sp");
  __asm volatile("loop2:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop2");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  #endif
  __asm volatile("mov R5,sp"); 
  __asm volatile("mov R0,#0x62"); 
  __asm volatile("mov R1,#0x2d"); 
  __asm volatile("mov R2,#0x77"); 
  __asm volatile("mov R3,#0x88"); 
  __asm volatile("mov R6,#0xf2"); 
  __asm volatile("mov R7,#0x3a"); 
  __asm volatile("mov R8,#0x31"); 
  __asm volatile("mov R9,#0xc5"); 
  __asm volatile("mov R11,#0x37"); 
  __asm volatile("mov R14,#0xad"); 
  __asm volatile("STRD R7, R8, [R5] ,#-68");
  __asm volatile("mov R0,#0xce"); 
  __asm volatile("mov R1,#0xf8"); 
  __asm volatile("mov R2,#0x0a"); 
  __asm volatile("mov R3,#0xd0"); 
  __asm volatile("mov R6,#0xc2"); 
  __asm volatile("mov R7,#0x84"); 
  __asm volatile("mov R8,#0x20"); 
  __asm volatile("mov R9,#0xc1"); 
  __asm volatile("mov R11,#0x1d"); 
  __asm volatile("mov R14,#0x78"); 
  __asm volatile("LDRD R7, R8, [R5] ,#-68");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
void main(void){
  int i;  for(i=0;i<2050;i++){
      STACK[2050-1-i]=i;
  }
  foo();
}
