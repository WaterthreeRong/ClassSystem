#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
#include"Student.h"
int main()
{//1
   //模块一：登录
   //定义登录学号，登录密码变量
   int loading_num;   int loading_password;
   Student_HWN stu;int i;
   //读取学生的信息
   ifstream instu("student.txt",ios::out);
   if(!instu)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   instu>>stu.num>>stu.Class>>stu.name>>stu.personal_num>>stu.personal_password;
   //读取学生公共课
   ifstream instup("studentPucourse.txt",ios::out);
   if(!instup)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<5;i++)
   {instup>>stu.Pu[i];}
   //读取学生必修课
   ifstream instur("studentRecourse.txt",ios::out);
   if(!instur)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<5;i++)
   {instur>>stu.Re[i];}
   //读取学生选修课
   ifstream instue("studentElcourse.txt",ios::out);
   if(!instue)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<5;i++)
   {instue>>stu.El[i];}
   Public_course_ZR P[25];//定义一个公共课类对象数组用来读取公共课的选课信息
   Required_course_ZR R[25];//定义一个必修课类对象数组
   ElctiveCourse_HWN E[25];//定义一个选修课类对象数组
   //读取公共课选课信息
   ifstream inp("Publiccourse.txt",ios::in);
   if(!inp)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<25;i++)
   {inp>>P[i];}
   //读取必修课选课信息
   ifstream inr("Requiredcourse.txt",ios::in);
   if(!inr)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<25;i++)
   {inr>>R[i];}
   //读取选修课选课信息
   ifstream ine("Elctivecourse.txt",ios::in);
   if(!ine)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<25;i++)
   {ine>>E[i];}
   //
   while(1)
   {//2
   cout<<"▏▏▏▏   欢迎来到学生选课系统     ▏▏▏▏"<<endl;
   cout<<endl;
   cout<<"*  *  *  *   请输入你的学号和密码   *  *  *  *  " <<endl;
   cout<<endl;
   cout<<"     *  *    学号： ";
   cin>>loading_num;
   cout<<endl;
   cout<<"     *  *    密码： ";
   cin>>loading_password;
   system("cls");
  //因为personal_num是学生类的保护数据。所以不能直接调用
   if(loading_num==stu.personal_num)//！！！！用个文件存放所有学生的学号和密码，这里再调用那个文件来判断
   {//3
   if(loading_password==stu.personal_password)  
   { //4
	   //模块二：进入界面选择：
	  while(1)
      {//5
       cout<<"****** 1、必修课      ******"<<endl;
	   cout<<"****** 2、公共课      ******"<<endl;
	   cout<<"****** 3、选修课      ******"<<endl;
	   cout<<"****** 4、退出系统    ******"<<endl;
	   cout<<"-------  请输入你的选择  -------  "<<endl;
	   
         int  select_num_HWN;//定义一个变量用来装载用户的选择
	     cin>>select_num_HWN;//用户输入他的选择
        switch(select_num_HWN)
		{
		  case 1://必修的模块
                 while(1)
				 {
                  cout<<"^^^^^^^  必修课  ^^^^^^^"<<endl;
				  cout<<"     1、选择大学英语    "<<endl;
				  cout<<"     2、选择体育课      "<<endl;
				  cout<<"     3、查看已选课程    "<<endl;
				  cout<<"     4、退选课程        "<<endl;
				  cout<<"   请输入你的选择       "<<endl;
                    int select_Re ;cin>>select_Re;
                    system("cls");
					if(select_Re==1)
					{   int num1;
					    cout<<"|课程编号|"<<"课程名称|"<<"课程性质|"<<"总学时|"
		                <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
						for(i=0;i<12;i++)
						{cout<<R[i];}
						while(1)
						{
						    cout<<"请输入你要选的课的课程编号:";
						    cin>>num1;
						    for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							{ if(num1==stu.Re[i].get_course_num()) break;}
						    if(num1==stu.Re[i].get_course_num()) 
							{  
						       cout<<"该课程已选!请重新输入!"<<endl;
							   continue;
							}
						    else
							{
						      int a1;
						      for(i=0;i<12;i++)
							  {if(num1==R[i].get_course_num()) a1=i;}
						      for(i=0;stu.Re[i].get_course_name()!="\0";i++) {}
						      stu.Re[i]=R[a1];
                              system("cls");
						      cout<<"选课成功!"<<endl;
						      cout<<"|课程编号|"<<"课程名称|"<<"课程性质|"<<"总学时|"
		                      <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
						      for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							  {cout<<stu.Re[i];}
							  break;
							}
						}
					  break;
					}
					if(select_Re==2) 
					{    
						
					  int num2;
					  cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		              <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
					  for(i=12;i<25;i++)
					  {cout<<R[i];}
					  while(1)
					  {
						    cout<<"请输入你要选的课的课程编号:";
						    cin>>num2;
						    for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							{ if(num2==stu.Re[i].get_course_num()) break;}
						    if(num2==stu.Re[i].get_course_num()) 
							{ 
						       cout<<"该课程已选!请重新输入!"<<endl;
							   continue;
							}
							else
							{
						       int a2;
						       for(i=12;i<25;i++)
							   {if(num2==R[i].get_course_num()) a2=i;}
						       for(i=0;stu.Re[i].get_course_name()!="\0";i++) {}
						       stu.Re[i]=R[a2];
						       system("cls");
						       cout<<"选课成功!"<<endl;
					           cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                       <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
						       for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							   {cout<<stu.Re[i];}
							   break;
							}
						}
                     
				      break;
					}
					if(select_Re==3)
					{   
						if(stu.Re[0].get_course_name()=="\0")
						{cout<<"当前无课程!"<<endl;}
						else
						{  
                           cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                   <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
						   for(i=0;stu.Re[i].get_course_name()!="\0";i++)
						   {cout<<stu.Re[i];}
						}
						break;
					}
				    if(select_Re==4)
					{   
						if(stu.Re[0].get_course_name()=="\0")
						{cout<<"当前无课程!"<<endl;}
						else
						{  
						   while(1)
						   {
                               cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                       <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
                               for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							   {cout<<stu.Re[i];}
	                           int k1;
						       cout<<"请输入你要退选的课程编号:";
					           cin>>k1;
						       for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							   { if(k1==stu.Re[i].get_course_num()) break;}
							   if(k1!=stu.Re[i].get_course_num()) 
							   {   system("cls");
								   cout<<"输入有误，无当前课程!请重新输入!"<<endl;
								   cout<<endl;
								   continue;
							   }
							   else
							   {
                                  stu.delete_Requiredcourse(k1);
						          system("cls");
						          cout<<"退选成功!"<<endl;
						          cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                          <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
                                  for(i=0;stu.Re[i].get_course_name()!="\0";i++)
								  {cout<<stu.Re[i];}
								  break;
							   }
						   }
						}
					  break;
					}
					else {system("cls");cout<<"输入有误，请重新输入。"<<endl;continue;}
				 }

			      break;
		  case 2://公共课
                      while(1)
					  {
                         cout<<"^^^^^^^ 公共课  ^^^^^^^"<<endl;
					     cout<<"    1、军事理论课       "<<endl;
					     cout<<"    2、形势政策课       "<<endl;
					     cout<<"    3、技术编程课       "<<endl;
						 cout<<"    4、查看已选课程     "<<endl;
						 cout<<"    5、退选课程         "<<endl;
					     cout<<"   请输入你的选择       "<<endl;
                         int select_Pu ;cin>>select_Pu;
                         system("cls");
				   	     if(select_Pu==1) 
						 {     
							int num3;
						    cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                    <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
					        for(i=0;i<8;i++)
							{cout<<P[i];}
							while(1)
							{
						        cout<<"请输入你要选的课的课程编号:";
						        cin>>num3;
							    for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								{ if(num3==stu.Pu[i].get_course_num()) break;}
						        if(num3==stu.Pu[i].get_course_num()) 
								{ 
						           cout<<"该课程已选!请重新输入!"<<endl;
							       continue;
								}
								else
								{
						          int a3;
						          for(i=0;i<8;i++)
								  {if(num3==P[i].get_course_num()) a3=i;}
						          for(i=0;stu.Pu[i].get_course_name()!="\0";i++) {}
						          stu.Pu[i]=P[a3];
							      system("cls");
						          cout<<"选课成功!"<<endl;
							      cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                          <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
						          for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								  {cout<<stu.Pu[i];}
								  break;
								}
							 }
						   break;
						 }
					     if(select_Pu==2) 
						 {    
							  
							int num4;
						    cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                    <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
					        for(i=8;i<16;i++)
							{cout<<P[i];}
							while(1)
							{
						         cout<<"请输入你要选的课的课程编号:";
						         cin>>num4;
							     for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								 { if(num4==stu.Pu[i].get_course_num()) break;}
						         if(num4==stu.Pu[i].get_course_num()) 
								 { 
						            cout<<"该课程已选!请重新输入!"<<endl;
							        continue;
								 }
								 else
								 {
						           int a4;
						           for(i=8;i<16;i++)
								   {if(num4==P[i].get_course_num()) a4=i;}
						           for(i=0;stu.Pu[i].get_course_name()!="\0";i++) {}
						           stu.Pu[i]=P[a4];
							       system("cls");
						           cout<<"选课成功!"<<endl;
							       cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                           <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
						           for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								   {cout<<stu.Pu[i];}
								   break;
								 }
							  }
                           break;
						 }
					     if(select_Pu==3) 
						 {    
							    int num5;
						        cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                        <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
					            for(i=16;i<25;i++)
								{cout<<P[i];}
							while(1)
							{
						        cout<<"请输入你要选的课的课程编号:";
						        cin>>num5;
							    for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								{ if(num5==stu.Pu[i].get_course_num()) break;}
						        if(num5==stu.Pu[i].get_course_num()) 
								{ 
						           cout<<"该课程已选!请重新输入!"<<endl;
							       continue;
								}
								else
								{
						           int a5;
						           for(i=16;i<25;i++)
								   {if(num5==P[i].get_course_num()) a5=i;}
						           for(i=0;stu.Pu[i].get_course_name()!="\0";i++) {}
						           stu.Pu[i]=P[a5];
							       system("cls");
						           cout<<"选课成功!"<<endl;
							       cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                           <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
						           for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								   {cout<<stu.Pu[i];}
								   break;
								}
							 }
					       break;
						 }
						 if(select_Pu==4)
						 {   
							 if(stu.Pu[0].get_course_name()=="\0")
							 {cout<<"当前无课程!"<<endl;}
							 else
							 {  
                                cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                        <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
						        for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								{cout<<stu.Pu[i];}
							 }
						     break;
						 }
				         if(select_Pu==5)
						 {   
                             if(stu.Pu[0].get_course_name()=="\0")
							 {cout<<"当前无课程!"<<endl;}
							 else
							 {   
								while(1)
								{
								   cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                           <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
                                   for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								   {cout<<stu.Pu[i];}
	                               int k2;
						           cout<<"请输入你要退选的课程编号:";
					               cin>>k2;
								   for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								   { if(k2==stu.Pu[i].get_course_num()) break;}
								   if(k2!=stu.Pu[i].get_course_num()) 
								   {  system("cls");
								      cout<<"输入有误，无当前课程!请重新输入!"<<endl;
									  cout<<endl;
									  continue;
								   }
								   else
								   {
                                      stu.delete_Publiccourse(k2);
								      system("cls");
						              cout<<"退选成功!"<<endl;
								      cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                              <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
                                      for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
									  {cout<<stu.Pu[i];}
									  break;
								   }
								}
							 }
						   break;
						 }
				   	     else {system("cls");cout<<"输入有误，请重新输入。"<<endl;continue;}
					  }
			          break;


          case 3://选修课：
                  while(1)
				  {
				  cout<<"^^^^^^^  选修课  ^^^^^^^"<<endl;
				  cout<<"     1、查看选修课"<<endl;
                  cout<<"     2、查看已选课程    "<<endl;
				  cout<<"     3、退选课程        "<<endl;
				  cout<<"^^^^^^^ 请输入你的选择^^^^^^^"<<endl;
				  int select_El1;
				  cin>>select_El1;
                  system("cls");
				   switch(select_El1)
				   {
				    case 1:
						  while(1)
						  { system("cls");
					        cout<<"   1、查看所有课程       "<<endl;
					        cout<<"   2、按学分查看课程     "<<endl;
					        cout<<"   3、按总学时查看课程   "<<endl;
							cout<<"   请输入你的选择：      "<<endl;
							int select_El2;
							cin>>select_El2;
							switch(select_El2)
							{
							case 1: 
								    cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                            <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl; 
								    for(i=0;i<25;i++)
									{E[i].search_nature();}
									cout<<" 是否要进行选课？ 1、是  2、否 "<<endl;
									int n1;cin>>n1;
									switch(n1)
									{
									    case 1:
										//进行选课
											int num6;
											cout<<"请输入你要选的课程的数量:";
											cin>>num6;
											for(i=0;i<num6;i++)
											{   int num7;int j;int a7;
												cout<<"请输入你要选择的课程的编号:";
												cin>>num7;
												for(j=0;stu.El[j].get_course_name()!="\0";j++)
												{ if(num7==stu.El[j].get_course_num()) break;}
												if(num7==stu.El[j].get_course_num()) 
												{ 
													cout<<"该课程已选!请重新输入!"<<endl;
						                            num6=num6+1;
												}
												else
												{ 
												  for(j=0;j<25;j++)
												  {if(num7==E[j].get_course_num()) a7=j;}
												  for(j=0;stu.El[j].get_course_name()!="\0";j++)
												  {if(E[a7].get_day()==stu.El[j].get_day()) break;}
												  if(E[a7].get_day()==stu.El[j].get_day())
												  {  
													  cout<<"该课程与所选课程日期冲突,请重新输入!"<<endl;
												      num6=num6+1;
												  }
												  else
												  {
												    for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												    stu.El[j]=E[a7];
												    cout<<"选课成功!"<<endl;
                                                    cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                            <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											        for(j=0;stu.El[j].get_course_name()!="\0";j++)
													{cout<<stu.El[j];}
												  }
												}
											}
										   break;
										case 2:
										//不进行选课的话就回到要他查看课程还是按学分查看的那个页面
											break;
										
                                        default:system("cls"); 
											    cout<<"输入有误。"<<endl;
											    break; 
									}
						    break;

                            case 2:
                                  while(1)
								  {   system("cls");
									  cout<<"1、 1.0学分    2、 1.5学分   3、2.0学分  "<<endl;
									  cout<<"请输入你的选择："<<endl;
									  int select_El3;cin>>select_El3;
									  switch(select_El3)
									  {
                                           case 1:
												 //po出1学分的选修课，因为可能可选的课不多了，至于选老师的话就可以不用按老师来查询。让用户喜欢那个就选那个呗
											     cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                         <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											     for(i=0;i<25;i++)
												 {E[i].search_credit(1.0);}
											     cout<<"是否进行选课？  1、是   2、否"<<endl;
											     int n2;cin>>n2;
									             switch(n2)
												 {
									              case 1:
									                	//进行选课
													    int num8;
											            cout<<"请输入你要选的课程的数量:";
											            cin>>num8;
											            for(i=0;i<num8;i++)
														{   int num9;int j;int a9;
											 	            cout<<"请输入你要选择的课程的编号:";
												            cin>>num9;
															for(j=0;stu.El[j].get_course_name()!="\0";j++)
															{ if(num9==stu.El[j].get_course_num()) break;}
												            if(num9==stu.El[j].get_course_num()) 
															{ 
													          cout<<"该课程已选!请重新输入!"<<endl;
						                                      num8=num8+1;
															}
															else
															{
												                for(j=0;j<25;j++)
																{if(num9==E[j].get_course_num()) a9=j;}
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{if(E[a9].get_day()==stu.El[j].get_day()) break;}
												                if(E[a9].get_day()==stu.El[j].get_day())
																{  
													               cout<<"该课程与所选课程日期冲突,请重新输入!"<<endl;
												                   num8=num8+1;
																}
																else
																{
												                   for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                   stu.El[j]=E[a9];
												                   cout<<"选课成功!"<<endl;
                                                                   cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                                           <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											                       for(j=0;stu.El[j].get_course_name()!="\0";j++)
																   {cout<<stu.El[j];}
																}
															}
														}
														break;
												  case 2: break;
												  //不进行选课的话就回到要他查看课程还是按学分查看的那个页面	  
                                                  default:system("cls");
													      cout<<"输入有误。"<<endl;  
														  break; 
									 
												 }
										          break;
                                           case 2:
												   //po出1.5学分的必修课
											     cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                         <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											     for(i=0;i<25;i++)
												 {E[i].search_credit(1.5);}
                                                 cout<<"是否进行选课？  1、是   2、否"<<endl;
											     int n3;cin>>n3;
									                switch(n3)
													{
									                    case 1:
									                	 //进行选课
                                                            int num10;
											                cout<<"请输入你要选的课程的数量:";
											                cin>>num10;
											                for(i=0;i<num10;i++)
															{   int num11;int j;int a11;
											 	                cout<<"请输入你要选择的课程的编号:";
												                cin>>num11;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num11==stu.El[j].get_course_num()) break;}
												                if(num11==stu.El[j].get_course_num()) 
																{ 
												                    cout<<"该课程已选!请重新输入!"<<endl;
						                                            num10=num10+1;
																}
																else
																{
												                    for(j=0;j<25;j++)
																	{if(num11==E[j].get_course_num()) a11=j;}
																	for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	{if(E[a11].get_day()==stu.El[j].get_day()) break;}
												                    if(E[a11].get_day()==stu.El[j].get_day())
																	{  
													                   cout<<"该课程与所选课程日期冲突,请重新输入!"<<endl;
												                       num10=num10+1;
																	}
																	else
																	{
												                      for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                      stu.El[j]=E[a11];
												                      cout<<"选课成功!"<<endl;
															          cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                                              <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											                          for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	  {cout<<stu.El[j];}
																	}
																}
															}
															break;
														case 2: break;
												      //不进行选课的话就回到要他查看课程还是按学分查看的那个页面	  
                                                     default :system("cls");
														      cout<<"输入有误。"<<endl; 
															  break; 
									 
													}
									             break;
										   case 3:
												   //po出2学分的必修课
											         cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                             <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											         for(i=0;i<25;i++)
													 {E[i].search_credit(2.0);}
                                                     cout<<"是否进行选课？  1、是   2、否"<<endl;
											          int n4;cin>>n4;
									                   switch(n4)
													   {
									                      case 1:
									                	  //进行选课
                                                            int num12;
											                cout<<"请输入你要选的课程的数量:";
											                cin>>num12;
											                for(i=0;i<num12;i++)
															{   int num13;int j;int a13;
											 	                cout<<"请输入你要选择的课程的编号:";
												                cin>>num13;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num13==stu.El[j].get_course_num()) break;}
												                if(num13==stu.El[j].get_course_num()) 
																{ 
													                cout<<"该课程已选!请重新输入!"<<endl;
						                                            num12=num12+1;
																}
																else
																{
												                    for(j=0;j<25;j++)
																	{if(num13==E[j].get_course_num()) a13=j;}
																	for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	{if(E[a13].get_day()==stu.El[j].get_day()) break;}
												                    if(E[a13].get_day()==stu.El[j].get_day())
																	{  
													                  cout<<"该课程与所选课程日期冲突,请重新输入!"<<endl;
												                      num12=num12+1;
																	}
																	else
																	{
												                       for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                       stu.El[j]=E[a13];
												                       cout<<"选课成功!"<<endl;
																       cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                                               <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											                           for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	   {cout<<stu.El[j];}
																	}
																} 
															}
															break;
														  case 2: break;
												          //不进行选课的话就回到要他查看课程还是按学分查看的那个页面	  
                                                          default :system("cls");
															       cout<<"输入有误。"<<endl;
																   break; 
									 
													   }

											       break;

										   default : system("cls");
											         cout<<"选择有误，请重选"<<endl;
													 break;

									  }//switch
									  if(select_El3==1||select_El3==2||select_El3==3) break;
									  else continue;
								  }//循环
							    break;

							case 3:
								
                                  while(1)
								  {
									  cout<<"1、 16学时    2、 32学时   3、48学时  "<<endl;
									  cout<<"请输入你的选择："<<endl;
									  int select_El4;cin>>select_El4;
									  switch(select_El4)
									  {
                                           case 1:
												 //po出16学时的必修课，因为可能可选的课不多了，至于选老师的话就可以不用按老师来查询。让用户喜欢那个就选那个呗
											     cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                         <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											     for(i=0;i<25;i++)
												 {E[i].search_hours(16);}
											     cout<<"是否进行选课？  1、是   2、否"<<endl;
											     int n5;cin>>n5;
									             switch(n5)
												 {
									              case 1:
									                	//进行选课
                                                            int num14;
											                cout<<"请输入你要选的课程的数量:";
											                cin>>num14;
											                for(i=0;i<num14;i++)
															{   int num15;int j;int a15;
											 	                cout<<"请输入你要选择的课程的编号:";
												                cin>>num15;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num15==stu.El[j].get_course_num()) break;}
												                if(num15==stu.El[j].get_course_num()) 
																{ 
													                cout<<"该课程已选!请重新输入!"<<endl;
						                                            num14=num14+1;
																}
																else
																{
												                    for(j=0;j<25;j++)
																	{if(num15==E[j].get_course_num()) a15=j;}
																	for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	{if(E[a15].get_day()==stu.El[j].get_day()) break;}
												                    if(E[a15].get_day()==stu.El[j].get_day())
																	{  
													                   cout<<"该课程与所选课程日期冲突,请重新输入!"<<endl;
												                       num14=num14+1;
																	}
																	else
																	{
												                       for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                       stu.El[j]=E[a15];
												                       cout<<"选课成功!"<<endl;
																       cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                                               <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											                           for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	   {cout<<stu.El[j];}
																	}
																}
															}
														    break;
												  case 2: break;
												  //不进行选课的话就回到要他查看课程还是按学分查看的那个页面	  
                                                  default:system("cls");
													      cout<<"输入有误。"<<endl; 
														  break; 
									 
												 }
												 break;
                                           case 2:
												   //po出32学时的必修课
											     cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                         <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											     for(i=0;i<25;i++)
												 {E[i].search_hours(32);}
                                                 cout<<"是否进行选课？  1、是   2、否"<<endl;
											     int n6;cin>>n6;
									                switch(n6)
													{
									                    case 1:
									                	 //进行选课
                                                            int num16;
											                cout<<"请输入你要选的课程的数量:";
											                cin>>num16;
											                for(i=0;i<num16;i++)
															{   int num17;int j;int a17;
											 	                cout<<"请输入你要选择的课程的编号:";
												                cin>>num17;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num17==stu.El[j].get_course_num()) break;}
												                if(num17==stu.El[j].get_course_num()) 
																{ 
													                cout<<"该课程已选!请重新输入!"<<endl;
						                                            num16=num16+1;
																}
																else
																{
												                    for(j=0;j<25;j++)
																	{if(num17==E[j].get_course_num()) a17=j;}
																	for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	{if(E[a17].get_day()==stu.El[j].get_day()) break;}
												                    if(E[a17].get_day()==stu.El[j].get_day())
																	{  
													                   cout<<"该课程与所选课程日期冲突,请重新输入!"<<endl;
												                       num16=num16+1;
																	}
																	else
																	{
												                       for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                       stu.El[j]=E[a17];
												                       cout<<"选课成功!"<<endl;
																       cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                                               <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											                           for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	   {cout<<stu.El[j];}
																	}
																}
															}
															break;
														case 2: break;
												      //不进行选课的话就回到要他查看课程还是按学分查看的那个页面	  
                                                     default :system("cls");
														      cout<<"输入有误。"<<endl; 
															  break; 
									 
													}
											   break;
										   case 3:
											  
												   //po出48学时的必修课
											       cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                           <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											       for(i=0;i<25;i++)
												   {E[i].search_hours(48);}
                                                     cout<<"是否进行选课？  1、是   2、否"<<endl;
											          int n7;cin>>n7;
									                   switch(n7)
													   {
									                      case 1:
									                	  //进行选课
                                                            int num18;
											                cout<<"请输入你要选的课程的数量:";
											                cin>>num18;
											                for(i=0;i<num18;i++)
															{   int num19;int j;int a19;
											 	                cout<<"请输入你要选择的课程的编号:";
												                cin>>num19;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num19==stu.El[j].get_course_num()) break;}
												                if(num19==stu.El[j].get_course_num()) 
																{ 
												 	                cout<<"该课程已选!请重新输入!"<<endl;
						                                            num18=num18+1;
																}
																else
																{
												                    for(j=0;j<25;j++)
																	{if(num19==E[j].get_course_num()) a19=j;}
																	for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	{if(E[a19].get_day()==stu.El[j].get_day()) break;}
												                    if(E[a19].get_day()==stu.El[j].get_day())
																	{  
													                   cout<<"该课程与所选课程日期冲突,请重新输入!"<<endl;
												                       num18=num18+1;
																	}
																	else
																	{
												                      for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                      stu.El[j]=E[a19];
												                      cout<<"选课成功!"<<endl;
																      cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                                                              <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
											                          for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	  {cout<<stu.El[j];}
																	}
																}
															}
															  break;
														  case 2: break;
												          //不进行选课的话就回到要他查看课程还是按学分查看的那个页面	  
                                                          default :system("cls");
															       cout<<"输入有误。"<<endl; 
																   break; 
									 
													   }

											      break;
										   default : system("cls");
											         cout<<"选择有误，请重选"<<endl;
													 break;

									  }//switch
									  if(select_El4==1||select_El4==2||select_El4==3) break;
									  else continue;
								  }//循环

								break;
                            default:system("cls");
								    cout<<"输入有误，请重新输入"<<endl; 
									break;
							}//switch_select_El2
                            if(select_El2==1||select_El2==2||select_El2==3) break;
							else continue;
						  }//循环
                   break;
                  case 2://查看已选的选修课
					  //po出他选了的选修课程
					  system("cls");
					  if(stu.El[0].get_course_name()=="\0")
					  {cout<<"当前无课程!"<<endl;}
					  else
					  {   
						  cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                  <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
					      for(i=0;stu.El[i].get_course_name()!="\0";i++)
						  {cout<<stu.El[i];}
					  }
					  break;  
				  case 3://退选课程
					  system("cls");
                      if(stu.El[0].get_course_name()=="\0")
					  {cout<<"当前无课程!"<<endl;}
					  else
					  {   
						  while(1)
						  {
						    cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                    <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
                            for(i=0;stu.El[i].get_course_name()!="\0";i++)
							{cout<<stu.El[i];}
					        int num20;
					        cout<<"请输入要退选的课程的编号:";
                            cin>>num20;
						    for(i=0;stu.El[i].get_course_name()!="\0";i++)
							{ if(num20==stu.El[i].get_course_num()) break;}
						    if(num20!=stu.El[i].get_course_num()) 
							{   system("cls");
								cout<<"输入有误，无当前课程!请重新输入!"<<endl;
								cout<<endl;
						        continue;
							}
						    else
							{
					          stu.delete_Elctivecourse(num20);
						      system("cls");
					          cout<<"退选成功!"<<endl;
						      cout<<"|课程编号| "<<"课程名称|"<<"课程性质|"<<"总学时|"
		                      <<"授课学时|"<<"实验或上机学时|"<<"学分|"<<"开课学期|"<<"教师|"<<"日期|"<<endl;
					          for(i=0;stu.El[i].get_course_name()!="\0";i++)
							  {cout<<stu.El[i];}
						      break;
							}
						  }
					  }
                       break;
				  default: system("cls");
					       cout<<"输入有误，请重新选择。"<<endl; 
						   break;

				}//switch_select_El1
				if(select_El1==1||select_El1==2||select_El1==3) break;
				else continue;
			  }
			break;

		  case 4://退出系统：
			 break;
		  default: system("cls");
			       cout<<"对不起，输入错误。"<<endl;
				   cout<<"请再次输入正确的选择。"<<endl; break;

		}//switch_select_num_HWN
		if(select_num_HWN==4) break;
		else continue;
	  }//5大循环
	   break;}//4
	   else {system("cls");cout<<"密码错误请重新输入!"<<endl;continue;}
     break;}//3
	 else{system("cls");cout<<"用户不存在请重新输入!"<<endl;continue;}
   }//2
   system("cls");
   ofstream outstup("studentPucourse.txt",ios::out);
   if(!outstup)
   {cerr<<"Open erroe!"<<endl;
   exit(1);
   }
   for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
   {outstup<<stu.Pu[i];
   }
   ofstream outstur("studentRecourse.txt",ios::out);
   if(!outstur)
   {cerr<<"Open erroe!"<<endl;
   exit(1);
   }
   for(i=0;stu.Re[i].get_course_name()!="\0";i++)
   {outstur<<stu.Re[i];
   }
   ofstream outstue("studentElcourse.txt",ios::out);
   if(!outstue)
   {cerr<<"Open erroe!"<<endl;
   exit(1);
   }
   for(i=0;stu.El[i].get_course_name()!="\0";i++)
   {outstue<<stu.El[i];
   }
   outstup.close();
   outstur.close();
   outstue.close();
   instu.close();
   instup.close();
   instur.close();
   instue.close();
   cout<<"你已经成功退出系统!"<<endl;
   return 0;
}//1