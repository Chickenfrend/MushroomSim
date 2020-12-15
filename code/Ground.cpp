#include "Ground.hpp"

Ground::Ground(float _density, float _moisture, float _drainageRate, std::unique_ptr<TreeRoot> r, std::unique_ptr<TreeTrunk> t, std::unique_ptr<Mushroom> m){
	density = _density;
	moisture = _moisture;
	drainageRate = _drainageRate;
	root = std::move(r);
	trunk = std::move(t);
	mushroom = std::move(m);
}
