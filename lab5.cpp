#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>

using namespace std::chrono;
using namespace std;

int main() {
	cout << "Test size: " << 300 << endl;
	int multable2[300][300];
	int multable[300][300];
	int* rowptr[300];
	int* rowptr2[300];
	int** doubleptr;
	int** doubleptr2;
	doubleptr = &rowptr[0];
	doubleptr2 = &rowptr2[0];
	vector<vector<int>> v(300);
	vector<vector<int>> v2(300);
	for (int i = 0; i < 300; i++) {
		rowptr[i] = &multable[i][0];
	}
	for (int i = 0; i < 300; i++) {
		vector<int> current_vector(300);
		v.at(i) = (current_vector);
	}
	int time_total = 0;
	auto start = high_resolution_clock::now();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	for (int k = 0; k < 5; k++) {
		start = high_resolution_clock::now();
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				*(*(doubleptr + i) + j) = i * j;
			}
		}
		stop = high_resolution_clock::now();
		duration = duration_cast<nanoseconds>(stop - start);
		time_total = time_total + duration.count();
	}
	time_total = time_total / 5;
	cout << fixed << "Using double pointers to assign data: " << time_total << " nanoseconds" << endl;

	time_total = 0;
	for (int k = 0; k < 5; k++) {
		start = high_resolution_clock::now();
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				v.at(i).at(j) = (i * j);
			}
		}
		stop = high_resolution_clock::now();
		duration = duration_cast<nanoseconds>(stop - start);
		time_total = time_total + duration.count();
	}
	time_total = time_total / 5;
	cout << fixed << "Using vectors to assign data: " << time_total << " nanoseconds" << endl;

	time_total = 0;
	for (int k = 0; k < 5; k++) {
		start = high_resolution_clock::now();
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				multable2[i][j] = i * j;
			}
		}
		stop = high_resolution_clock::now();
		duration = duration_cast<nanoseconds>(stop - start);
		time_total = time_total + duration.count();
	}
	time_total = time_total / 5;
	cout << fixed << "Using 2D arrays to assign data: " << time_total << " nanoseconds" << endl;

	// Now for the "copying" portion 

	time_total = 0;
	for (int k = 0; k < 5; k++) {
		start = high_resolution_clock::now();
		for (int i = 0; i < 300; i++) {
			rowptr2[i] = rowptr[i];
		}
		stop = high_resolution_clock::now();
		duration = duration_cast<nanoseconds>(stop - start);
		time_total = time_total + duration.count();
	}
	time_total = time_total / 5;
	cout << fixed << "Using double pointers to copy data: " << time_total << " nanoseconds" << endl;

	time_total = 0;
	for (int k = 0; k < 5; k++) {
		start = high_resolution_clock::now();
		for (int i = 0; i < 300; i++) {
			v2.at(i) = v.at(i);
		}
		stop = high_resolution_clock::now();
		duration = duration_cast<nanoseconds>(stop - start);
		time_total = time_total + duration.count();
	}
	time_total = time_total / 5;
	cout << fixed << "Using vectors to copy data: " << time_total << " nanoseconds" << endl;

	time_total = 0;
	for (int k = 0; k < 5; k++) {
		start = high_resolution_clock::now();
		for (int i = 0; i < 300; i++) {
			for (int j = 0; j < 300; j++) {
				multable2[i][j] = multable[i][j];
			}
		}
		stop = high_resolution_clock::now();
		duration = duration_cast<nanoseconds>(stop - start);
		time_total = time_total + duration.count();
	}
	time_total = time_total / 5;
	cout << fixed << "Using 2D arrays to copy data: " << time_total << " nanoseconds" << endl;

	return 0;
}