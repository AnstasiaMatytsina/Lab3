#ifndef CALCULATIONSTARETEGYBYTYPE_H
#define CALCULATIONSTARETEGYBYTYPE_H
#include <calculationstrategy.h>
#include <QFileInfo>
#include <QDirIterator>
#include <QVector>

class CalculationStaretegyByType : public CalculationStrategy
{
public:
    CalculationStaretegyByType() = default;
    QVector<CalculatedStrategyData> calculation(QString path) override {
        QFileInfo pathValue(path);
        if (pathValue.isDir() != 1) {
            throw std::runtime_error("Path value is not directory");
        }
        QDirIterator dirIterator(path, QDir::Files, QDirIterator::Subdirectories);
        std::map<QString, qint64> typesInfo;
        while(dirIterator.hasNext())
        {
           QString filePath = dirIterator.next();
           QFileInfo file(filePath);
           typesInfo[file.suffix()] += file.size();
        }
        QVector<CalculatedStrategyData> result;
        for (auto typeInfo : typesInfo) {
            result.push_back(CalculatedStrategyData(typeInfo.first, typeInfo.second));
        }
        return result;
    }
};

#endif // CALCULATIONSTARETEGYBYTYPE_H
