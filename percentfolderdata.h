#ifndef PERCENTFOLDERDATA_H
#define PERCENTFOLDERDATA_H
#include<QString>

class PercentFolderData
{
public:
    PercentFolderData() = default;
    PercentFolderData(QString newSign, float newSize) {
        sign = newSign;
        size = newSize;
    }
    float getSize(){
        return size;
    }
    QString getSign(){
        return sign;
    }
private:
    float size;
    QString sign;
};

#endif // PERCENTFOLDERDATA_H
