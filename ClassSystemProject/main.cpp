#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
#include"Student.h"
int main()
{//1
   //ģ��һ����¼
   //�����¼ѧ�ţ���¼�������
   int loading_num;   int loading_password;
   Student_HWN stu;int i;
   //��ȡѧ������Ϣ
   ifstream instu("student.txt",ios::out);
   if(!instu)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   instu>>stu.num>>stu.Class>>stu.name>>stu.personal_num>>stu.personal_password;
   //��ȡѧ��������
   ifstream instup("studentPucourse.txt",ios::out);
   if(!instup)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<5;i++)
   {instup>>stu.Pu[i];}
   //��ȡѧ�����޿�
   ifstream instur("studentRecourse.txt",ios::out);
   if(!instur)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<5;i++)
   {instur>>stu.Re[i];}
   //��ȡѧ��ѡ�޿�
   ifstream instue("studentElcourse.txt",ios::out);
   if(!instue)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<5;i++)
   {instue>>stu.El[i];}
   Public_course_ZR P[25];//����һ�����������������������ȡ�����ε�ѡ����Ϣ
   Required_course_ZR R[25];//����һ�����޿����������
   ElctiveCourse_HWN E[25];//����һ��ѡ�޿����������
   //��ȡ������ѡ����Ϣ
   ifstream inp("Publiccourse.txt",ios::in);
   if(!inp)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<25;i++)
   {inp>>P[i];}
   //��ȡ���޿�ѡ����Ϣ
   ifstream inr("Requiredcourse.txt",ios::in);
   if(!inr)
   {cerr<<"Open error!"<<endl;
   exit(1);
   }
   for(i=0;i<25;i++)
   {inr>>R[i];}
   //��ȡѡ�޿�ѡ����Ϣ
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
   cout<<"��������   ��ӭ����ѧ��ѡ��ϵͳ     ��������"<<endl;
   cout<<endl;
   cout<<"*  *  *  *   ���������ѧ�ź�����   *  *  *  *  " <<endl;
   cout<<endl;
   cout<<"     *  *    ѧ�ţ� ";
   cin>>loading_num;
   cout<<endl;
   cout<<"     *  *    ���룺 ";
   cin>>loading_password;
   system("cls");
  //��Ϊpersonal_num��ѧ����ı������ݡ����Բ���ֱ�ӵ���
   if(loading_num==stu.personal_num)//���������ø��ļ��������ѧ����ѧ�ź����룬�����ٵ����Ǹ��ļ����ж�
   {//3
   if(loading_password==stu.personal_password)  
   { //4
	   //ģ������������ѡ��
	  while(1)
      {//5
       cout<<"****** 1�����޿�      ******"<<endl;
	   cout<<"****** 2��������      ******"<<endl;
	   cout<<"****** 3��ѡ�޿�      ******"<<endl;
	   cout<<"****** 4���˳�ϵͳ    ******"<<endl;
	   cout<<"-------  ���������ѡ��  -------  "<<endl;
	   
         int  select_num_HWN;//����һ����������װ���û���ѡ��
	     cin>>select_num_HWN;//�û���������ѡ��
        switch(select_num_HWN)
		{
		  case 1://���޵�ģ��
                 while(1)
				 {
                  cout<<"^^^^^^^  ���޿�  ^^^^^^^"<<endl;
				  cout<<"     1��ѡ���ѧӢ��    "<<endl;
				  cout<<"     2��ѡ��������      "<<endl;
				  cout<<"     3���鿴��ѡ�γ�    "<<endl;
				  cout<<"     4����ѡ�γ�        "<<endl;
				  cout<<"   ���������ѡ��       "<<endl;
                    int select_Re ;cin>>select_Re;
                    system("cls");
					if(select_Re==1)
					{   int num1;
					    cout<<"|�γ̱��|"<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
						for(i=0;i<12;i++)
						{cout<<R[i];}
						while(1)
						{
						    cout<<"��������Ҫѡ�ĿεĿγ̱��:";
						    cin>>num1;
						    for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							{ if(num1==stu.Re[i].get_course_num()) break;}
						    if(num1==stu.Re[i].get_course_num()) 
							{  
						       cout<<"�ÿγ���ѡ!����������!"<<endl;
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
						      cout<<"ѡ�γɹ�!"<<endl;
						      cout<<"|�γ̱��|"<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                      <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
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
					  cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		              <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
					  for(i=12;i<25;i++)
					  {cout<<R[i];}
					  while(1)
					  {
						    cout<<"��������Ҫѡ�ĿεĿγ̱��:";
						    cin>>num2;
						    for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							{ if(num2==stu.Re[i].get_course_num()) break;}
						    if(num2==stu.Re[i].get_course_num()) 
							{ 
						       cout<<"�ÿγ���ѡ!����������!"<<endl;
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
						       cout<<"ѡ�γɹ�!"<<endl;
					           cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                       <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
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
						{cout<<"��ǰ�޿γ�!"<<endl;}
						else
						{  
                           cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                   <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
						   for(i=0;stu.Re[i].get_course_name()!="\0";i++)
						   {cout<<stu.Re[i];}
						}
						break;
					}
				    if(select_Re==4)
					{   
						if(stu.Re[0].get_course_name()=="\0")
						{cout<<"��ǰ�޿γ�!"<<endl;}
						else
						{  
						   while(1)
						   {
                               cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                       <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
                               for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							   {cout<<stu.Re[i];}
	                           int k1;
						       cout<<"��������Ҫ��ѡ�Ŀγ̱��:";
					           cin>>k1;
						       for(i=0;stu.Re[i].get_course_name()!="\0";i++)
							   { if(k1==stu.Re[i].get_course_num()) break;}
							   if(k1!=stu.Re[i].get_course_num()) 
							   {   system("cls");
								   cout<<"���������޵�ǰ�γ�!����������!"<<endl;
								   cout<<endl;
								   continue;
							   }
							   else
							   {
                                  stu.delete_Requiredcourse(k1);
						          system("cls");
						          cout<<"��ѡ�ɹ�!"<<endl;
						          cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                          <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
                                  for(i=0;stu.Re[i].get_course_name()!="\0";i++)
								  {cout<<stu.Re[i];}
								  break;
							   }
						   }
						}
					  break;
					}
					else {system("cls");cout<<"�����������������롣"<<endl;continue;}
				 }

			      break;
		  case 2://������
                      while(1)
					  {
                         cout<<"^^^^^^^ ������  ^^^^^^^"<<endl;
					     cout<<"    1���������ۿ�       "<<endl;
					     cout<<"    2���������߿�       "<<endl;
					     cout<<"    3��������̿�       "<<endl;
						 cout<<"    4���鿴��ѡ�γ�     "<<endl;
						 cout<<"    5����ѡ�γ�         "<<endl;
					     cout<<"   ���������ѡ��       "<<endl;
                         int select_Pu ;cin>>select_Pu;
                         system("cls");
				   	     if(select_Pu==1) 
						 {     
							int num3;
						    cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                    <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
					        for(i=0;i<8;i++)
							{cout<<P[i];}
							while(1)
							{
						        cout<<"��������Ҫѡ�ĿεĿγ̱��:";
						        cin>>num3;
							    for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								{ if(num3==stu.Pu[i].get_course_num()) break;}
						        if(num3==stu.Pu[i].get_course_num()) 
								{ 
						           cout<<"�ÿγ���ѡ!����������!"<<endl;
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
						          cout<<"ѡ�γɹ�!"<<endl;
							      cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                          <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
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
						    cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                    <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
					        for(i=8;i<16;i++)
							{cout<<P[i];}
							while(1)
							{
						         cout<<"��������Ҫѡ�ĿεĿγ̱��:";
						         cin>>num4;
							     for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								 { if(num4==stu.Pu[i].get_course_num()) break;}
						         if(num4==stu.Pu[i].get_course_num()) 
								 { 
						            cout<<"�ÿγ���ѡ!����������!"<<endl;
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
						           cout<<"ѡ�γɹ�!"<<endl;
							       cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                           <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
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
						        cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                        <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
					            for(i=16;i<25;i++)
								{cout<<P[i];}
							while(1)
							{
						        cout<<"��������Ҫѡ�ĿεĿγ̱��:";
						        cin>>num5;
							    for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								{ if(num5==stu.Pu[i].get_course_num()) break;}
						        if(num5==stu.Pu[i].get_course_num()) 
								{ 
						           cout<<"�ÿγ���ѡ!����������!"<<endl;
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
						           cout<<"ѡ�γɹ�!"<<endl;
							       cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                           <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
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
							 {cout<<"��ǰ�޿γ�!"<<endl;}
							 else
							 {  
                                cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                        <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
						        for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								{cout<<stu.Pu[i];}
							 }
						     break;
						 }
				         if(select_Pu==5)
						 {   
                             if(stu.Pu[0].get_course_name()=="\0")
							 {cout<<"��ǰ�޿γ�!"<<endl;}
							 else
							 {   
								while(1)
								{
								   cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                           <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
                                   for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								   {cout<<stu.Pu[i];}
	                               int k2;
						           cout<<"��������Ҫ��ѡ�Ŀγ̱��:";
					               cin>>k2;
								   for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
								   { if(k2==stu.Pu[i].get_course_num()) break;}
								   if(k2!=stu.Pu[i].get_course_num()) 
								   {  system("cls");
								      cout<<"���������޵�ǰ�γ�!����������!"<<endl;
									  cout<<endl;
									  continue;
								   }
								   else
								   {
                                      stu.delete_Publiccourse(k2);
								      system("cls");
						              cout<<"��ѡ�ɹ�!"<<endl;
								      cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                              <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
                                      for(i=0;stu.Pu[i].get_course_name()!="\0";i++)
									  {cout<<stu.Pu[i];}
									  break;
								   }
								}
							 }
						   break;
						 }
				   	     else {system("cls");cout<<"�����������������롣"<<endl;continue;}
					  }
			          break;


          case 3://ѡ�޿Σ�
                  while(1)
				  {
				  cout<<"^^^^^^^  ѡ�޿�  ^^^^^^^"<<endl;
				  cout<<"     1���鿴ѡ�޿�"<<endl;
                  cout<<"     2���鿴��ѡ�γ�    "<<endl;
				  cout<<"     3����ѡ�γ�        "<<endl;
				  cout<<"^^^^^^^ ���������ѡ��^^^^^^^"<<endl;
				  int select_El1;
				  cin>>select_El1;
                  system("cls");
				   switch(select_El1)
				   {
				    case 1:
						  while(1)
						  { system("cls");
					        cout<<"   1���鿴���пγ�       "<<endl;
					        cout<<"   2����ѧ�ֲ鿴�γ�     "<<endl;
					        cout<<"   3������ѧʱ�鿴�γ�   "<<endl;
							cout<<"   ���������ѡ��      "<<endl;
							int select_El2;
							cin>>select_El2;
							switch(select_El2)
							{
							case 1: 
								    cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                            <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl; 
								    for(i=0;i<25;i++)
									{E[i].search_nature();}
									cout<<" �Ƿ�Ҫ����ѡ�Σ� 1����  2���� "<<endl;
									int n1;cin>>n1;
									switch(n1)
									{
									    case 1:
										//����ѡ��
											int num6;
											cout<<"��������Ҫѡ�Ŀγ̵�����:";
											cin>>num6;
											for(i=0;i<num6;i++)
											{   int num7;int j;int a7;
												cout<<"��������Ҫѡ��Ŀγ̵ı��:";
												cin>>num7;
												for(j=0;stu.El[j].get_course_name()!="\0";j++)
												{ if(num7==stu.El[j].get_course_num()) break;}
												if(num7==stu.El[j].get_course_num()) 
												{ 
													cout<<"�ÿγ���ѡ!����������!"<<endl;
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
													  cout<<"�ÿγ�����ѡ�γ����ڳ�ͻ,����������!"<<endl;
												      num6=num6+1;
												  }
												  else
												  {
												    for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												    stu.El[j]=E[a7];
												    cout<<"ѡ�γɹ�!"<<endl;
                                                    cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                            <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											        for(j=0;stu.El[j].get_course_name()!="\0";j++)
													{cout<<stu.El[j];}
												  }
												}
											}
										   break;
										case 2:
										//������ѡ�εĻ��ͻص�Ҫ���鿴�γ̻��ǰ�ѧ�ֲ鿴���Ǹ�ҳ��
											break;
										
                                        default:system("cls"); 
											    cout<<"��������"<<endl;
											    break; 
									}
						    break;

                            case 2:
                                  while(1)
								  {   system("cls");
									  cout<<"1�� 1.0ѧ��    2�� 1.5ѧ��   3��2.0ѧ��  "<<endl;
									  cout<<"���������ѡ��"<<endl;
									  int select_El3;cin>>select_El3;
									  switch(select_El3)
									  {
                                           case 1:
												 //po��1ѧ�ֵ�ѡ�޿Σ���Ϊ���ܿ�ѡ�Ŀβ����ˣ�����ѡ��ʦ�Ļ��Ϳ��Բ��ð���ʦ����ѯ�����û�ϲ���Ǹ���ѡ�Ǹ���
											     cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                         <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											     for(i=0;i<25;i++)
												 {E[i].search_credit(1.0);}
											     cout<<"�Ƿ����ѡ�Σ�  1����   2����"<<endl;
											     int n2;cin>>n2;
									             switch(n2)
												 {
									              case 1:
									                	//����ѡ��
													    int num8;
											            cout<<"��������Ҫѡ�Ŀγ̵�����:";
											            cin>>num8;
											            for(i=0;i<num8;i++)
														{   int num9;int j;int a9;
											 	            cout<<"��������Ҫѡ��Ŀγ̵ı��:";
												            cin>>num9;
															for(j=0;stu.El[j].get_course_name()!="\0";j++)
															{ if(num9==stu.El[j].get_course_num()) break;}
												            if(num9==stu.El[j].get_course_num()) 
															{ 
													          cout<<"�ÿγ���ѡ!����������!"<<endl;
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
													               cout<<"�ÿγ�����ѡ�γ����ڳ�ͻ,����������!"<<endl;
												                   num8=num8+1;
																}
																else
																{
												                   for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                   stu.El[j]=E[a9];
												                   cout<<"ѡ�γɹ�!"<<endl;
                                                                   cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                                           <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											                       for(j=0;stu.El[j].get_course_name()!="\0";j++)
																   {cout<<stu.El[j];}
																}
															}
														}
														break;
												  case 2: break;
												  //������ѡ�εĻ��ͻص�Ҫ���鿴�γ̻��ǰ�ѧ�ֲ鿴���Ǹ�ҳ��	  
                                                  default:system("cls");
													      cout<<"��������"<<endl;  
														  break; 
									 
												 }
										          break;
                                           case 2:
												   //po��1.5ѧ�ֵı��޿�
											     cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                         <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											     for(i=0;i<25;i++)
												 {E[i].search_credit(1.5);}
                                                 cout<<"�Ƿ����ѡ�Σ�  1����   2����"<<endl;
											     int n3;cin>>n3;
									                switch(n3)
													{
									                    case 1:
									                	 //����ѡ��
                                                            int num10;
											                cout<<"��������Ҫѡ�Ŀγ̵�����:";
											                cin>>num10;
											                for(i=0;i<num10;i++)
															{   int num11;int j;int a11;
											 	                cout<<"��������Ҫѡ��Ŀγ̵ı��:";
												                cin>>num11;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num11==stu.El[j].get_course_num()) break;}
												                if(num11==stu.El[j].get_course_num()) 
																{ 
												                    cout<<"�ÿγ���ѡ!����������!"<<endl;
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
													                   cout<<"�ÿγ�����ѡ�γ����ڳ�ͻ,����������!"<<endl;
												                       num10=num10+1;
																	}
																	else
																	{
												                      for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                      stu.El[j]=E[a11];
												                      cout<<"ѡ�γɹ�!"<<endl;
															          cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                                              <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											                          for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	  {cout<<stu.El[j];}
																	}
																}
															}
															break;
														case 2: break;
												      //������ѡ�εĻ��ͻص�Ҫ���鿴�γ̻��ǰ�ѧ�ֲ鿴���Ǹ�ҳ��	  
                                                     default :system("cls");
														      cout<<"��������"<<endl; 
															  break; 
									 
													}
									             break;
										   case 3:
												   //po��2ѧ�ֵı��޿�
											         cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                             <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											         for(i=0;i<25;i++)
													 {E[i].search_credit(2.0);}
                                                     cout<<"�Ƿ����ѡ�Σ�  1����   2����"<<endl;
											          int n4;cin>>n4;
									                   switch(n4)
													   {
									                      case 1:
									                	  //����ѡ��
                                                            int num12;
											                cout<<"��������Ҫѡ�Ŀγ̵�����:";
											                cin>>num12;
											                for(i=0;i<num12;i++)
															{   int num13;int j;int a13;
											 	                cout<<"��������Ҫѡ��Ŀγ̵ı��:";
												                cin>>num13;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num13==stu.El[j].get_course_num()) break;}
												                if(num13==stu.El[j].get_course_num()) 
																{ 
													                cout<<"�ÿγ���ѡ!����������!"<<endl;
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
													                  cout<<"�ÿγ�����ѡ�γ����ڳ�ͻ,����������!"<<endl;
												                      num12=num12+1;
																	}
																	else
																	{
												                       for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                       stu.El[j]=E[a13];
												                       cout<<"ѡ�γɹ�!"<<endl;
																       cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                                               <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											                           for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	   {cout<<stu.El[j];}
																	}
																} 
															}
															break;
														  case 2: break;
												          //������ѡ�εĻ��ͻص�Ҫ���鿴�γ̻��ǰ�ѧ�ֲ鿴���Ǹ�ҳ��	  
                                                          default :system("cls");
															       cout<<"��������"<<endl;
																   break; 
									 
													   }

											       break;

										   default : system("cls");
											         cout<<"ѡ����������ѡ"<<endl;
													 break;

									  }//switch
									  if(select_El3==1||select_El3==2||select_El3==3) break;
									  else continue;
								  }//ѭ��
							    break;

							case 3:
								
                                  while(1)
								  {
									  cout<<"1�� 16ѧʱ    2�� 32ѧʱ   3��48ѧʱ  "<<endl;
									  cout<<"���������ѡ��"<<endl;
									  int select_El4;cin>>select_El4;
									  switch(select_El4)
									  {
                                           case 1:
												 //po��16ѧʱ�ı��޿Σ���Ϊ���ܿ�ѡ�Ŀβ����ˣ�����ѡ��ʦ�Ļ��Ϳ��Բ��ð���ʦ����ѯ�����û�ϲ���Ǹ���ѡ�Ǹ���
											     cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                         <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											     for(i=0;i<25;i++)
												 {E[i].search_hours(16);}
											     cout<<"�Ƿ����ѡ�Σ�  1����   2����"<<endl;
											     int n5;cin>>n5;
									             switch(n5)
												 {
									              case 1:
									                	//����ѡ��
                                                            int num14;
											                cout<<"��������Ҫѡ�Ŀγ̵�����:";
											                cin>>num14;
											                for(i=0;i<num14;i++)
															{   int num15;int j;int a15;
											 	                cout<<"��������Ҫѡ��Ŀγ̵ı��:";
												                cin>>num15;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num15==stu.El[j].get_course_num()) break;}
												                if(num15==stu.El[j].get_course_num()) 
																{ 
													                cout<<"�ÿγ���ѡ!����������!"<<endl;
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
													                   cout<<"�ÿγ�����ѡ�γ����ڳ�ͻ,����������!"<<endl;
												                       num14=num14+1;
																	}
																	else
																	{
												                       for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                       stu.El[j]=E[a15];
												                       cout<<"ѡ�γɹ�!"<<endl;
																       cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                                               <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											                           for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	   {cout<<stu.El[j];}
																	}
																}
															}
														    break;
												  case 2: break;
												  //������ѡ�εĻ��ͻص�Ҫ���鿴�γ̻��ǰ�ѧ�ֲ鿴���Ǹ�ҳ��	  
                                                  default:system("cls");
													      cout<<"��������"<<endl; 
														  break; 
									 
												 }
												 break;
                                           case 2:
												   //po��32ѧʱ�ı��޿�
											     cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                         <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											     for(i=0;i<25;i++)
												 {E[i].search_hours(32);}
                                                 cout<<"�Ƿ����ѡ�Σ�  1����   2����"<<endl;
											     int n6;cin>>n6;
									                switch(n6)
													{
									                    case 1:
									                	 //����ѡ��
                                                            int num16;
											                cout<<"��������Ҫѡ�Ŀγ̵�����:";
											                cin>>num16;
											                for(i=0;i<num16;i++)
															{   int num17;int j;int a17;
											 	                cout<<"��������Ҫѡ��Ŀγ̵ı��:";
												                cin>>num17;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num17==stu.El[j].get_course_num()) break;}
												                if(num17==stu.El[j].get_course_num()) 
																{ 
													                cout<<"�ÿγ���ѡ!����������!"<<endl;
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
													                   cout<<"�ÿγ�����ѡ�γ����ڳ�ͻ,����������!"<<endl;
												                       num16=num16+1;
																	}
																	else
																	{
												                       for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                       stu.El[j]=E[a17];
												                       cout<<"ѡ�γɹ�!"<<endl;
																       cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                                               <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											                           for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	   {cout<<stu.El[j];}
																	}
																}
															}
															break;
														case 2: break;
												      //������ѡ�εĻ��ͻص�Ҫ���鿴�γ̻��ǰ�ѧ�ֲ鿴���Ǹ�ҳ��	  
                                                     default :system("cls");
														      cout<<"��������"<<endl; 
															  break; 
									 
													}
											   break;
										   case 3:
											  
												   //po��48ѧʱ�ı��޿�
											       cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                           <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											       for(i=0;i<25;i++)
												   {E[i].search_hours(48);}
                                                     cout<<"�Ƿ����ѡ�Σ�  1����   2����"<<endl;
											          int n7;cin>>n7;
									                   switch(n7)
													   {
									                      case 1:
									                	  //����ѡ��
                                                            int num18;
											                cout<<"��������Ҫѡ�Ŀγ̵�����:";
											                cin>>num18;
											                for(i=0;i<num18;i++)
															{   int num19;int j;int a19;
											 	                cout<<"��������Ҫѡ��Ŀγ̵ı��:";
												                cin>>num19;
																for(j=0;stu.El[j].get_course_name()!="\0";j++)
																{ if(num19==stu.El[j].get_course_num()) break;}
												                if(num19==stu.El[j].get_course_num()) 
																{ 
												 	                cout<<"�ÿγ���ѡ!����������!"<<endl;
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
													                   cout<<"�ÿγ�����ѡ�γ����ڳ�ͻ,����������!"<<endl;
												                       num18=num18+1;
																	}
																	else
																	{
												                      for(j=0;stu.El[j].get_course_name()!="\0";j++) {}
												                      stu.El[j]=E[a19];
												                      cout<<"ѡ�γɹ�!"<<endl;
																      cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                                                              <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
											                          for(j=0;stu.El[j].get_course_name()!="\0";j++)
																	  {cout<<stu.El[j];}
																	}
																}
															}
															  break;
														  case 2: break;
												          //������ѡ�εĻ��ͻص�Ҫ���鿴�γ̻��ǰ�ѧ�ֲ鿴���Ǹ�ҳ��	  
                                                          default :system("cls");
															       cout<<"��������"<<endl; 
																   break; 
									 
													   }

											      break;
										   default : system("cls");
											         cout<<"ѡ����������ѡ"<<endl;
													 break;

									  }//switch
									  if(select_El4==1||select_El4==2||select_El4==3) break;
									  else continue;
								  }//ѭ��

								break;
                            default:system("cls");
								    cout<<"������������������"<<endl; 
									break;
							}//switch_select_El2
                            if(select_El2==1||select_El2==2||select_El2==3) break;
							else continue;
						  }//ѭ��
                   break;
                  case 2://�鿴��ѡ��ѡ�޿�
					  //po����ѡ�˵�ѡ�޿γ�
					  system("cls");
					  if(stu.El[0].get_course_name()=="\0")
					  {cout<<"��ǰ�޿γ�!"<<endl;}
					  else
					  {   
						  cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                  <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
					      for(i=0;stu.El[i].get_course_name()!="\0";i++)
						  {cout<<stu.El[i];}
					  }
					  break;  
				  case 3://��ѡ�γ�
					  system("cls");
                      if(stu.El[0].get_course_name()=="\0")
					  {cout<<"��ǰ�޿γ�!"<<endl;}
					  else
					  {   
						  while(1)
						  {
						    cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                    <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
                            for(i=0;stu.El[i].get_course_name()!="\0";i++)
							{cout<<stu.El[i];}
					        int num20;
					        cout<<"������Ҫ��ѡ�Ŀγ̵ı��:";
                            cin>>num20;
						    for(i=0;stu.El[i].get_course_name()!="\0";i++)
							{ if(num20==stu.El[i].get_course_num()) break;}
						    if(num20!=stu.El[i].get_course_num()) 
							{   system("cls");
								cout<<"���������޵�ǰ�γ�!����������!"<<endl;
								cout<<endl;
						        continue;
							}
						    else
							{
					          stu.delete_Elctivecourse(num20);
						      system("cls");
					          cout<<"��ѡ�ɹ�!"<<endl;
						      cout<<"|�γ̱��| "<<"�γ�����|"<<"�γ�����|"<<"��ѧʱ|"
		                      <<"�ڿ�ѧʱ|"<<"ʵ����ϻ�ѧʱ|"<<"ѧ��|"<<"����ѧ��|"<<"��ʦ|"<<"����|"<<endl;
					          for(i=0;stu.El[i].get_course_name()!="\0";i++)
							  {cout<<stu.El[i];}
						      break;
							}
						  }
					  }
                       break;
				  default: system("cls");
					       cout<<"��������������ѡ��"<<endl; 
						   break;

				}//switch_select_El1
				if(select_El1==1||select_El1==2||select_El1==3) break;
				else continue;
			  }
			break;

		  case 4://�˳�ϵͳ��
			 break;
		  default: system("cls");
			       cout<<"�Բ����������"<<endl;
				   cout<<"���ٴ�������ȷ��ѡ��"<<endl; break;

		}//switch_select_num_HWN
		if(select_num_HWN==4) break;
		else continue;
	  }//5��ѭ��
	   break;}//4
	   else {system("cls");cout<<"�����������������!"<<endl;continue;}
     break;}//3
	 else{system("cls");cout<<"�û�����������������!"<<endl;continue;}
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
   cout<<"���Ѿ��ɹ��˳�ϵͳ!"<<endl;
   return 0;
}//1