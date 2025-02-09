#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void Read_from_file();

void User_define();
void main() {
	int c;
	cout << "1.Read from file		2.User define" << endl;
	cout << "please enter your choice: ";	cin >> c;
	switch (c)
	{
	case 1:
		cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n";
		Read_from_file();
		cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n";
		break;
	case 2:
		cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n";
		User_define();
		cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*\n";
		break;
	default:
		cout << "please enter a valid number.....\n";
		break;
	}
}
void Read_from_file() {
	int n1, n2;
	float avail_count_max = 0, avail_count_min = 0;
	ifstream Infile("input.txt");
	Infile >> n1 >> n2;
	vector<float>row(n2, 0);
	vector<vector<float>>allo(n1, row);
	vector<vector<float>>max(n1, row);
	vector<float>avail(n2, 0);
#pragma region Available Matrix
	for (int j = 0; j < n2; j++)
	{
		Infile >> avail[j];
		avail_count_max += avail[j];
	}
#pragma endregion
#pragma region Allocation and Max matrices
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			Infile >> allo[i][j];
		}
		for (int z = 0; z < n2; z++) {
			Infile >> max[i][z];
		}
	}
#pragma endregion
	Infile.close();
#pragma region Need Matrix
	vector<vector<float>>need(n1, row);
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			need[i][j] = max[i][j] - allo[i][j];
		}
	}
#pragma endregion
#pragma region Safe or Unsafe
	vector<int>show;
	vector<int>unsafe;
	vector<bool>flag(n1, 0);
	for (int i = 0; i < n1; i++) {
		flag[i] = true;
	}
	bool v = false;
	do
	{
		avail_count_min = avail_count_max;
		for (int i = 0; i < n1; i++) {
			if (flag[i]) {
				for (int j = 0; j < n2; j++) {
					if (need[i][j] <= avail[j]) {
						v = true;
					}
					else {
						v = false;
					}
				}
				if (v) {
					for (int j = 0; j < n2; j++) {
						avail[j] += allo[i][j];
						avail_count_max += avail[j];
					}
					flag[i] = false;
					show.push_back(i);
				}
			}
		}
	} while (avail_count_max > avail_count_min);
	bool r = true;
	for (int i = 0; i < n1; i++) {
		if (flag[i]) {
			r = false;
			unsafe.push_back(i);
		}
	}
	if (r) {
		cout << "The Safe sequence is: ";
		for (int i = 0; i < (show.size()-1); i++) {
			cout << "P" << show[i] << " --> ";
		}
		cout << "P" << show.back() << endl;
	}
	else {
		cout << "Unsafe state......" << endl;;
		cout << "The problem in these processes: ";
		for (int i = 0; i < (unsafe.size()-1); i++) {
			cout << "P" << unsafe[i] << " , ";
		}
		cout << "P" << unsafe.back() << endl;
	}
#pragma endregion
}
void User_define() {
	int n1, n2;
	cout << "please enter the number of processes: ";
	cin >> n1;
	cout << "please enter the number of resources: ";
	cin >> n2;
	vector<float>row(n2, 0);
	float avail_count_max = 0, avail_count_min = 0;
#pragma region Allocation Matrix
	vector<vector<float>>allo(n1, row);
	for (int i = 0; i < n1; i++) {
		cout << "Please enter the allocation matrix for process number " << i << " : " << endl;
		for (int j = 0; j < n2; j++) {
			cout << "R" << (j + 1) << " : "; cin >> allo[i][j];
		}
	}
#pragma endregion
#pragma region Max Matrix
	vector<vector<float>>max(n1, row);
	for (int i = 0; i < n1; i++) {
		cout << "Please enter the Max matrix for process number " << i << " : " << endl;
		for (int j = 0; j < n2; j++) {
			cout << "R" << (j + 1) << " : "; cin >> max[i][j];
		}
	}
#pragma endregion
#pragma region Need Matrix
	vector<vector<float>>need(n1, row);
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			need[i][j] = max[i][j] - allo[i][j];
		}
	}
#pragma endregion
#pragma region Available Matrix
	vector<float>avail(n2, 0);
	cout << "Please enter the avialable Matrix: " << endl;
	for (int j = 0; j < n2; j++)
	{
		cout << "R" << (j + 1) << " : ";
		cin >> avail[j];
		avail_count_max += avail[j];
	}

#pragma endregion
#pragma region Safe or Unsafe
	vector<int>show;
	vector<int>unsafe;
	vector<bool>flag(n1, 0);
	for (int i = 0; i < n1; i++) {
		flag[i] = true;
	}
	bool v = false;
	do
	{
		avail_count_min = avail_count_max;
		for (int i = 0; i < n1; i++) {
			if (flag[i]) {
				for (int j = 0; j < n2; j++) {
					if (need[i][j] <= avail[j]) {
						v = true;
					}
					else {
						v = false;
					}
				}
				if (v) {
					for (int j = 0; j < n2; j++) {
						avail[j] += allo[i][j];
						avail_count_max += avail[j];
					}
					flag[i] = false;
					show.push_back(i);
				}
			}
		}
	} while (avail_count_max > avail_count_min);
	bool r = true;
	for (int i = 0; i < n1; i++) {
		if (flag[i]) {
			r = false;
			unsafe.push_back(i);
		}
	}
	if (r) {
		cout << "The Safe sequence is: ";
		for (int i = 0; i < (show.size() - 1); i++) {
			cout << "P" << show[i] << " --> ";
		}
		cout << "P" << show.back() << endl;
	}
	else {
		cout << "Unsafe state......" << endl;;
		cout << "The problem in these processes: ";
		for (int i = 0; i < (unsafe.size() - 1); i++) {
			cout << "P" << unsafe[i] << " , ";
		}
		cout << "P" << unsafe.back() << endl;
	}
#pragma endregion
}
