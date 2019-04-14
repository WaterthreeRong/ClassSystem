#include"Course_ZR.h"
class Public_course_ZR;
class Required_course_ZR;
class ElctiveCourse_HWN;
ostream & operator<<(ostream &,Public_course_ZR &);
istream & operator>>(istream &,Public_course_ZR &);
ostream & operator<<(ostream &,Required_course_ZR &);
istream & operator>>(istream &,Required_course_ZR &);
ostream & operator<<(ostream &,ElctiveCourse_HWN &);
istream & operator>>(istream &,ElctiveCourse_HWN &);
class Public_course_ZR:public Course_ZR
{public:
    void data_show()
	{
	   cout<<course_num<<" "<<course_name<<" "<<course_nature<<" "<<all_hours
	      <<" "<<teach_hours<<" "<<practice_hours<<" "<<credit<<" "<<term<<" "<<teacher<<" "<<day<<endl;
	 }
    virtual void search_credit(float n);//用于按学分查找课程信息
	virtual void search_nature();//用于查找课程类型
	virtual void search_hours(int h);//用于按总学时查找课程信息
    friend ostream & operator<<(ostream &,Public_course_ZR &);
    friend istream & operator>>(istream &,Public_course_ZR &);
    string get_teacher(){return teacher;}
private:
	string teacher;
};
class Required_course_ZR:public Course_ZR
{public:
    void data_show()
	{
	     cout<<course_num<<" "<<course_name<<" "<<course_nature<<" "<<all_hours
	      <<" "<<teach_hours<<" "<<practice_hours<<" "<<credit<<" "<<term<<" "<<teacher<<" "<<day<<endl;
	 }
    virtual void search_credit(float n);//用于按学分查找课程信息
	virtual void search_nature();//用于查找课程类型
	virtual void search_hours(int h);//用于按总学时查找课程信息
    friend ostream & operator<<(ostream &,Required_course_ZR &);
    friend istream & operator>>(istream &,Required_course_ZR &);
	string get_teacher(){return teacher;}
private:
	string teacher;
};
class ElctiveCourse_HWN :public Course_ZR
{
  public: 
	 void data_show()
	  {
	     cout<<course_num<<" "<<course_name<<" "<<course_nature<<" "<<all_hours
	      <<" "<<teach_hours<<" "<<practice_hours<<" "<<credit<<" "<<term<<" "<<teacher<<" "<<day<<endl;
	 }
     friend ostream & operator<<(ostream &,ElctiveCourse_HWN &);
	 friend istream & operator>>(istream &,ElctiveCourse_HWN &);
     void search_credit(float n);
	 void search_nature();
	 void search_hours(int h);
     string get_teacher(){return teacher;}
private:
	string teacher;
 };

