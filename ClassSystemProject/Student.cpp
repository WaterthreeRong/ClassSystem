#include"Student.h"
void Student_HWN::delete_Publiccourse(int a)//退选公共课
{int i;
 for(i=0;Pu[i].course_name!="\0";i++)
 {if(a==Pu[i].course_num) break;}
 for(;Pu[i].course_name!="\0";i++)
 {Pu[i]=Pu[i+1];}
}
void Student_HWN::delete_Requiredcourse(int a)//退选必修课
{int i;
 for(i=0;Re[i].course_name!="\0";i++)
 {if(a==Re[i].course_num) break;}
 for(;Re[i].course_name!="\0";i++)
 {Re[i]=Re[i+1];}
}
void Student_HWN::delete_Elctivecourse(int a)//退选选修课
{int i;
 for(i=0;El[i].course_name!="\0";i++)
 {if(a==El[i].course_num) break;}
 for(;El[i].course_name!="\0";i++)
 {El[i]=El[i+1];}
}
ostream & operator<<(ostream &output,Student_HWN &a)
{output<<a.num<<" "<<a.Class<<" "<<a.name<<" "<<endl<<a.Pu[1]<<a.Pu[2]<<a.Pu[3]<<a.Pu[4]<<a.Pu[5]<<a.Re[1]<<a.Re[2]<<a.Re[3]
 <<a.Re[4]<<a.Re[5]<<a.El[1]<<a.El[2]<<a.El[3]<<a.El[4]<<a.El[5];
return output;
}
istream & operator>>(istream &input,Student_HWN &a)
{input>>a.num>>a.Class>>a.name>>a.Pu[1]>>a.Pu[2]>>a.Pu[3]>>a.Pu[4]>>a.Pu[5]>>a.Re[1]>>a.Re[2]>>a.Re[3]
 >>a.Re[4]>>a.Re[5]>>a.El[1]>>a.El[2]>>a.El[3]>>a.El[4]>>a.El[5];
return input;
}