//Addanki Adithya
#ifndef NEIGHBOR_HPP
#define NEIGHBOR_HPP

#include <stdexcept>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "point.hpp"
#include "strcls.hpp"
#include "binstr.hpp"
#include "concepts.hpp"
#include <math.h>
#include <vector>

using namespace std;

template<typename T, typename U,typename I, typename Op>
requires Iterator<I>() and Readable<I>()  and Regular<T>() and Binary_operation<Op,U>()
U nearestpoint(I first, T number,U x0,Op dis) {
	  int i=0;
	  double tempdist=INFINITY;
	  T n=number;
	  U nn=x0;
	  while(n>0)
	  {
	  	double temp=dis(x0,*first);
	  	std::cout << "distance: " << ++i<<" -->> "<<temp<<std::endl;
	  	   	if(tempdist > temp)
	  	   		{
	  	   			tempdist=temp;
	  	   			nn=*first;
	  	   		}
	  	   		first=++first;
	  	   	--n	;
	  }
	return  nn;
}

template<typename T1,typename T2>
double distanceEucl(point<T1,T2> p1 , point<T1,T2> p2) {
	double dist=0;
	double xDiff=(p1.x-p2.x);
	double yDiff=(p1.y-p2.y);
		dist=sqrt(xDiff*xDiff+yDiff*yDiff);
	return dist;
}


template<typename T1,typename T2,typename T3>
double distanceEucl3(point_3d<T1,T2,T3> p1 , point_3d<T1,T2,T3> p2) {
	double xDiff=(p1.x-p2.x);
	double yDiff=(p1.y-p2.y);
	double zDiff=(p1.z-p2.z);
return sqrt(xDiff*xDiff+yDiff*yDiff+zDiff*zDiff);
}

template<typename T1>
double distanceHamming(StrCls<T1> p1, StrCls<T1> p2) {
const char* p1Temp=p1.x;
const char* p2Temp=p2.x;
if(strlen(p1Temp)!=strlen(p2Temp))
	return INFINITY;
double dist=0;
while( *(p1Temp)!='\0' && *(p2Temp)!='\0' )
{
	if(*p1Temp != *p2Temp)
	{
		dist++;
	}
	++p1Temp;
	++p2Temp;
}
return dist;
}

template<typename T>
T maxi(T a, T b)
{
	return a<=b?b:a;
}

template<typename T>
T mini(T a, T b)
{
	return a>=b?b:a;
}

template<typename T>
T mini(T a, T b, T c)
{
	T temp=(a>=b?b:a);
	return temp>=c?c:temp;
}

template<typename T1>
double distanceLevenshtein(StrCls<T1> p1, StrCls<T1> p2) {
const char* p1Temp=p1.x;
const char* p2Temp=p2.x;
double len1=strlen(p1Temp);	
double len2=strlen(p2Temp);
if(mini(len1,len2)==0)
	return maxi(len1,len2);
else
	{
	return levDist(p1,len1,p2,len2);
	}
}

template<typename T1,typename T2>
double levDist(StrCls<T1> p1,T2 l1, StrCls<T1> p2, T2 l2) {
	T2 cost=0;
if(l1==0)
	return l2;
if(l2==0)
	return l1;
const char* p1Temp=p1.x;
const char* p2Temp=p2.x;
if(p1Temp[(int)l1-1]==p2Temp[(int)l2-1])
	cost=0;
else
	cost=1;
return mini((levDist(p1,l1-1,p2,l2)+1),(levDist(p1,l1,p2,l2-1)+1),(levDist(p1,l1-1,p2,l2-1)+cost));
}

template<typename T1>
double distanceJaccard(BinStr<T1> p1, BinStr<T1> p2) {
const char* p1Temp=p1.x;
const char* p2Temp=p2.x;
int m00=0;
int m01=0;
int m10=0;
int m11=0;
double dist=0;
if(strlen(p1Temp)!=strlen(p2Temp))
	return INFINITY;
while( *(p1Temp)!='\0' && *(p2Temp)!='\0' )
{
	if((*p1Temp=='0' || *p1Temp=='1') && (*p2Temp=='0' || *p2Temp=='1'))
	{
		if(*p1Temp=='0' && *p2Temp=='0')
		{
			m00++;
		}
		else if(*p1Temp=='0' && *p2Temp=='1')
		{
			m01++;
		}
		else if(*p1Temp=='1' && *p2Temp=='0')
		{
			m10++;
		}
		else if(*p1Temp=='1' && *p2Temp=='1')
		{
			m11++;
		}
	}
	else
		return INFINITY;
	++p1Temp;
	++p2Temp;
}
dist=(double)(m01+m10)/(m01+m10+m11);
return dist;
}

#endif
