#include <iostream>
#include <fstream>
#include "Memory.h"

using namespace std;



void memory::Add()
{

	unsigned int i,j;
	unsigned int **copy= new unsigned int*[NumberOfManagers];


	for(i=1;i<=NumberOfManagers;i++)
	 {
	 	copy[i]=new unsigned int[Stack];
	 }
	 for(i=1;i<=NumberOfManagers;i++)
	{
		for(j=1;j<=Stack+1;j++)
		{
			copy[i][j]=MemoryManager[i][j];
		}
	}
	 
	NumberOfManagers++;


MemoryManager= new unsigned int *[NumberOfManagers];


     for(i=1;i<=NumberOfManagers;i++)
	 {
	 	MemoryManager[i]=new unsigned int[Stack];
	 }


	 for(i=1;i<NumberOfManagers;i++)
	{
		for(j=1;j<=Stack;j++)
		{
			MemoryManager[i][j]=copy[i][j];
		}
	}


	for (i = 0; i <= Stack; i++)
	{
		MemoryManager[NumberOfManagers][i]=0;
	}


}
void memory::createManager()
{
	
   
    cout<<"Input number of cells"<<endl;
	cin>>Stack;
	cout<<"Input number of managers"<<endl;
	cin>>NumberOfManagers;

	 unsigned int i,j;
	 MemoryManager= new unsigned int *[NumberOfManagers];

	 for(i=1;i<=NumberOfManagers;i++)
	 {
	 	MemoryManager[i]=new unsigned int[Stack];
	 }

	for(i=1;i<=NumberOfManagers;i++)
	{
		for(j=1;j<=Stack;j++)
		{
			MemoryManager[i][j]=0;
		}
	}

}
void memory::showMemory()
{
	 unsigned int i,j,use=0,nouse=0;
	for(i=1;i<=NumberOfManagers;i++)
	{
		for(j=1;j<=Stack;j++)
		{
			if(MemoryManager[i][j]==1) use++;
			if(MemoryManager[i][j]==0) nouse++;
		}

		cout<<"Manager "<<i<<": in use "<<use<<", free "<<nouse<<endl;
		use=0;
		nouse=0;
	}
}
void memory::clearMemory()
{
	cout<<"Input number of cells to clear"<<endl;
	cin>>clear;
	cout<<"Input number of manager"<<endl;
	cin>>NumberOfManager;
	 unsigned int i,c=0;
     for (i = 0; i < Stack; i++)
     {
     	if(MemoryManager[NumberOfManager][i]==1)
     	{
     		MemoryManager[NumberOfManager][i]=0;
     		clear--;
     		continue;
     	}
     	if(clear==0)
     	{
     		MemoryManager[NumberOfManager][i]=0;
     		break;
     	}
     }

}
void memory::fillMemory()
{
	cout<<"Input number cells to fill"<<endl;
	cin>>toFill;
	cout<<"Input number of manager"<<endl;
	cin>>NumberOfManager;
unsigned int counter=0,c=0,j1=0,i;
 bool first=true,done=false;
		for(i=1;i<=Stack;i++)
		{
			if(MemoryManager[NumberOfManager][i]==0)
			{
				c++;
			}
			if (MemoryManager[NumberOfManager][i]==1)
			{
				if(first==true)
				{
					if(c>= toFill)
					{
						j1=i-1-toFill;
						first=false;
						done=true;
						counter=c;
						c=0;
					}
				}
				else
				{
					if((c>= toFill)&&(c<=counter))
					{
						j1=i-1-toFill;
						done=true;
						counter=c;
						c=0;
					}
				}
			}
		}
	if ((done==false)&&(c!=Stack))
			{
				cout<<"Error.Not enough memory."<<endl;
			}
			else
			{
				if (c==Stack)
				{
					for (i = 0; i <=toFill; i++)
				{
					MemoryManager[NumberOfManager][i]=1;
				}
			}
				else
				{
					for (i = j1; i <=j1+toFill; i++)
				{
					MemoryManager[NumberOfManager][i]=1;
				}
	        }
		}
				
	
}
void memory::saveTo()
{
	unsigned int i, j;
	ofstream fout;
	fout.open("MemoryPrototype.txt");
	fout << NumberOfManagers;
	fout << " ";
	fout << Stack;
	fout << " ";
	for (i = 1;i <= NumberOfManagers;i++)
	{
		for (j = 1;j <= Stack;j++)
		{
			fout << MemoryManager[i][j];
			fout << " ";
		}

	}
	fout.close();
}
void memory::loadFrom()
{
	ifstream fin("MemoryPrototype.txt");
	unsigned int i, j;
	fin >> NumberOfManagers;
	fin >> Stack;

	MemoryManager = new unsigned int *[NumberOfManagers];


	for (i = 1;i <= NumberOfManagers;i++)
	{
		MemoryManager[i] = new unsigned int[Stack];
	}

	for (i = 1;i <= NumberOfManagers;i++)
	{
		for (j = 1;j <= Stack;j++)
		{
			fin >> MemoryManager[i][j];

		}

	}
}
memory::memory()
{
	Stack = 0;
	NumberOfManagers = 0;

}
unsigned int& memory::operator[](unsigned int index)
{
	return ((unsigned int*)this)[index];
}
memory::memory(unsigned int length, unsigned int weight)
{
	Stack = length;
	NumberOfManagers = weight;

}
memory::memory(memory& forcopy)
{
	unsigned int i, j;
	NumberOfManagers = forcopy.NumberOfManagers;
	Stack = forcopy.Stack;
	toFill = forcopy.toFill;
	clear = forcopy.clear;
	for (i = 1;i <= NumberOfManagers;i++)
	{
		for (j = 1;j <= Stack;j++)
		{
			MemoryManager[i][j] = forcopy.MemoryManager[i][j];
		}
	}
}
memory& memory:: operator->()
{
	return *this;
}
ostream& operator<<(ostream& out, memory& mem)
{
	return out<<mem;
}
ifstream& operator>>(ifstream& in, memory& mem)
{
	return in>>mem;
}
unsigned int memory::getStack()
{
	return Stack;
}
unsigned int memory::getNum()
{
	return NumberOfManagers;
}



