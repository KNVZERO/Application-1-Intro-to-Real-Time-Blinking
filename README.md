# Application-1-Intro-to-Real-Time-Blinking
Application 1: Intro to Real-Time Blinking (Tasks and Setup)

# Q1. Vary Priorities:

When the delay within the print task is increased, the LED is slightly delayed, but is about the same.

When the number of characters printed increases, it still seems approximately the same.

# Q2. Increase Load:

The print task outputs constantly and the LED blinks every few seconds, rather than 250 ms. 

# Q3. Thematic Customization:

It is important to explain what each messages mean so anyone can know what it means. This system 
benefits from having correct functionality as predictable times because the system is sequential. 
One mistake causes future results to be off time. 

# Q4:

1. I measured the periods by creating a variable that measured the tick amount. It would print 
the tick amount everytime the LED blinked and the message printed. 

2. The LED blink task period is approximately 250.

3. The Print task period is approximately 10000.

# Q5:

The timing requirements were met. It was measured using the tick counter and the internal clock 
was referenced. 

# Q6: 

In the single loop, the LED timing and print message are very incorrect. It toggles, delays for 10000
ms, then prints the toggle message. Removing the 10000 ms in the longprint function fixes the LED
timing. 

# Q7:

By using multitasking, timing determinism was achieved for the LED blink. The LED blinks and message
prints predictably. 
