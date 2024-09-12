The purpose of this project is to exercise the Neon functions on a Cortex-A57 
CPU available on a NVIDIA Jetson Nano.

Requieres:
	This project is implemented on Arm Cortex-A57, you can use this on any
Arm Cortex Av8 cpu, but you will need to specify it in the cmake options
	gcc version 7.5.0 
	
Build a part of each lab:

	```bash
		cmake -DCPU=Arm Cortex-A57 -Bbuild
		cmake --build build
	```

