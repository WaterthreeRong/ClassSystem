1.直接使用双击名为a.exe的可执行文件或者在windows系统命令行下执行该文件
2.使用windows系统的命令行编译运行
1）在命令行下进入到项目所在的学生选课系统的文件夹
2）进行cpp文件的编译，编译语句为：g++ All_course.cpp Student.cpp main.cpp
3）编译成功后会在原来的文件夹下生成一个后缀为exe可执行文件，一般来说应该为a.exe
4）运行exe可执行文件，即在弹出的下一条命令行中输入文件完整名称即可运行（即输入a.exe）
3.使用Viusal C++ 6.0进行编译运行
1）在该环境下将学生选课系统这个项目文件夹导入
2）找到文件列表中的cpp文件，首先编译All_course.cpp，其次为Student.cpp，最后编译main.cpp
3）编译完成后可以直接在main.cpp下运行即可