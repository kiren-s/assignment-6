#include "Process.h"

Process::Process() {
	for (int i = 0; i < 4; i++) {
		process_max[i] = 0;
		process_allocation[i] = 0;
		process_need[i] = 0;
	}
}

void Process::set_process_max(int a, int b, int c, int d) {
	process_max[0] = a;
	process_max[1] = b;
	process_max[2] = c;
	process_max[3] = d;
}

void Process::set_proccess_allocation(int a, int b, int c, int d) {
	process_allocation[0] = a;
	process_allocation[1] = b;
	process_allocation[2] = c;
	process_allocation[3] = d;
}

void Process::set_process_need() {
	for (int i = 0; i < 4; i++) {
		process_need[i] = process_max[i] - process_allocation[i];
	}
}

int Process::get_process_need(int need) {
	return process_need[need];
}

int Process::get_process_allocation(int alloc) {
	return process_allocation[alloc];
}