// Command.cpp

#include "stdafx.h"
#include "Command.h"
using namespace std;

Command::Command(){
	this->type = 0;
	this->op2 = 0;
	this->calc = 0;
}

void Command::print(){
	/*cout << "type " << this->type << endl;
	cout << "op2 " << this->op2 << endl;
	cout << "calc " << this->calc << endl;*/
	for (int i = 0; i < this->size; i++){
		if(time[i] == 2)
			cout << " " << " ";
		else if (time[i] == 3)
			cout << "_" << " ";
		else
			cout << time[i] << " ";
	}
	cout << endl;
}

void Command::printNice(){
	int isZeroUsed = 0;
	/* K - чтение кода операции
	D - дешифрация
	R - обращаемся к регистру
	M - обращаемся к памяти
	_ - такт с "нет операции"
	пробел - пустые отступы для наглядности
	*/
	if (this->op2 == 1){ 
		for (int i = 0; i < this->size; i++){
			if(time[i] == 2 && isZeroUsed == 0)
				cout << " " << " ";
			else if (time[i] == 3)
				cout << "_" << " ";
			else if (time[i] == 1)
				cout << "M" << " ";
			else if (time[i] == 0){
				if (isZeroUsed == 0){
					isZeroUsed = 1;
					cout << "K" << " ";
				}
				else if (isZeroUsed == 1){
					isZeroUsed = 2;
					cout << "D" << " ";
				}
				else if (isZeroUsed == 2){
					isZeroUsed = 3;
					cout << "R" << " ";
				}
				else if (isZeroUsed == 3){
					isZeroUsed = 4;
					cout << "R" << " ";
				}
				else if (isZeroUsed == 4){
					isZeroUsed = 4;
					cout << "C" << " ";
				}
			}
		}
	}
	else{ 
		for (int i = 0; i < this->size; i++){
			if(time[i] == 2 && isZeroUsed == 0)
				cout << " " << " ";
			else if (time[i] == 3)
				cout << "_" << " ";
			else if (time[i] == 1)
				cout << "M" << " ";
			else if (time[i] == 0){
				if (isZeroUsed == 0){
					isZeroUsed = 1;
					cout << "K" << " ";
				}
				else if (isZeroUsed == 1){
					isZeroUsed = 2;
					cout << "D" << " ";
				}
				else if (isZeroUsed == 2){
					isZeroUsed = 3;
					cout << "R" << " ";
				}
				else if (isZeroUsed == 3){
					isZeroUsed = 3;
					cout << "C" << " ";
				}
			}
		}
	}
	
	cout << endl;
}

Command Command::generate(double pReg, double pType1, int memTime, int calcTime){
	Command com;
	if((rand() % 100) < (pReg * 100)){ 
		com.op2 = 1; 
	}
	else
		com.op2 = memTime;
	if((rand() % 100) < (pType1 * 100)){
		com.calc = 1; 
		com.type = 1;
	}
	else{
		com.type = 2;
		com.calc = calcTime;
	}
	return com;
}

int Command::getTime(){
	int time = 0;
	for (int i =0; i < this->size; i++){
		if (this->time[i] != 2){ 
			time++;
		}
	}
	return time;
}

void Command::getTimeMas(){
	vector <int>::iterator it;
	it = this->time.begin();
	this->size = 2 + 1 + this->op2 + this->calc + 1; 
	this->time.insert(it, 0); 
	it = this->time.begin() + 1;
	this->time.insert(it, 0); 
	it = this->time.begin() + 2;
	this->time.insert(it, 0);
	it = this->time.begin() + 3;
	int i = 3;
	if (this->op2 == 1){ 
		this->time.insert(it, 0); 
		it = this->time.begin() + 4;
	}
	else{ 
		while(i < this->op2 + 3){ 
			this->time.insert(it, 1); 
			i++; 
			it = this->time.begin() + i;
		}
	}
	int cnt = 0;
	while(cnt < this->calc){
		this->time.insert(it, 0); 
		i++;
		it = this->time.begin() + i;
		cnt++;
	}
	this->time.push_back(1); 
}

void Command::appendShift(int value){
	for(int i = 0; i < value; i++){
		vector <int>::iterator it;
		it = this->time.begin();
		this->size++;
		//this->time.resize(this->size);
		this->time.insert(it, 2);
	}
}

void Command::appendBack(int value){
	for(int i = 0; i < value; i++){
		this->size++;
		this->time.push_back(2);
	}
}
