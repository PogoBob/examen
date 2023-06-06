#include <QCoreApplication>
#include <mytcpserver.h>
//Выполнил Доброзоров Егор Денисович 221-332

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyTcpServer server;
    return a.exec();
}
