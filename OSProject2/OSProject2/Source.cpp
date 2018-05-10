#include "Process.h"
#include <list>
#include <string>
#include <iostream>

int main() {
	list<string> safe_sequence;

	// Set availablility for each dataset
	int available[4] = { 1, 5, 2, 0 };			//	Dataset 1
//	int available[4] = { 0, 0, 4, 2 };			//	Dataset 2
//	int available[4] = { 1, 5, 2, 0 };			//	Dataset 3

	bool deadlock[5] = { true, true, true, true, true };
	int deadlock_count = 0;
	int threshhold = 5;
	int count = 1;

	Process p0;
	p0.set_process_max(0, 0, 1, 2);				//	Dataset 1
//	p0.set_process_max(4, 0, 1, 2);				//	Dataset 2
//	p0.set_process_max(0, 0, 1, 2);				//	Dataset 3,
	p0.set_proccess_allocation(0, 0, 1, 2);		//	Dataset 1
//	p0.set_proccess_allocation(1, 0, 1, 2);		//	Dataset 2
//	p0.set_proccess_allocation(0, 0, 1, 2);		//	Dataset 3
	p0.set_process_need();

	Process p1;
	p1.set_process_max(1, 7, 5, 0);				//	Dataset 1
//	p1.set_process_max(4, 0, 0, 0);				//	Dataset 2
//	p1.set_process_max(4, 7, 5, 0);				//	Dataset 3,
	p1.set_proccess_allocation(1, 0, 0, 0);		//	Dataset 1
//	p1.set_proccess_allocation(2, 0, 0, 0);		//	Dataset 2
//	p1.set_proccess_allocation(1, 0, 0, 0);		//	Dataset 3
	p1.set_process_need();

	Process p2;
	p2.set_process_max(2, 3, 5, 6);				//	Dataset 1
//	p2.set_process_max(2, 3, 0, 2);				//	Dataset 2
//	p2.set_process_max(2, 3, 5, 6);				//	Dataset 3,
	p2.set_proccess_allocation(1, 3, 5, 4);		//	Dataset 1
//	p2.set_proccess_allocation(1, 3, 0, 0);		//	Dataset 2
//	p2.set_proccess_allocation(1, 3, 5, 4);		//	Dataset 3
	p2.set_process_need();

	Process p3;
	p3.set_process_max(0, 6, 5, 2);				//	Dataset 1
//	p3.set_process_max(1, 3, 5, 2);				//	Dataset 2
//	p3.set_process_max(0, 6, 5, 2);				//	Dataset 3,
	p3.set_proccess_allocation(0, 6, 3, 2);		//	Dataset 1
//	p3.set_proccess_allocation(1, 3, 0, 0);		//	Dataset 2
//	p3.set_proccess_allocation(0, 6, 3, 2);		//	Dataset 3
	p3.set_process_need();

	Process p4;
	p4.set_process_max(0, 6, 5, 6);				//	Dataset 1
//	p4.set_process_max(0, 3, 3, 6);				//	Dataset 2
//	p4.set_process_max(0, 6, 5, 6);				//	Dataset 3,
	p4.set_proccess_allocation(0, 0, 1, 4);		//	Dataset 1
//	p4.set_proccess_allocation(0, 3, 1, 4);		//	Dataset 2
//	p4.set_proccess_allocation(0, 0, 1, 4);		//	Dataset 3
	p4.set_process_need();

	cout << "Dataset 1\n\n";					//	Dataset 1
//	cout << "Dataset 2\n\n";					//	Dataset 2
//	cout << "Dataset 3\n\n";					//	Dataset 3

	while (true) {
		cout << "Pass " << count << ": ";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				if (deadlock[i] == true) {
					if (i == 0) {
						if (available[j] < p0.get_process_need(j)) {
							cout << "P0(F) ";
							deadlock_count += 1;
							break;
						}

						if (j == 3) {
							cout << "P0(T) ";
							for (int k = 0; k < 4; k++) {
								available[k] += p0.get_process_allocation(k);
							}
							safe_sequence.push_back("P0");
							deadlock_count = 0;
							threshhold -= 1;
							deadlock[i] = false;
						}
					}
					else if (i == 1) {
						if (available[j] < p1.get_process_need(j)) {
							cout << "P1(F) ";
							deadlock_count += 1;
							break;
						}

						if (j == 3) {
							cout << "P1(T) ";
							for (int k = 0; k < 4; k++) {
								available[k] += p1.get_process_allocation(k);
							}
							safe_sequence.push_back("P1");
							deadlock_count = 0;
							threshhold -= 1;
							deadlock[i] = false;
						}
					}
					else if (i == 2) {
						if (available[j] < p2.get_process_need(j)) {
							cout << "P2(F) ";
							deadlock_count += 1;
							break;
						}

						if (j == 3) {
							cout << "P2(T) ";
							for (int k = 0; k < 4; k++) {
								available[k] += p2.get_process_allocation(k);
							}
							safe_sequence.push_back("P2");
							deadlock_count = 0;
							threshhold -= 1;
							deadlock[i] = false;
						}
					}
					else if (i == 3) {
						if (available[j] < p3.get_process_need(j)) {
							cout << "P3(F) ";
							deadlock_count += 1;
							break;
						}

						if (j == 3) {
							cout << "P3(T) ";
							for (int k = 0; k < 4; k++) {
								available[k] += p3.get_process_allocation(k);
							}
							safe_sequence.push_back("P3");
							deadlock_count = 0;
							threshhold -= 1;
							deadlock[i] = false;
						}
					}
					else if (i == 4) {
						if (available[j] < p4.get_process_need(j)) {
							cout << "P4(F) ";
							deadlock_count += 1;
							break;
						}

						if (j == 3) {
							cout << "P4(T) ";
							for (int k = 0; k < 4; k++) {
								available[k] += p4.get_process_allocation(k);
							}
							safe_sequence.push_back("P4");
							deadlock_count = 0;
							threshhold -= 1;
							deadlock[i] = false;
						}
					}
				}
			}
		}
		cout << endl;
		count += 1;

		if (deadlock[0] == false && deadlock[1] == false && deadlock[2] == false && deadlock[3] == false && deadlock[4] == false) {
			cout << "All sequences passed.\n\n";
			int	available[4] = { 1, 5, 2, 0 };		// Dataset 1
//			int available[4] = { 0, 0, 4, 2 };		// Dataset 2
//			int available[4] = { 1, 5, 2, 0 };		// Dataset 3
			list<string>::iterator it;

			cout << "Safe sequence:  ";
			for (it = safe_sequence.begin(); it != safe_sequence.end(); it++) {
				if (*it == "P0") {
					for (int i = 0; i < 4; i++) {
						available[i] += p0.get_process_allocation(i);
					}
					cout << "P0(T) ";
				}
				else if (*it == "P1") {
					for (int i = 0; i < 4; i++) {
						available[i] += p1.get_process_allocation(i);
					}
					cout << "P1(T) ";
				}
				else if (*it == "P2") {
					for (int i = 0; i < 4; i++) {
						available[i] += p2.get_process_allocation(i);
					}
					cout << "P2(T) ";
				}
				else if (*it == "P3") {
					for (int i = 0; i < 4; i++) {
						available[i] += p3.get_process_allocation(i);
					}
					cout << "P3(T) ";
				}
				else if (*it == "P4") {
					for (int i = 0; i < 4; i++) {
						available[i] += p4.get_process_allocation(i);
					}
					cout << "P4(T) ";
				}
			}
			cout << "\nAvailability:  ";

			for (int i = 0; i < 4; i++) {
				cout << available[i] << " ";
			}

			cout << "\n\nEnd of Safe Sequence\n\n";

			break;
		}
		else if (threshhold != 0 && deadlock_count == threshhold) {
			cout << "No safe sequence has been found.\n\n";

			list<string>::iterator it;
			cout << "Sequence(s) that passed: ";
			for (it = safe_sequence.begin(); it != safe_sequence.end(); it++) {
				cout << *it << " -> ";
			}
			cout << "End of sequences\n\n";

			break;
		}
	}

	cin.ignore();

	return 0;
}