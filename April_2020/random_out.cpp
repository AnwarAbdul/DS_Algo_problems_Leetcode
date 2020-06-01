#include <iostream>
#include <ctime>
#include <vector>
#include <fstream>

int main(){
	
	int n = 20;
	int num;
	srand(time(NULL));
	std::vector<std::vector<int>> a;
	int j,i;
	std::vector<int> row;
	for(i = 0; i < n; i++){
		row.clear();
		for(j = 0; j < n; j++){
			num = rand() % (2) + 0;
			row.push_back(num);
		}
		a.push_back(row);
	}
	std::ofstream outf("out.txt");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			outf<<a[i][j]<<",";
		}
		outf<<"\n";
	}
	return 0;
}
