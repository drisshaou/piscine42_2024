
#include <unistd.h>

int main(void){
	int i;
	char a;
	char b;


	i = 1;
	while(i <= 100){
		if (i % 3 == 0)
			write(1, "fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "buzz\n", 5);
		else if ( i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else {
			a = (i / 10) + '0';
			b = (i % 10) + '0';
			if (i > 9)
				write(1, &a, 1);
			write(1, &b, 1);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
