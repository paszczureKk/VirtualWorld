#pragma once

#include "World.h"
#include "Utilities.h"

#include <string>
#include <iostream>

template <typename T>
class Plant : public Organism {
	public:
		Plant(int s, int a, char ch, World* w, float p) : Organism(s, 0, a, ch, w) {
			probability = p;
		}

		void virtual Action() override {

			if (probability < Utilities::random(0.0f, 1.0f)) {
				return;
			}

			Point p = world->SeekForFree(location);

			if (p == NULL_POINT) {
				return;
			}

			Organism* org = (Organism*)(new T(world->GetAge(), world));
			world->AddToWorld(org, p);

			world->Notify(this->ToString() + " has grown on " + p.ToString());
		}
		bool virtual Collision(Organism* o) override {
			this->Kill(o->ToString());

			o->Move(this->GetLocation());

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
		float probability;
};