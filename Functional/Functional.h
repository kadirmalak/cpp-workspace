#pragma once

#include <memory>
#include <algorithm>
using namespace std;

namespace kadir {

	template <typename Coll, typename UnOp>
	void ffor_each(Coll coll, UnOp op) {
		for_each(coll.begin(), coll.end(), op);
	}

	template <typename Coll, typename UnOp>
	auto ffilter(Coll coll, UnOp op) {
		auto filtered = make_shared<Coll>(coll.size());
		auto it = copy_if(coll.begin(), coll.end(), filtered->begin(), op);
		filtered->resize(distance(filtered->begin(), it));
		return filtered;
	}

	template <typename Coll, typename UnOp>
	auto fmap(Coll coll, UnOp op) {
		auto target = make_shared<Coll>();
		target->resize(coll.size());
		transform(coll.begin(), coll.end(), target->begin(), op);
		return target;
	}

	template <typename T>
	void println(T t) {
		cout << t << endl;
	}
}
