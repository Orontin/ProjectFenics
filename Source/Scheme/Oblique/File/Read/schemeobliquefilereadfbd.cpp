#include "schemeobliquefilereadfbd.h"

#include <QString>
#include <QList>

#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeObliqueFileReadFBD::SchemeObliqueFileReadFBD(): AbstractSchemeFileRead("fbd", "Friendship Bracelet Designer")
{

}

SchemeObliqueFileReadFBD::~SchemeObliqueFileReadFBD()
{

}

AbstractSchemeChartView &SchemeObliqueFileReadFBD::readScheme(QByteArray byteArray, QString name)
{
    int isNode1_2;
    int countHalfrow;
    int countThreads;
    QList<int> nodeDirections;
    QList<QBrush> colorThreads;

    QByteArray byteArrayHex = byteArray.toHex();
    if (byteArrayHex.size() >= 42 && byteArrayHex.size() % 2 == 0) {
        countHalfrow = readCountHalfrow(byteArrayHex);
        int sizeThread = 0;
        countThreads = readCountThread(byteArrayHex, sizeThread);
        isNode1_2 = readIsNode1_2(byteArrayHex, countThreads);
        if (countThreads >= 3) {
            if (countHalfrow >= 2) {
                int countBitDirection = (sizeThread + 1) * (countHalfrow + 2);
                if (byteArrayHex.size() >= countBitDirection) {
                    nodeDirections = readListNodeDirections(byteArrayHex, countBitDirection, (countThreads - 1) * (countHalfrow / 2));
                    int countMatrixElemet = countMatrixElemets(countThreads, isNode1_2);
                    if (byteArrayHex.size() >= countMatrixElemet) {
                        QList<bool> isSetColors = readListIsSetColor(byteArrayHex, countThreads, isNode1_2);
                        int countBitColor = 0;
                        for (int i = 0; i < isSetColors.size(); ++i) {
                            if (isSetColors[i]) {
                                countBitColor = countBitColor + 8;
                            }
                        }
                        if (byteArrayHex.size() >= countBitColor) {
                            colorThreads = readListColorThreads(byteArrayHex, isSetColors);
                        } else {
                            throw QString("Файл поврежден!\n"
                                          "Файл содержит неверную структуру.\n"
                                          "В файле должны быть записаны биты.\n"
                                          "В файле содержится битов: %1.\n"
                                          "В файле должно быть битов или более: %2.").arg(18 + byteArrayHex.size() + countBitDirection + countMatrixElemet).arg(18 + countBitDirection + countMatrixElemet + countBitColor);
                        }
                    } else {
                        throw QString("Файл поврежден!\n"
                                      "Файл содержит неверную структуру.\n"
                                      "В файле должны быть записаны биты.\n"
                                      "В файле содержится битов: %1.\n"
                                      "В файле должно быть битов или более: %2.").arg(18 + byteArrayHex.size() + countBitDirection).arg(18 + countBitDirection + countMatrixElemet);
                    }
                } else {
                    throw QString("Файл поврежден!\n"
                                  "Файл содержит неверную структуру.\n"
                                  "В файле должны быть записаны биты.\n"
                                  "В файле содержится битов: %1.\n"
                                  "В файле должно быть битов или более: %2.").arg(18 + byteArrayHex.size()).arg(18 + countBitDirection);
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
                      "В файле должно быть минимум 42 бита и количество битов в файле должно делиться на 2 без остатка.").arg(byteArrayHex.size());
    }

    return *(new SchemeObliqueChartView(countThreads, countHalfrow, isNode1_2, nodeDirections, colorThreads, name));
}

int SchemeObliqueFileReadFBD::readCountThread(QByteArray &byteArray, int &countThread)
{
    int result = readInteger(byteArray);
    if (result > 0) {
        countThread = result;
        return result;
    } else {
        throw QString("Файл поврежден!\n"
                      "Повреждены первые или вторые 8 бит.\n"
                      "В файле записаны первые или вторые 8 бит как '00000000'.\n"
                      "В файле должно быть от '01000000' до 'ffffffff' первых и вторых бит.");
    }
}

int SchemeObliqueFileReadFBD::readCountHalfrow(QByteArray &byteArray)
{
    int result = readInteger(byteArray);
    if (result > 0) {
        return result - 1;
    } else {
        throw QString("Файл поврежден!\n"
                      "Повреждены первые или вторые 8 бит.\n"
                      "В файле записаны первые или вторые 8 бит как '00000000'.\n"
                      "В файле должно быть от '01000000' до 'ffffffff' первых и вторых бит.");
    }
}

int SchemeObliqueFileReadFBD::readIsNode1_2(QByteArray &byteArray, int &countThreads)
{
    QByteArray string;
    for (int j = 0; j < 2; ++j) {
        string.push_back(byteArray.front());
        byteArray.remove(0, 1);
    }
    int isNode1_2 = string.toInt(nullptr, 16);
    bool boolIsNode1_2 = true;
    if (isNode1_2 >= 1 && isNode1_2 <= 4) {
        switch (string.toInt(nullptr, 16)) {
            case 1:
                boolIsNode1_2 = true;
                countThreads = countThreads * 2;
                break;
            case 2:
                boolIsNode1_2 = false;
                countThreads = (countThreads * 2) - 1;
                break;
            case 3:
                boolIsNode1_2 = true;
                countThreads = (countThreads * 2) + 1;
                break;
            case 4:
                boolIsNode1_2 = false;
                countThreads = countThreads * 2;
                break;
        }
    } else {
        throw QString("Файл поврежден!\n"
                      "Считая с конца файла повреждены биты в позициях: %1 - %2.\n"
                      "В файле записаны биты как: %3.\n"
                      "В файле должно быть от '01' до '04' бит.").arg(byteArray.size() + 2).arg(byteArray.size() + 1).arg(isNode1_2);
    }
    return boolIsNode1_2;
}

int SchemeObliqueFileReadFBD::readInteger(QByteArray &byteArray)
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

QList<bool> SchemeObliqueFileReadFBD::readListIsSetColor(QByteArray &byteArray, const int &coutThread, const int &isNode1_2)
{
    QList<bool> result;
    if (coutThread % 2 == 0) {
        if (isNode1_2) {
            byteArray.remove(0, 2);
            readIsColor(byteArray, coutThread, result);
            byteArray.remove(0, 2);
        } else {
            byteArray.remove(0, 4);
            readIsColor(byteArray, coutThread, result);
        }
    } else {
        if (isNode1_2) {
            byteArray.remove(0, 2);
            readIsColor(byteArray, coutThread, result);
        } else {
            byteArray.remove(0, 4);
            readIsColor(byteArray, coutThread, result);
            byteArray.remove(0, 2);
        }
    }
    return result;
}

void SchemeObliqueFileReadFBD::readIsColor(QByteArray &byteArray, const int &coutThread, QList<bool> &result)
{
    for (int i = 0; i < coutThread; ++i) {
        QByteArray oneBlockByte;
        for (int j = 0; j < 2; ++j) {
            oneBlockByte = oneBlockByte + byteArray.front();
            byteArray.remove(0, 1);
        }
        int isColor = oneBlockByte.toInt(nullptr, 16);
        if (isColor == 0 || isColor == 1) {
            result.push_back(isColor);
        } else {
            throw QString("Файл поврежден!\n"
                          "Считая с конца файла повреждены биты в позициях: %1 - %2.\n"
                          "В файле записаны биты как: %3.\n"
                          "В файле должно быть от '00' до '01' бит.").arg(byteArray.size() + 2).arg(byteArray.size() + 1).arg(isColor);
        }
    }
}

int SchemeObliqueFileReadFBD::countMatrixElemets(const int &coutThread, const int &isNode1_2)
{
    if (coutThread % 2 == 0) {
        if (isNode1_2) {
            return coutThread + 2;
        } else {
            return coutThread + 2;
        }
    } else {
        if (isNode1_2) {
            return coutThread + 1;
        } else {
            return coutThread + 3;
        }
    }
}

QList<QBrush> SchemeObliqueFileReadFBD::readListColorThreads(QByteArray &byteArray, const QList<bool> &isColor)
{
    QList<QBrush> threadColor;
    for (int i = 0; i < isColor.size(); ++i) {
        if (isColor[i]) {
            QByteArray string = "#";
            for (int j = 0; j < 8; ++j) {
                if (j < 6) {
                    string.push_back(byteArray.front());
                }
                byteArray.remove(0, 1);
            }
            threadColor.push_back(QBrush(QColor(QString::fromStdString(string.toStdString()))));
        } else {
            threadColor.push_back(QBrush(QColor(Qt::white)));
        }
    }
    return threadColor;
}

QList<int> SchemeObliqueFileReadFBD::readListNodeDirections(QByteArray &byteArray, const int &countRows, const int &coutDirection)
{
    QList<int> arrowsDirection;
    for (int i = 0; i < countRows; ++i) {
        QByteArray string;
        for (int j = 0; j < 2; ++j) {
            string.push_back(byteArray.front());
            byteArray.remove(0, 1);
        }
        int direcion = string.toInt(nullptr, 16);
        if (direcion >= 0 && direcion <= 32) {
            switch (direcion) {
                case 1:
                    direcion = 0;
                    break;
                case 2:
                    direcion = 7;
                    break;
                case 3:
                    direcion = 6;
                    break;
                case 4:
                    direcion = 5;
                    break;
                case 5:
                    direcion = 4;
                    break;
                default:
                    continue;
            }
            arrowsDirection.push_back(direcion);
        } else {
            throw QString("Файл поврежден!\n"
                          "Считая с конца файла повреждены биты в позициях: %1 - %2.\n"
                          "В файле записаны биты как: %3.\n"
                          "В файле должно быть от '00' до '20' бит.").arg(byteArray.size() + 2).arg(byteArray.size() + 1).arg(direcion);
        }
    }
    if (coutDirection == arrowsDirection.size()) {
        return arrowsDirection;
    } else {
        throw QString("Файл поврежден!\n"
                      "Неправильное колличество направлений.\n"
                      "Направлений в файле: %1.\n"
                      "Должно быть направлений: %2.").arg(arrowsDirection.size()).arg(coutDirection);
    }
}
