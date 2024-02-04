#include "Student.h"
#include "School.h"

int main() {
	Power spell("spell", 10);
	Power curse("curse", 20);
	Power charm("charm", 5);

	School school;

	school.addStudent(Student("Jojo", "1", 100, &spell));
	school.addStudent(Student("Penka", "2", 100, &curse));
	school.addStudent(Student("Misho", "1", 100, &spell));
	school.addStudent(Student("Bruh", "3", 100, &curse));
	school.addStudent(Student("Idk", "3", 100, &charm));

	std::cout << "Students: \n" << school << std::endl;

	/*while (school.getHouseStudentsCount("1") > 0
		&& school.getHouseStudentsCount("3") > 0)
	{
		Student* student1 = nullptr;
		Student* student2 = nullptr;
		while (student1 == nullptr || student2 == nullptr)
		{
			student1 = school.getFirstStudent("1");
			student2 = school.getFirstStudent("2");
		}
	}*/
}