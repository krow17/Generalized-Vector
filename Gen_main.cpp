/*Gen_vec.h
Kyle Rowland
Main fucntion for a templated vector data structure
*/

#include <iostream>
#include <stdexcept>
#include "Gen_vec.h"

int main()
{
	try
	{
	
	Gen_vec<int> v;
	Gen_vec<int> v2;

	////////////////////////////////////////////////////////////////////////////////////////////
	// testing with int
	
		
		
		for(int i = 0; i<v.get_capacity(); i++)
		{
			v.insert_at_rank(i, 0);
		}
		
		v.replace_at_rank(0, 1);
		for (int i = 0; i < v.get_size(); i++)
		{
			cout<<v[i]<<' ';	
		}	
		cout<<endl<<"Size: "<<v.get_size()<<endl;
		
		v.replace_at_rank(0, 4);
		for (int i = 0; i < v.get_size(); i++)
			{
				cout<<v[i]<<' ';	
			}	
		cout<<endl<<"Size: "<<v.get_size()<<endl;
		
		v.replace_at_rank(10, 10);
		for (int i = 0; i < v.get_size(); i++)
			{
				cout<<v[i]<<' ';	
			}	
		cout<<endl<<"Size: "<<v.get_size()<<endl;
		
		v.replace_at_rank(2, 2);
		for (int i = 0; i < v.get_size(); i++)
			{
				cout<<v[i]<<' ';	
			}	
		cout<<endl<<"Size: "<<v.get_size()<<endl;
		
		v.remove_at_rank(2);
		for (int i = 0; i < v.get_size(); i++)
			{
				cout<<v[i]<<' ';	
			}		
		cout<<endl<<"Size: "<<v.get_size()<<endl;
		
		v.insert_at_rank(2, 3);
		for (int i = 0; i < v.get_size(); i++)
			{
				cout<<v[i]<<' ';	
			}	
		cout<<endl<<"Size: "<<v.get_size()<<endl;
		
		Gen_vec<int> v1 = v;
		
		v1.replace_at_rank(2, 9);
		for (int i = 0; i < v1.get_size(); i++)
			{
				cout<<v1[i]<<' ';	
			}	
		cout<<"This is v1";
		cout<<endl<<"Size: "<<v1.get_size()<<endl;
		
		v2.insert_at_rank(0, 6);
		for (int i = 0; i < v2.get_size(); i++)
			{
				cout<<v2[i]<<' ';	
			}	
		cout<<endl<<"Size: "<<v2.get_size()<<endl;
		
		v2 = v1;
		for (int i = 0; i < v2.get_size(); i++)
			{
				cout<<v2[i]<<' ';	
			}	
		cout<<"This is v2";
		cout<<endl<<"Size: "<<v2.get_size()<<endl;
		
		v2.find_max_index(v2);
	
	}

	catch(...)
	{
		cerr<<"You done goofed";
	}
}
