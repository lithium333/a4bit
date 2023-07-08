#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{

std::fstream fi;
if (argc<2) {
	return -1;
}
fi.open(argv[1],std::ios::in);

int8_t pos=0;
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
