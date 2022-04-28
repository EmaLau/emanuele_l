#include <iostream>
#include <string.h>
#include "conversione.h"

using namespace std;
	
string conversione(int a){
	string b = "";
	int n;
	while(n>0){
		if(n%2==0)
			b='0'+b;
		else
			b='1'+b;
		n=n/2;
	}
	return b;
}
