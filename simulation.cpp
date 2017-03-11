//gunakan compiler dengan -std=c++11 untuk #include <random>

#include <iostream>
#include <fstream>
#include <stdlib.h> /* srand, rand */
#include <time.h> /* time */
using namespace std;

struct cd {
	string c;
	int d;
};

cd s[16];

int main () {
	//default_random_engine generator;
	//uniform_int_distribution<int> distribution(0,15);
	
	//auto rng = bind(distribution, generator);
	
	/* initialize random seed: */
  	srand (time(NULL));
	
	int n = 32500; //normal N
	cd s[16];
	
	s[0].c = "0000"; s[0].d = 500;
	s[1].c = "0001"; s[1].d = 400;
	s[2].c = "0010"; s[2].d = 300;
	s[3].c = "0011"; s[3].d = 200;
	s[4].c = "0100"; s[4].d = 100;
	s[5].c = "0101"; s[5].d = 100;
	s[6].c = "0110"; s[6].d = 200;
	s[7].c = "0111"; s[7].d = 250;
	s[8].c = "1000"; s[8].d = 300;
	s[9].c = "1001"; s[9].d = 350;
	s[10].c = "1010"; s[10].d = 300;
	s[11].c = "1011"; s[11].d = 250;
	s[12].c = "1100"; s[12].d = 200;
	s[13].c = "1101"; s[13].d = 150;
	s[14].c = "1110"; s[14].d = 100;
	s[15].c = "1111"; s[15].d = 500;
	
	int r = 0; //100x
	while (r<101) {
		int rr = rand() % 16;
		int critical = rand()%5;
		//int rr = rng();
		if (critical > 0) {
			n -= s[rr].d*(1/critical);
		}
		n -= s[rr].d;
		r++;
	}	
	
	if (n<=0){
		cout<<"N dead";
	}
	else {
		cout<<"N survived, HP = "<<n<<endl;
	}
	
	return 0;
}
