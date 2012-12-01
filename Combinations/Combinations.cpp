// Combinations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

long nCombs(int N, int k);
void shiftInd(long * indV,long shiftIndex, long nMiss, long nFreq, bool * maxFlag);

int _tmain(int argc, _TCHAR* argv[])
{
	while(true){
		int N,k, Npk;
		cout<<"Number of frequencies: ";
		cin>>N;
		cout<<"Number of missing peaks: ";
		cin>>k;
		Npk = N+k;

		long * freqVec = new long[Npk];
		long * misInd = new long[k];
		bool * flag = new bool;
		*flag = false;

		long combs = nCombs(N,k);
		cout<<"Combinations: "<<combs<<endl;

		for(int i = 0; i < k; i++){
			misInd[i] = i;
		}

		for(int i = 0; i < combs; i ++){
			for(int j = 0; j < k; j++){
				cout<<misInd[j]<<" ";
			}
			cout<<endl;
			shiftInd(misInd, k-1, k, N, flag);
		}

		delete[] freqVec;
		delete[] misInd;
		delete flag;
	}


	return 0;
}


void shiftInd(long * indV,long shiftIndex, long nMiss, long nFreq, bool * maxFlag){
 
	if((shiftIndex == 0)&& (indV[shiftIndex] == nFreq - (nMiss - shiftIndex))){
		return;
	}	

	if(indV[shiftIndex] == nFreq -(nMiss - shiftIndex)){
		*maxFlag = true;
		shiftInd(indV, shiftIndex - 1, nMiss, nFreq, maxFlag);
	}
	
	else{
	*maxFlag = false;
	
	indV[shiftIndex]++;

	for(int i = shiftIndex +1; i < nMiss; i ++){
		indV[i] = indV[shiftIndex]+(i-shiftIndex );
	}

	return;
	}
}



long nCombs(int N, int k){

	long result = (long) N;
	long kfac = (long) k;

	if(N == 0){
		return 0;
	}
	if(k == 0){
		return 1;
	}

	for(int i = N-1; i > (N-k); i--){
		result *= i;
	}
	for(int i = k-1; i >0; i--){
		kfac *= i;
	}

	result /= kfac;

	return result;
}