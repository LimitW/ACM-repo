//枚举
#include <iostream>

using namespace std;

void op1(int **clock,int t1)
{
	clock[0][0]+=t1;
	clock[0][1]+=t1;
	clock[1][0]+=t1;
	clock[1][1]+=t1;
}
void op2(int **clock,int t2)
{
	clock[0][0]+=t2;
	clock[0][1]+=t2;
	clock[0][2]+=t2;
}
void op3(int **clock,int t3)
{
	clock[0][1]+=t3;
	clock[0][2]+=t3;
	clock[1][1]+=t3;
	clock[1][2]+=t3;
}
void op4(int **clock,int t4)
{
	clock[0][0]+=t4;
	clock[1][0]+=t4;
	clock[2][0]+=t4;
}
void op5(int **clock,int t5)
{
	clock[0][1]+=t5;
	clock[1][0]+=t5;
	clock[1][1]+=t5;
	clock[1][2]+=t5;
	clock[2][1]+=t5;
}
void op6(int **clock,int t6)
{
	clock[0][2]+=t6;
	clock[1][2]+=t6;
	clock[2][2]+=t6;
}
void op7(int **clock,int t7)
{
	clock[1][0]+=t7;
	clock[1][1]+=t7;
	clock[2][0]+=t7;
	clock[2][1]+=t7;
}
void op8(int **clock,int t8)
{
	clock[2][0]+=t8;
	clock[2][1]+=t8;
	clock[2][2]+=t8;
}
void op9(int **clock,int t9)
{
	clock[1][1]+=t9;
	clock[1][2]+=t9;
	clock[2][1]+=t9;
	clock[2][2]+=t9;
}
bool check(int **clock)
{
	bool ans=1;
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			if(clock[i][j] %4 == 0)
				continue;
			else
			{
				ans=0;
				return ans;
			}
		}
		return ans;
}
void ori(int **clock,int **c_clock)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			clock[i][j]=c_clock[i][j];
}
int main()
{
	int **clock,**c_clock;
	clock=new int*[3];
	c_clock=new int*[3];
	int i,j;
	for(i=0;i<3;i++)
	{	
		clock[i]=new int[3];
		c_clock[i]=new int[3];
	}
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			cin>>clock[i][j];
			c_clock[i][j]=clock[i][j];
		}
	int t1,t2,t3,t4,t5,t6,t7,t8,t9;
	int sum=0,min=36;
	int path[9]={0};
	for(t9=0;t9<4;t9++)
		for(t8=0;t8<4;t8++)
			for(t7=0;t7<4;t7++)
				for(t6=0;t6<4;t6++)
					for(t5=0;t5<4;t5++)
						for(t4=0;t4<4;t4++)
							for(t3=0;t3<4;t3++)
								for(t2=0;t2<4;t2++)
									for(t1=0;t1<4;t1++)
									{
										sum=t1+t2+t3+t4+t5+t6+t7+t8+t9;
										op1(clock,t1);
										op2(clock,t2);
										op3(clock,t3);
										op4(clock,t4);
										op5(clock,t5);
										op6(clock,t6);
										op7(clock,t7);
										op8(clock,t8);
										op9(clock,t9);
										if(check(clock))
										{
											if(sum>=min) continue;
											if(sum<min) 
											{path[0]=t1;path[1]=t2;path[2]=t3;path[3]=t4;path[4]=t5;path[5]=t6;path[6]=t7;path[7]=t8;path[8]=t9;}
										}
										else 
											ori(clock,c_clock);
									}
	for(i=0;i<9;i++)
	{

		for(j=path[i];j>0;j--)
			cout<<i+1<<' ';
	}
	for(i=0;i<3;i++)
		delete []clock[i];
	delete []clock;
	return 0;
}