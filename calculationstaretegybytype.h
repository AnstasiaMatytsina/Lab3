#ifndef CALCULATIONSTARETEGYBYTYPE_H
#define CALCULATIONSTARETEGYBYTYPE_H
#include <calculationstrategy.h>

class CalculationStaretegyByType : public CalculationStrategy
{
public:
    CalculationStaretegyByType();
    QVector<CalculatedStrategyData> calculation(QString path) override;
};

#endif // CALCULATIONSTARETEGYBYTYPE_H
