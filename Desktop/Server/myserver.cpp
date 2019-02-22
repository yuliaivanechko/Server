#include "myserver.h"

myserver::myserver(){};
myserver::~myserver(){};

void myserver::startServer()
{
    if (this->listen(QHostAddress::Any,1050))
    {
        qDebug()<<"Listening";
    }
    else
    {
        qDebug()<<"Not listening";
    }
}
void myserver::incomingConnection(int socketDescriptor)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()),this,SLOT(sockReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisk()));

    qDebug()<<socketDescriptor<<"Client Connected";
    socket->write("You are connected");
    qDebug()<<"Send client connect status - YES";
}
void myserver::sockReady()
{

}

void myserver::sockDisk()
{
    qDebug()<<"Disconnect";
    socket->deleteLater();

}
