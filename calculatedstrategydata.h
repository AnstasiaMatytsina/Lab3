#ifndef DATA_H
#define DATA_H
#include<QString>


class Data
{
public:
    Data(qint64 newSize,QString newName){
        name=newName;
        size=newSize;
    }
    qint64 getSize(){
        return size;
    }
    QString getName(){
        return name;
    }
private:
    qint64 size;
    QString name;
};

#endif // DATA_H
