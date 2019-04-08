#pragma once

#include "World.h"

template <typename T>
class Plant : public Organism {
	public:
		Plant(int s, int a, char ch, World* w) : Organism(s, 0, a, ch, w) {}

		void virtual Action() override {
			Point p = world->SeekForFree(location);

			if (p == NULL_POINT) {
				return;
			}

			Organism* org = (Organism*)(new T(world->GetAge(), world));
			world->AddToWorld(org);
		}
		bool virtual Collision(Organism* o) override {
			this->Kill(o->ToString());

			return false;
		}
		void Move(Point p) override {}
		void Kill(std::string s) override {
			Organism::Kill(this->ToString() + " has been eaten by " + s);
		}

		bool IsAnimal() override {
			return false;
		}
	private:
};