#include "WorkingTrainee.h"
#include "EmployeeCollection.h"

int main() {
	size_t projects[4] = {1, 2, 3, 6};
	Worker w1("pesho", 20, 1000, 23, projects, 4);
	Trainee t1("tisho", 18, 400, 2);
	WorkingTrainee wt1("nana", 19, 800, 3, projects, 4, 6);
	EmployeeCollection coll1;
	coll1.addWorker(w1);
	coll1.addTrainee(t1);
	coll1.addWorkingTrainee(wt1);

	coll1.printEmployees();
}