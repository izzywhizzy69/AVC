#include <stdio.h>
#include <time.h>
#include "E101.h"
int main() {
	init(0);
	set_motors(3, 48);
	 set_motors(5, 48);
	 hardware_exchange();
	 return 0;
}
