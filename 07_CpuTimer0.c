#define GpioDataRegs.GPASET.all NUM

interrupt void  TINT0_ISR(void)      // CPU-Timer0中断函数
{
    CpuTimer0.InterruptCount++;
    NUM=0x0020;
	int right(int NUM){
		for(int CpuTimer0.InterruptCount=0;CpuTimer0.InterruptCount<5;CpuTimer0.InterruptCount++){
			NUM=NUM>>1;
		}
		CpuTimer0.InterruptCount=0；
		return NUM;	

	}
	int left(int NUM){
		for(int CpuTimer0.InterruptCount=0;CpuTimer0.InterruptCount<5;CpuTimer0.InterruptCount++){
			NUM=NUM<<1;  
		}
		CpuTimer0.InterruptCount=0；
		return NUM;
	}
	while(1){
		int NUM=0x0020;	    
		int a=right(NUM);
		left(a);
	}


   CpuTimer0Regs.TCR.bit.TIF=1;  //清除定时器中断标志位
   PieCtrl.PIEACK.bit.ACK1=1;    //响应同组其他中断
   EINT;  //开全局中断
}