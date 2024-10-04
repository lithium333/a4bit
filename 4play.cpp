#include <iostream>
#include <fstream>
#include <cstdint>

int main(int argc, char* argv[]) {

std::fstream fi;
if (argc<2)
	return -1;
fi.open(argv[1],std::ios::in);

uint8_t cur,decoded;

while(fi.read((char*)&cur,1)) {
	decoded=(cur/16)<<4;
	std::cout << *((char*)&decoded);
	decoded=(cur%16)<<4;
	std::cout << *((char*)&decoded);
}
fi.close();

return 0;
}
