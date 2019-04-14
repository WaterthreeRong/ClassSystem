#include"All_course.h"
class Student_HWN;
ostream & operator<<(ostream &,Student_HWN &);
istream & operator>>(istream &,Student_HWN &);
class Student_HWN 
{ 
public:
     void delete_Publiccourse(int);//退选公共课
	 void delete_Requiredcourse(int);//退选必修课
	 void delete_Elctivecourse(int);//退选选修课
	//int loading();//学生登陆进这个选修课程系统
    //可不可以从文件中把数据弄到数组上，用构造函数可以实现吗？
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
