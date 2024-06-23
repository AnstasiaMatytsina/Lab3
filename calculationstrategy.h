#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H
#include <QString>
#include <calculatedstrategydata.h>
#include <QVector>

class CalculationStrategy
{
public:
    CalculationStrategy() = default;
    virtual QVector<CalculatedStrategyData> calculation(QString path) {
        throw std::runtime_error("Strategy not supported");
    }
};

#endif // CALCULATIONSTRATEGY_H
