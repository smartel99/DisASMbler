#include <avr/io.h>

void Delay()
{
	long counter = 0;
	while (counter++ < $$com.sysprogs.avr.ledblink.DELAYCYCLES$$)
		asm("nop");
}

void MainLoop()
{
	DDR$$com.sysprogs.avr.ledblink.LEDPORT$$ |= (1 << $$com.sysprogs.avr.ledblink.LEDBIT$$);
	
	for (;;)
	{
		PORT$$com.sysprogs.avr.ledblink.LEDPORT$$ |= (1 << $$com.sysprogs.avr.ledblink.LEDBIT$$);
		Delay();
		PORT$$com.sysprogs.avr.ledblink.LEDPORT$$ &= ~(1 << $$com.sysprogs.avr.ledblink.LEDBIT$$);
		Delay();
	}
}

int main()
{
	MainLoop();
}