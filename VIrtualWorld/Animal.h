#pragma once

#include "World.h"
#include <typeinfo>

template <typename T>
class Animal : public Organism {
	public :
		Animal(int s, int i, int a, char ch, World* w) : Organism(s, i, a, ch, w) {}

		void virtual Action() override {
			Point newP = Navigation::Translate(location);

			if (world->PointValidate(newP) == false) {
				return;
			}

			Move(newP);
		}
		bool virtual Collision(Organism* o) override {

			if (TypeCheck(o)) {
				Point p = world->SeekForFree(location);

				if (p == NULL_POINT) {
					return false;
				}

				Organism* org = (Organism*)(new T(world->GetAge(), world));
				world->AddToWorld(org, p);

				return false;
			}

			return true;
		}

		bool IsAnimal() override {
			return true;
		}

		void Move(Point p) override {
			Organism* o = world->MoveTo(p, this);

			if (o == nullptr) {
				return;
			}

			if (o->Collision(this) == true) {
				if (this->Collision(o) == true) {
					Fight(o);
				}
			}
		}
		void Kill(std::string s) override {
			Organism::Kill(this->ToString() + " has been slain by " + s);
		}
	protected:
		bool TypeCheck(Organism* o) {

			Organism& base = *this;
			Organism& other = *o;

			if (typeid(this).name() == typeid(o).name())
				return true;

			return false;
		}
	private :
};