#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H
#include <QString>
#include <calculatedstrategydata.h>

class CalculationStrategy
{
public:
    CalculationStrategy() = default;
    virtual QVector<CalculatedStrategyData> calculation(QString path) = 0;
};

#endif // CALCULATIONSTRATEGY_H
