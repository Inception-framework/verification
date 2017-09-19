__attribute__((naked))
void main(void){
  __asm volatile("mov r0,r0");
  __asm volatile("bge ret2");
  __asm volatile("bge ret3");
  __asm volatile("mov r0,#1");
  __asm volatile("bx lr");
  __asm volatile("ret2: mov r0,#2");
  __asm volatile("bx lr");
  __asm volatile("ret3: mov r0,#3");
  __asm volatile("bge ret4");
  __asm volatile("bx lr");
  __asm volatile("mov r0,#4");
  __asm volatile("ret4: bx lr");
}
