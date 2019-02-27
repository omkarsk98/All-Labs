//push down automata L={a^n b^n;n>=1}
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
stack<char> s;
string str;
string::iterator it;
char state;

void strt();
void stateA();
void stateB();
void stateC();
void trap();
void checkstr();
void strt(){
	s.push('z');
	state='s';
	it=str.begin();
	if(*it=='a'){
		s.push('a');
		stateA();
	}
	else
		trap();
}
void stateA(){
	state='a';
	++it;
	if(it==str.end())
		checkstr();
		
	if(*it=='a'){
		s.push('a');
		stateA();
	}
	else{
		s.pop();
		stateB();
	}
}
void stateB(){
	state='b';
	++it;

	if(s.top()=='z'){
		stateC();
	}
	else if(it==str.end())
		checkstr();
	else if(*it=='b'){
		s.pop();
		stateB();
	}
	else{
		trap();
	}
}
void stateC(){
	state='c';
	if(it!=str.end())
		trap();
	checkstr();
}
void trap(){
	state='t';
	checkstr();
}
void checkstr(){
	if(state=='c')
		cout<<"String Accepted\n";
	else
		cout<<"String Rejected\n";
	exit(0);
}
int main(){
  cout<<"Input String:";
	cin>>str;
	strt();
	return 0;
}