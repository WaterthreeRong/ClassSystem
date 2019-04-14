#include"All_course.h"
void Public_course_ZR::search_credit(float n)
 {if(n==credit) data_show();}
 void Public_course_ZR::search_nature()
 {data_show();}
 void Public_course_ZR::search_hours(int h)
 {if(h==all_hours) data_show();}
 ostream & operator<<(ostream &output,Public_course_ZR &a)
 {output<<a.course_num<<" "<<a.course_name<<" "<<a.course_nature<<" "<<a.all_hours<<" "<<a.teach_hours<<" "<<a.practice_hours
 <<" "<<a.credit<<" "<<a.term<<" "<<a.teacher<<" "<<a.day<<endl;
 return output;
 }
 istream & operator>>(istream &input,Public_course_ZR &a)
 {input>>a.course_num>>a.course_name>>a.course_nature>>a.all_hours>>a.teach_hours>>a.practice_hours>>a.credit>>a.term>>a.teacher>>a.day;
 return input;
 }
 void Required_course_ZR::search_credit(float n)
 {if(n==credit) data_show();}
 void Required_course_ZR::search_nature()
 {data_show();}
 void Required_course_ZR::search_hours(int h)
 {if(h==all_hours) data_show();}
 ostream & operator<<(ostream &output,Required_course_ZR &a)
 {output<<a.course_num<<" "<<a.course_name<<" "<<a.course_nature<<" "<<a.all_hours<<" "<<a.teach_hours<<" "<<a.practice_hours
 <<" "<<a.credit<<" "<<a.term<<" "<<a.teacher<<" "<<a.day<<endl;
 return output;
 }
 istream & operator>>(istream &input,Required_course_ZR &a)
 {input>>a.course_num>>a.course_name>>a.course_nature>>a.all_hours>>a.teach_hours>>a.practice_hours>>a.credit>>a.term>>a.teacher>>a.day;
 return input;
 }
void ElctiveCourse_HWN::search_credit(float n)
{if(n==credit) data_show();}

void ElctiveCourse_HWN::search_nature()
{data_show();}

void ElctiveCourse_HWN::search_hours(int h)
{if(h==all_hours) data_show(); }

ostream & operator<<(ostream & output,ElctiveCourse_HWN &EC )
{
 output<<EC.course_num<<" "<<EC.course_name<<" "<<EC.course_nature<<" "<<EC.all_hours<<" "<<EC.teach_hours<<" "<<EC.practice_hours
 <<" "<<EC.credit<<" "<<EC.term<<" "<<EC.teacher<<" "<<EC.day<<endl;
 return output;
}
istream & operator>>(istream &input,ElctiveCourse_HWN &a)
{input>>a.course_num>>a.course_name>>a.course_nature>>a.all_hours>>a.teach_hours>>a.practice_hours>>a.credit>>a.term>>a.teacher>>a.day;
 return input;
}

