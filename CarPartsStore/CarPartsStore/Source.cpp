#include "Car.h"

int main() {
	Piston p1("piston1", "Ivan&Co.", 2010, 1, 2.1);
	Piston p2("piston2", "Ian&Co.", 2011, 1, 2.1);

	Tire t1("front left tire", "gumite na Pesho", 2023, 100, 2, 30);
	Tire t2("front right tire", "gumite na Pesho", 2023, 100, 2, 30);
	Tire t3("back left tire", "gumite na Pesho", 2023, 100, 2, 30);
	Tire t4("back right tire", "gumite na Pesho", 2023, 100, 2, 30);
	FuelTank<std::string> ft1("okayish fuel tank", "Jojo engines", 2020, 50, "benzin");

	Piston pistons[2] = { p1, p2 };
	Engine e1("engine", "Jojo engines", 2021, 200, pistons, 2);

	Car car1;
	car1.setBrand("Debonair Brand");
	car1.setModel("Rose Quartz");
	car1.addPart(e1);
	car1.addPart(t1);
	car1.addPart(t2);
	car1.addPart(t3);
	car1.addPart(t4);
	car1.addPart(ft1);
	car1.displayCarParts();
}