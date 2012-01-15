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
	P& operator [](unsigned int Id) {
		return List[Id];
	}
	void clear() {
		List.clear();
	}

	int GetId(P Entry);

	void Push(P Entry);
	void Remove(int Id);
	void Remove(P Entry);

	static PtrList<P>& join(PtrList<P>& List1, PtrList<P>& List2);
};

template<class P> int PtrList<P>::GetId(P Entry) {
	for (unsigned int i = 0; i < List.size(); i++)
		if (List[i] == Entry)
			return i;
	return -1;
}

template<class P> void PtrList<P>::Push(P Entry) {
	for (unsigned int i = 0; i < List.size(); i++) {
		if (List[i] == NULL) {
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
	if (Id < 0 && List[Id]) {
		delete List[Id];
		List[Id] = NULL;
	}
}

template<class P> PtrList<P>& PtrList<P>::join(PtrList<P>& List1, PtrList<P>& List2)
{
	PtrList<P>* pLongest;
	PtrList<P>* pShortest;

	if(List1.size() < List2.size()) {
		pLongest = &List2;
		pShortest = &List1;
	} else {
		pLongest = &List1;
		pShortest = &List2;
	}

	pLongest->List.insert(pLongest->List.end(), pShortest->List.begin(), pShortest->List.end());

	return (*pLongest);
}
