#include <QCoreApplication>
#include <iostream>
#include <percentfolderdata.h>
#include <calculatedstrategydata.h>
#include <QVector>
#include <calculationstrategy.h>
#include <calculationstaretegybytype.h>
#include <calculationstrategybyfolder.h>

using namespace std;

QVector<PercentFolderData> convertByteToPercent(QVector<CalculatedStrategyData> byteFormatData) {
    qint64 totalSize = 0;
    for (int i = 0; i < byteFormatData.length(); i++) {
        totalSize += byteFormatData[i].getSize();
    }
    QVector<PercentFolderData> result;
    for (int i = 0; i < byteFormatData.length(); i++) {
        result.push_back(PercentFolderData(byteFormatData[i].getSign(), (double)byteFormatData[i].getSize()/(double)totalSize * 100));
    }
    return result;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    int strategyName;
    QString testPath = ""; // Вставить путь
    while (1) {
        cin >> strategyName;
        CalculationStrategy * strategy;
        switch (strategyName)
        {
        case 1:
            strategy = new CalculationStrategyByFolder();
            cout << "---Folder Strategy---" << endl;
            break;
        case 2:
            strategy = new CalculationStaretegyByType();
            cout << "---Type Strategy---" << endl;
            break;
        default :
            strategy = new CalculationStrategy();
            break;
        }
        QVector<PercentFolderData> result = convertByteToPercent(strategy->calculation(testPath));
        for (int i = 0; i < result.length(); i++) {
            cout << result[i].getSign().toStdString() << " - " << result[i].getSize() << endl;
        }
    }
    return a.exec();
}
