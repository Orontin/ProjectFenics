#include "schemeobliquefilereadrnx.h"

#include <QString>
#include <QList>

#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeObliqueFileReadRNX::SchemeObliqueFileReadRNX(): AbstractSchemeFileRead("rnx", "Renyxa")
{

}

SchemeObliqueFileReadRNX::~SchemeObliqueFileReadRNX()
{

}

AbstractSchemeChartView &SchemeObliqueFileReadRNX::readScheme(QByteArray byteArray, QString name)
{
    int isNode1_2;
    int countHalfrow;
    int countThreads;
    QList<int> nodeDirections;
    QList<QBrush> colorThreads;

    QByteArray byteArrayHex = byteArray.toHex();
    if (byteArrayHex.size() >= 24 && byteArrayHex.size() % 2 == 0) {
        countThreads = readCountLine(byteArrayHex);
        countHalfrow = readCountRow(byteArrayHex);
        if (countThreads >= 3) {
            if (countHalfrow >= 2) {
                int countBitColorAndDirection = (countThreads * 8) + (((countHalfrow / 2) * (countThreads - 1)) * 2);
                if (byteArrayHex.size() == countBitColorAndDirection) {
                    isNode1_2 = true;
                    colorThreads = readListColorThreads(byteArrayHex, countThreads);
                    nodeDirections = readListKnotDirections(byteArrayHex, (countHalfrow / 2) * (countThreads - 1));
                } else {
                    throw QString("Файл поврежден!\n"
                                  "Файл содержит неверную структуру.\n"
                                  "В файле должны быть записаны биты.\n"
                                  "В файле содержится битов: %1.\n"
                                  "В файле должно быть битов: %2.").arg(16 + byteArrayHex.size(), 16 + countBitColorAndDirection);
                }
            } else {
                throw QString("Файл не поддерживается!\n"
                              "Файл содержит неверное количество строк: %1.\n"
                              "Поддерживоемое количесво строк от 2.").arg(countHalfrow);
            }
        } else {
            throw QString("Файл не поддерживается!\n"
                          "Файл содержит неверное количество нитей: %1.\n"
                          "Поддерживоемое количесво нитей от 3.").arg(countThreads);
        }
    } else {
        throw QString("Файл поврежден!\n"
                      "Файл содержит неверную структуру.\n"
                      "В файле должны быть записаны биты.\n"
                      "В файле содержится битов: %1.\n"
                      "В файле должно быть минимум 24 бита и количество битов в файле должно делиться на 2 без остатка.").arg(byteArrayHex.size());
    }

    return *(new SchemeObliqueChartView(countThreads, countHalfrow, isNode1_2, nodeDirections, colorThreads, name));
}

int SchemeObliqueFileReadRNX::readCountLine(QByteArray &byteArray)
{
    int result = readInteger(byteArray);
    if (result > 0) {
        return result;
    } else {
        throw QString("Файл поврежден!\n"
                      "Повреждены первые или вторые 8 бит.\n"
                      "В файле записаны первые или вторые 8 бит как '00000000'.\n"
                      "В файле должно быть от '01000000' до 'ffffffff' первых и вторых бит.");
    }
}

int SchemeObliqueFileReadRNX::readCountRow(QByteArray &byteArray)
{
    int result = readInteger(byteArray);
    if (result > 0) {
        return result * 2;
    } else {
        throw QString("Файл поврежден!\n"
                      "Повреждены первые или вторые 8 бит.\n"
                      "В файле записаны первые или вторые 8 бит как '00000000'.\n"
                      "В файле должно быть от '01000000' до 'ffffffff' первых и вторых бит.");
    }
}

int SchemeObliqueFileReadRNX::readInteger(QByteArray &byteArray)
{
    QByteArray integer;
    for (int i = 0; i < 4; ++i) {
        QByteArray oneBlockByte;
        for (int j = 0; j < 2; ++j) {
            oneBlockByte = oneBlockByte + byteArray.front();
            byteArray.remove(0, 1);
        }
        integer.push_front(oneBlockByte);
    }
    return integer.toInt(nullptr, 16);
}

QList<QBrush> SchemeObliqueFileReadRNX::readListColorThreads(QByteArray &byteArray, int countThreads)
{
    QList<QBrush> threadColor;
    for (int i = 0; i < countThreads; ++i) {
        QByteArray string = "#";
        for (int j = 0; j < 8; ++j) {
            if (j < 6) {
                string.push_back(byteArray.front());
            }
            byteArray.remove(0, 1);
        }
        threadColor.push_back(QBrush(QColor(QString::fromStdString(string.toStdString()))));
    }
    return threadColor;
}

QList<int> SchemeObliqueFileReadRNX::readListKnotDirections(QByteArray &byteArray, int countHalfrow)
{
    QList<int> nodeDirections;
    for (int i = 0; i < countHalfrow; ++i) {
        QByteArray string;
        for (int j = 0; j < 2; ++j) {
            string.push_back(byteArray.front());
            byteArray.remove(0, 1);
        }
        int direcion = string.toInt(nullptr, 16);
        if (direcion >= 0 && direcion <= 7) {
            switch (direcion) {
                case 0:
                case 1:
                    direcion = 1;
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                default:
                    continue;
            }
            nodeDirections.push_back(direcion);
        } else {
            throw QString("Файл поврежден!\n"
                          "Считая с конца файла повреждены биты в позициях: %1 - %2.\n"
                          "В файле записаны биты как: %3.\n"
                          "В файле должно быть от '00' до '07' бит.").arg(byteArray.size() + 2, byteArray.size() + 1, direcion);
        }
    }
    return nodeDirections;
}
