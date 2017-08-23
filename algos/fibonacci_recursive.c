__attribute__((naked))
int fibonacci(int n){
  __asm volatile("push	{r4, r7, r8}");
  __asm volatile("sub	sp, #12");
  __asm volatile("add	r7, sp, #0");
  __asm volatile("str	r0, [r7, #4]");
  __asm volatile("ldr	r3, [r7, #4]");
  __asm volatile("cmp	r3, #3");
  __asm volatile("bhs	continue");
  __asm volatile("movs	r3, #1");
  __asm volatile("b.n	stop");
  __asm volatile("continue:");
  __asm volatile("ldr	r3, [r7, #4]");
  __asm volatile("subs	r3, #1");
  __asm volatile("mov	r0, r3");
  __asm volatile("bl	fibonacci");
  __asm volatile("mov	r4, r0");
  __asm volatile("ldr	r3, [r7, #4]");
  __asm volatile("subs	r3, #2");
  __asm volatile("mov	r0, r3");
  __asm volatile("bl	fibonacci");
  __asm volatile("mov	r3, r0");
  __asm volatile("add	r3, r4");
  __asm volatile("stop:");
  __asm volatile("mov	r0, r3");
  __asm volatile("adds	r7, #12");
  __asm volatile("mov	sp, r7");
  __asm volatile("pop	{r4, r7, pc}");
}

int fibonacci_golden(int n){
  if(n <= 2) return 1;
  return fibonacci(n-1)+fibonacci(n-2);
}

void main(void){
  int x,y,y_golden;
  x = 6;
  y = fibonacci(x);
  y_golden = fibonacci_golden(x);
  #ifndef NOPRINT
  printf("fibonacci(%d) = %d\n",x,y);
  printf("fibonacci_golden(%d) = %d\n",x,y_golden);
  if(y != y_golden){
    printf("error!! y != y_golden\n");
  }else{
    printf("ok!! y == y_golden\n");
  }
  #endif
}
