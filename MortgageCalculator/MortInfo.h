#ifndef MORTINFO_h
#define MORTINFO_h

struct MortInfo {
	float interest;
	int principal;
	int term;

	//start date of loan
	int monStart, dayStart, yearStart;
	//end date of loan
	int monEnd, dayEnd, yearEnd;
};


#endif //MORTINFO_h
