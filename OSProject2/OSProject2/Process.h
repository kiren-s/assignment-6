#ifndef _PROCESS_H
#define _PROCESS_H

using namespace std;

class Process {
private:
	int process_max[4];
	int process_allocation[4];
	int process_need[4];
public:
	Process();
	void set_process_max(int, int, int, int);
	void set_proccess_allocation(int, int, int, int);
	void set_process_need();
	int get_process_need(int);
	int get_process_allocation(int);
};

#endif