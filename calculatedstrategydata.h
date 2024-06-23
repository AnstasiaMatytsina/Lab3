#ifndef DATA_H
#define DATA_H
#include<QString>

class CalculatedStrategyData
{
public:
    CalculatedStrategyData() = default;
    CalculatedStrategyData(QString newSign, qint64 newSize) {
        sign = newSign;
        size = newSize;
    }
    qint64 getSize(){
        return size;
    }
    QString getSign(){
        return sign;
    }
private:
    qint64 size;
    QString sign;
};

#endif // DATA_H
