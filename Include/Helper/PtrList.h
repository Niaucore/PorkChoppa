/*
 * PtrList.h
 *
 *  Created on: 21.12.2011
 *      Author: 06hofmann-sebas
 */

#pragma once /* PTRLIST_H_ */

#include <vector>

template<class P> class PtrList {
private:
	std::vector<P> List;

public:
	PtrList() { List.clear(); }

	size_t size() {
		return List.size();
	}
	P operator [](unsigned int Id) {
		return List[Id];
	}
	void clear() {
		List.clear();
	}

	int GetId(P Entry);

	void Push(P Entry);
	void Remove(int Id);
	void Remove(P Entry);
};

template<class P> int PtrList<P>::GetId(P Entry) {
	for (unsigned int i = 0; i < List.size(); i++)
		if (List[i] == Entry)
			return i;
	return -1;
}

template<class P> void PtrList<P>::Push(P Entry) {
	for (unsigned int i = 0; i < List.size(); i++) {
		if (List[i] != NULL) {
			List[i] = Entry;
			return;
		}
	}
	List.push_back(Entry);
}

template<class P> void PtrList<P>::Remove(P Entry) {
	int Id = GetId(Entry);
	Remove(Id);
}

template<class P> void PtrList<P>::Remove(int Id) {
	if (Id < 0) {
		delete List[Id];
		List[Id] = NULL;
	}
}
