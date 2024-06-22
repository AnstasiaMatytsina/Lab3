#ifndef CALCULATIONSTRATEGYBYFOLDER_H
#define CALCULATIONSTRATEGYBYFOLDER_H
#include <calculationstrategy.h>

class CalculationStrategyByFolder : public CalculationStrategy
{
public:
    CalculationStrategyByFolder() = default;
    QVector<CalculatedStrategyData> calculation(QString path) override;
};

#endif // CALCULATIONSTRATEGYBYFOLDER_H
