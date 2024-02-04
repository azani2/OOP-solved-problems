#include "Power.h"

Power::Power(const std::string& name, int damage) : name(name), damage(damage) {}

bool operator<(const Power& left, const Power& right) {
	return left.damage < right.damage;
}

const std::string& Power::getName() const {
	return name;
}

int Power::getDamage() const {
	return damage;
}