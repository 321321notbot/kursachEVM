// main.cpp

#include "stdafx.h"
#include "command.h"
using namespace std;

int main(){
	
	double pReg, pType1;
	int memTime, calcTime, num;
	cout << "vvod veroyatnosti togo,chto vtoroy operand nahoditsya v registre" << endl;
	cout << "0.9 0.8 0.6 " << endl;
	cin >> pReg;
	cout << "vvedite veroyatnost togo,chto komanda imeet 1 type" << endl;
	cout << "0.9 0.7 0.5 " << endl;
	cin >> pType1;
	cout << "vvedite kol-vo taktov dlya obrashenia v pamyat'" << endl;
	cout << "2 5 10 " << endl;
	cin >> memTime;
	cout << "vvedite kol-vo taktov dlya vichislenia rezultata dlya komand 2 type" << endl;
	cout << "4 8 16 " << endl;
	cin >> calcTime;
	cout << "vvedite kol-vo komand" << endl;
	cin >> num;

	
	Command *list;
	list = new Command[num];
	for(int i = 0; i < num; i++){
	
		Command bufcom;
		bufcom = bufcom.generate(pReg, pType1, memTime, calcTime);
		bufcom.getTimeMas();
		bufcom.appendShift(i);
		list[i] = bufcom;
	}
	 
	int maxsize = 0;
	for(int i = 0; i < num; i++){
		if (list[i].size > maxsize)
			maxsize = list[i].size;
	}

	
	for(int i = 0; i < num; i++){
		int val = maxsize - list[i].size;
		list[i].appendBack(val);
	}

	int isOneHere; 
	for(int i =0; i < maxsize; i++){
		isOneHere = 0;
		for(int j = 0; j < num; j++){
			if (list[j].time[i] == 1){ 
				if (isOneHere == 0){
					isOneHere = 1;
					continue;
				}
				if (isOneHere == 1){ 
					isOneHere = 2;
					continue;
				}
				if (isOneHere == 2){ 
					vector <int>::iterator start1;
					for (int k =0; k<list[j].time.size(); k++){
						if(list[j].time[k] == 1){
							start1 = list[j].time.begin() + k;
							break;
						}
					}
					list[j].size++;
					maxsize++;
					list[j].time.insert(start1, 3); 
					for(int r = 0; r < num; r++){ 
						if(r != j)
							list[r].size++;
							list[r].time.push_back(2);
					}
					
					for (int k =0; k<list[j].time.size(); k++){
						if(list[j].time[k] == 1){
							start1 = list[j].time.begin() + k;
							break;
						}
					}
					int bufi = i ;
				
					while(list[j].time[bufi] == 1){
						list[j].size++;
						list[j].time.insert(start1, 3); 
						/*for(int r = 0; r < num; r++){
							if(r != j)
								list[r].size++;
								list[r].time.push_back(2);
						}*/
						for (int k =0; k<list[j].time.size(); k++){
							if(list[j].time[k] == 1){
								start1 = list[j].time.begin() + k;
								break;
							}
						}
						//bufi--;
					}
				}
			}
		}
	}

	
	int sum = 0, buftime;
	for(int i = 0; i < num; i++){
		buftime = list[i].getTime();
		sum += buftime;
	}
	int avtime = 0;
	avtime = sum / num; 

	for(int i = 0; i < num; i++){
		list[i].printNice();
	}
	cout << endl << "srendee vremya: " << avtime << endl;

	delete []list;
	system("pause");
	return 0;
}
