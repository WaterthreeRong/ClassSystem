#include<string>
#include<iostream>
using namespace std;
class Student_HWN;
class Course_ZR
{protected:
    int course_num;
    string course_name;
    string course_nature;
    int all_hours;
    int teach_hours;
    int practice_hours;
    float credit;
    string term;
	string day;
public:
    virtual void data_show()=0;//���������ʾ��Ϣ
    virtual void search_credit(float n)=0;//���ڰ�ѧ�ֲ��ҿγ���Ϣ
	virtual void search_nature()=0;//���ڲ��ҿγ�����
	virtual void search_hours(int h)=0;//���ڰ���ѧʱ���ҿγ���Ϣ
	int get_course_num(){return course_num;}
	string get_course_name(){return course_name;}
	string get_course_nature(){return course_nature;}
	int get_all_hours(){return all_hours;}
	int get_teach_hours(){return teach_hours;}
	int get_practice_hours(){return practice_hours;}
	float get_credit(){return credit;}
	string get_term(){return term;}
	string get_day(){return day;}
    friend Student_HWN;
};
