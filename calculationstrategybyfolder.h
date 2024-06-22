#ifndef CALCULATIONSTRATEGYBYFOLDER_H
#define CALCULATIONSTRATEGYBYFOLDER_H
#include <calculationstrategy.h>
#include <QFileInfo>
#include <QDirIterator>
#include <QVector>

class CalculationStrategyByFolder : public CalculationStrategy
{
public:
    CalculationStrategyByFolder() = default;
    QVector<CalculatedStrategyData> calculation(QString path) override {
        QFileInfo pathValue(path);
        if (pathValue.isDir() != 1) {
            throw std::runtime_error("Path value is not directory");
        }
        QDirIterator dirIterator(path, QDir::Dirs | QDir::NoDotAndDotDot);
        QVector<CalculatedStrategyData> result;
        while(dirIterator.hasNext())
        {
           QString dirPath = dirIterator.next();
           QString dirName = dirIterator.fileName();
           qint64 dirSize = 0;
           QDirIterator subDirIterator(dirPath, QDir::Files, QDirIterator::Subdirectories);
           while(subDirIterator.hasNext()) {
               QString subFilePath = subDirIterator.next();
               QFileInfo file(subFilePath);
               dirSize += file.size();
           }
           result.push_back(CalculatedStrategyData(dirName, dirSize));
        }
        return result;
    }
};

#endif // CALCULATIONSTRATEGYBYFOLDER_H
