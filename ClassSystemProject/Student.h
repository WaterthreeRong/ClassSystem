#include"All_course.h"
class Student_HWN;
ostream & operator<<(ostream &,Student_HWN &);
istream & operator>>(istream &,Student_HWN &);
class Student_HWN 
{ 
public:
     void delete_Publiccourse(int);//��ѡ������
	 void delete_Requiredcourse(int);//��ѡ���޿�
	 void delete_Elctivecourse(int);//��ѡѡ�޿�
	//int loading();//ѧ����½�����ѡ�޿γ�ϵͳ
    //�ɲ����Դ��ļ��а�����Ū�������ϣ��ù��캯������ʵ����
    //Student_HWN();     
	friend ostream & operator<<(ostream &,Student_HWN &);
    friend istream & operator>>(istream &,Student_HWN &);
	int get_num(){return num;}
	string get_Class(){return Class;}
	string get_name(){return name;}
    int get_personal_num(){return personal_num;}
	int get_personal_password(){return personal_password;}
    Public_course_ZR Pu[5];
	Required_course_ZR Re[5];
    ElctiveCourse_HWN El[5];
	int num; string Class; string name; 
	int personal_num;int personal_password;	
};
