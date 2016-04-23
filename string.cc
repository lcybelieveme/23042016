///
///@date   2016-04-23 22:19:33
///
 
 
 
#include "string.hh"

int main()
{
	String s1;
	cin>>s1;
	cout<<s1<<endl;
	
	String s2="helli";
	
	cout<<s2<<endl;

	s1+=s2;
	cout<<s1<<endl;


	cout<<s1[3]<<endl;
	
	cout<<"s1.size()="<<s1.size()<<endl;

	cout<<"s1._c_str()="<<s1.c_str()<<endl;

	String s3;
	s3=s1+s2;
	cout<<s3<<endl;

	return 0;

}
