#ifndef COURSESET_H
#define COURSESET_H

#include <iostream>
#include <string>
#include "courseSet.h"
#include "course.h"

using namespace std;

class courseSet{

	private:
		course list[30];

		int listNum = 0;

	public:
		courseSet();

		~courseSet();

		course getCourseSet(int num);

		void setCourseSet();
};

#endif
