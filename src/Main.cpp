#include <iostream>
#include "Render.h"

using namespace std;

int main(int argc, char *argv[]) {
	try{
		Render r;
		r.run();
	}catch(int e){
		return e;
	}
	return 0;
}
