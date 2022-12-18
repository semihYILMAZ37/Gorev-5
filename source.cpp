#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
std::ifstream bfile("b.txt");
int count = 0;
for (std::string line; std::getline(bfile, line); ) 
{
    count++;
}
bfile.clear();
bfile.seekg(0, std::ios::beg);

std::vector<std::string> bvector;
for (std::string line; std::getline(bfile, line); ) 
{
    bvector.push_back(line);
}

std::cout << "--- B ----\n"; 

for (std::vector<std::string>::iterator it = bvector.begin(); it != bvector.end(); ++it) {
	std::cout << *it << std::endl;
}
//std::cout << "----------\n"; 

std::ifstream afile("a.txt");
std::vector<std::string> dummyvector;
std::vector< std::vector< std::string> > matrix;
std::string line;
for (int i =0;i<count;i++  ) {
	dummyvector.clear();
	std::getline(afile, line);
	for (int j =0;j<count;j++  ) {
		dummyvector.push_back(line.substr(2*j,1));
		//std::cout << "i: " << i << " j: " << j  << " element: " << line.substr(2*j,1) <<std::endl;	
	}
	matrix.push_back(dummyvector);
}
std::cout << "--- A ----\n"; 
for (std::vector< std::vector< std::string> >::iterator it = matrix.begin(); it != matrix.end(); ++it) {
	dummyvector = *it;
	for (std::vector<std::string>::iterator it2 = dummyvector.begin(); it2 != dummyvector.end(); ++it2) {
		std::cout << *it2 << " ";
	}
	std::cout << "\n";
}

return 0;
}
