#include "schemeobliquefilereadpfco.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "Scheme/Oblique/Chart/schemeobliquechartview.h"

SchemeObliqueFileReadPFCO::SchemeObliqueFileReadPFCO(): AbstractSchemeFileRead("pf.co", "Project Fenics - Complicated Oblique") {

}

SchemeObliqueFileReadPFCO::~SchemeObliqueFileReadPFCO()
{

}

AbstractSchemeChartView &SchemeObliqueFileReadPFCO::readScheme(QByteArray byteArray, QString name)
{
    bool isNode1_2;
    int countHalfrow;
    int countThreads;
    QList<int> nodeDirections;
    QList<QBrush> colorThreads;

    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(byteArray, &parseError);

    if (parseError.error == QJsonParseError::NoError) {
        if (jsonDocument.isObject()) {
            QJsonObject jsonObject = jsonDocument.object();
            setIsNode1_2(isNode1_2, jsonObject);
            setCountThreads(countThreads, jsonObject);
            if (countThreads >= 3) {
                setCountHalfrow(countHalfrow, jsonObject);
                if (countHalfrow >= 2) {
                    setColorThreads(colorThreads, jsonObject);
                    if (countThreads == colorThreads.size()) {
                        setDirectionNode(nodeDirections, jsonObject);
                        if (nodeDirections.size() != (((countHalfrow * (countThreads - 1)) / 2) + ((countHalfrow * (countThreads - 1)) % 2))) {
                            throw QString("Файл поврежден!\n"
                                          "Файл содержит неверный параметр или список.\n"
                                          "Значение формулы ((((CountHalfrow * (CountThreads - 1)) / 2) + ((CountHalfrow * (CountThreads - 1)) % 2))) и количество ColorThreads должны совпадать."
                                          "Параметр CountHalfrow равен %1.\n"
                                          "Параметр CountThreads равен %2.\n"
                                          "Значение формулы ((((CountHalfrow * (CountThreads - 1)) / 2) + ((CountHalfrow * (CountThreads - 1)) % 2))) равно %3.\n"
                                          "Список ColorThreads имеет %4 элементов.\n").arg(countHalfrow)
                                                                                      .arg(countThreads)
                                                                                      .arg((((countHalfrow * (countThreads - 1)) / 2) + ((countHalfrow * (countThreads - 1)) % 2)))
                                                                                      .arg(colorThreads.size());
                        }
                    } else {
                        throw QString("Файл поврежден!\n"
                                      "Файл содержит неверный параметр или список.\n"
                                      "Значение CountThreads и количество ColorThreads должны совпадать."
                                      "Параметр CountThreads равен %1.\n"
                                      "Список ColorThreads имеет %2 элементов.\n").arg(countThreads).arg(colorThreads.size());
                    }
                } else {
                    throw QString("Файл поврежден!\n"
                                  "Файл содержит неверный параметр.\n"
                                  "Параметр CountHalfrow должен быть больше или равен 2.\n"
                                  "Параметр CountHalfrow равен %1").arg(countHalfrow);
                }
            } else {
                throw QString("Файл поврежден!\n"
                              "Файл содержит неверный параметр.\n"
                              "Параметр CountThreads должен быть больше или равен 3.\n"
                              "Параметр CountThreads равен %1").arg(countThreads);
            }
        } else {
            throw QString("Файл поврежден!\n"
                          "Файл содержит неверную структуру.\n"
                          "В файле нет корневого объекта.");
        }
    } else {
        throw QString("Файл поврежден!\n"
                      "Ошибка парсинга файла.\n"
                      "Код ошибки %1.").arg(parseError.error);
    }

    return *(new SchemeObliqueChartView(countThreads, countHalfrow, isNode1_2, nodeDirections, colorThreads, name));
}

void SchemeObliqueFileReadPFCO::setColorThreads(QList<QBrush> &colorThreads, const QJsonObject &jsonObject)
{
    if (jsonObject.contains("ColorThreads")) {
        if (jsonObject["ColorThreads"].isArray()) {
            QJsonArray arrayColorThreads = jsonObject["ColorThreads"].toArray();
            if (!arrayColorThreads.isEmpty()) {
                for (int i = 0; i < arrayColorThreads.size(); i++) {
                    if (!arrayColorThreads[i].isUndefined()) {
                        if (!arrayColorThreads[i].isNull()) {
                            if (arrayColorThreads[i].isString()) {
                                QColor color = QColor::fromString(arrayColorThreads[i].toString());
                                if (color.isValid()) {
                                    colorThreads.push_back(QBrush(color));
                                } else {
                                    throw QString("Файл поврежден!\n"
                                                  "Файл содержит неверную структуру.\n"
                                                  "Список ColorThreads должен состоять из элементов каждый из которых должен являться строкой типа \"#ffffff\" (шестнадцатиричное представление цвета).\n"
                                                  "Элемент с номером по порядку %1 содержит значение равное %2").arg(i).arg(arrayColorThreads[i].toString());
                                }
                            } else {
                                throw QString("Файл поврежден!\n"
                                              "Файл содержит неверную структуру.\n"
                                              "Список ColorThreads должен состоять из элементов каждый из которых должен являться строкой типа \"#ffffff\" (шестнадцатиричное представление цвета).\n"
                                              "Элемент с номером по порядку %1 содержит значение которое не является строкой.").arg(i);
                            }
                        } else {
                            throw QString("Файл поврежден!\n"
                                          "Файл содержит неверную структуру.\n"
                                          "Список ColorThreads должен состоять из элементов каждый из которых должен являться строкой типа \"#ffffff\" (шестнадцатиричное представление цвета).\n"
                                          "Элемент с номером по порядку %1 содержит значение раное null").arg(i);
                        }
                    } else {
                        throw QString("Файл поврежден!\n"
                                      "Файл содержит неверную структуру.\n"
                                      "Список ColorThreads должен состоять из элементов каждый из которых должен являться строкой типа \"#ffffff\" (шестнадцатиричное представление цвета).\n"
                                      "Элемент с номером по порядку %1 содержит неопределенное значение").arg(i);
                    }
                }
            } else {
                throw QString("Файл поврежден!\n"
                              "Файл содержит неверную структуру.\n"
                              "Список ColorThreads должен состоять из элементов каждый из которых должен являться строкой типа \"#ffffff\" (шестнадцатиричное представление цвета).\n"
                              "Список ColorThreads пуст.");
            }
        } else {
            throw QString("Файл поврежден!\n"
                          "Файл содержит неверную структуру.\n"
                          "Файл должен содержать список ColorThreads.\n"
                          "Объект ColorThreads не является списком.");
        }
    } else {
        throw QString("Файл поврежден!\n"
                      "Файл содержит неверную структуру.\n"
                      "Файл должен содержать список ColorThreads.\n"
                      "В файле нет список ColorThreads.");
    }
}

void SchemeObliqueFileReadPFCO::setDirectionNode(QList<int> &nodeDirections, const QJsonObject &jsonObject)
{
    if (jsonObject.contains("DirectionNodes")) {
        if (jsonObject["DirectionNodes"].isArray()) {
            QJsonArray arrayDirectionNodes = jsonObject["DirectionNodes"].toArray();
            if (!arrayDirectionNodes.isEmpty()) {
                for (int i = 0; i < arrayDirectionNodes.size(); i++) {
                    if (!arrayDirectionNodes[i].isUndefined()) {
                        if (!arrayDirectionNodes[i].isNull()) {
                            if (arrayDirectionNodes[i].isString()) {
                                QString direction = arrayDirectionNodes[i].toString();
                                if (direction == "0" || direction == "1" ||
                                    direction == "2" || direction == "3" ||
                                    direction == "4" || direction == "5" ||
                                    direction == "6" || direction == "7") {
                                    nodeDirections.push_back(direction.toInt());
                                } else {
                                    throw QString("Файл поврежден!\n"
                                                  "Файл содержит неверную структуру.\n"
                                                  "Список DirectionNodes должен состоять из элементов каждый из которых должен являться строкой \"0\" или \"1\" или \"2\" или \"3\" или \"4\" или \"5\" или \"6\" или \"7\".\n"
                                                  "Элемент с номером по порядку %1 содержит значение равное %2.").arg(i).arg(direction);
                                }
                            } else {
                                throw QString("Файл поврежден!\n"
                                              "Файл содержит неверную структуру.\n"
                                              "Список DirectionNodes должен состоять из элементов каждый из которых должен являться строкой \"0\" или \"1\" или \"2\" или \"3\" или \"4\" или \"5\" или \"6\" или \"7\".\n"
                                              "Элемент с номером по порядку %1 содержит значение которое не является строкой.").arg(i);
                            }
                        } else {
                            throw QString("Файл поврежден!\n"
                                          "Файл содержит неверную структуру.\n"
                                          "Список DirectionNodes должен состоять из элементов каждый из которых должен являться строкой \"0\" или \"1\" или \"2\" или \"3\" или \"4\" или \"5\" или \"6\" или \"7\".\n"
                                          "Элемент с номером по порядку %1 содержит значение равное null").arg(i);
                        }
                    } else {
                        throw QString("Файл поврежден!\n"
                                      "Файл содержит неверную структуру.\n"
                                      "Список DirectionNodes должен состоять из элементов каждый из которых должен являться строкой \"0\" или \"1\" или \"2\" или \"3\" или \"4\" или \"5\" или \"6\" или \"7\".\n"
                                      "Элемент с номером по порядку %1 содержит неопределенное значение").arg(i);
                    }
                }
            } else {
                throw QString("Файл поврежден!\n"
                              "Файл содержит неверную структуру.\n"
                              "Список DirectionNodes должен состоять из элементов каждый из которых должен являться строкой \"0\" или \"1\" или \"2\" или \"3\" или \"4\" или \"5\" или \"6\" или \"7\".\n"
                              "Список DirectionNodes пуст.");
            }
        } else {
            throw QString("Файл поврежден!\n"
                          "Файл содержит неверную структуру.\n"
                          "Файл должен содержать список DirectionNodes.\n"
                          "Объект DirectionNodes не является списком.");
        }
    } else {
        throw QString("Файл поврежден!\n"
                      "Файл содержит неверную структуру.\n"
                      "Файл должен содержать список DirectionNodes.\n"
                      "В файле нет список DirectionNodes.");
    }
}

void SchemeObliqueFileReadPFCO::setIsNode1_2(bool &isNode1_2, const QJsonObject &jsonObject)
{
    if (jsonObject.contains("IsNode1_2")) {
        QJsonValue value = jsonObject["IsNode1_2"];
        if (!value.isUndefined()) {
            if (!value.isNull()) {
                if (value.isString()) {
                    QString boolean = value.toString();
                    if (boolean == "0" || boolean == "1") {
                        isNode1_2 = boolean.toInt();
                    } else {
                        throw QString("Файл поврежден!\n"
                                      "Файл содержит неверный параметр.\n"
                                      "Параметр IsNode1_2 должен содержать строку \"0\" или \"1\".\n"
                                      "Параметр CountHalfrow содержит строку %1.").arg(value.toString());
                    }
                } else {
                    throw QString("Файл поврежден!\n"
                                  "Файл содержит неверный параметр.\n"
                                  "Параметр IsNode1_2 должен содержать строку \"0\" или \"1\".\n"
                                  "Параметр CountHalfrow содержит значение которое не является строкой.");
                }
            } else {
                throw QString("Файл поврежден!\n"
                              "Файл содержит неверный параметр.\n"
                              "Параметр IsNode1_2 должен содержать строку \"0\" или \"1\".\n"
                              "Параметр CountHalfrow содержит значение равное null.");
            }
        } else {
            throw QString("Файл поврежден!\n"
                          "Файл содержит неверный параметр.\n"
                          "Параметр IsNode1_2 должен содержать строку \"0\" или \"1\".\n"
                          "Параметр IsNode1_2 содержит неопределенное значение.");
        }
    } else {
        throw QString("Файл поврежден!\n"
                      "Файл содержит неверную структуру.\n"
                      "Файл должен содержать параметр IsNode1_2.\n"
                      "В файле нет параметра IsNode1_2.");
    }
}

void SchemeObliqueFileReadPFCO::setCountHalfrow(int &countHalfrow, const QJsonObject &jsonObject)
{
    if (jsonObject.contains("CountHalfrow")) {
        QJsonValue value = jsonObject["CountHalfrow"];
        if (!value.isUndefined()) {
            if (!value.isNull()) {
                if (value.isString()) {
                    QString integer = value.toString();
                    bool isOk = false;
                    int integetCountHalfrow = integer.toInt(&isOk);
                    if (isOk) {
                        countHalfrow = integetCountHalfrow;
                    } else {
                        throw QString("Файл поврежден!\n"
                                      "Файл содержит неверный параметр.\n"
                                      "Параметр CountHalfrow должен содержать строку состоящую из цифр.\n"
                                      "Параметр CountHalfrow содержит строку %1.").arg(value.toString());
                    }
                } else {
                    throw QString("Файл поврежден!\n"
                                  "Файл содержит неверный параметр.\n"
                                  "Параметр CountHalfrow должен содержать строку состоящую из цифр.\n"
                                  "Параметр CountHalfrow содержит значение которое не является строкой.");
                }
            } else {
                throw QString("Файл поврежден!\n"
                              "Файл содержит неверный параметр.\n"
                              "Параметр CountHalfrow должен содержать строку состоящую из цифр.\n"
                              "Параметр CountHalfrow содержит значение равное null.");
            }
        } else {
            throw QString("Файл поврежден!\n"
                          "Файл содержит неверный параметр.\n"
                          "Параметр CountHalfrow должен содержать строку состоящую из цифр.\n"
                          "Параметр CountHalfrow содержит неопределенное значение.");
        }
    } else {
        throw QString("Файл поврежден!\n"
                      "Файл содержит неверную структуру.\n"
                      "Файл должен содержать параметр CountHalfrow.\n"
                      "В файле нет параметра CountHalfrow.");
    }
}

void SchemeObliqueFileReadPFCO::setCountThreads(int &countThreads, const QJsonObject &jsonObject)
{
    if (jsonObject.contains("CountThreads")) {
        QJsonValue value = jsonObject["CountThreads"];
        if (!value.isUndefined()) {
            if (!value.isNull()) {
                if (value.isString()) {
                    QString integer = value.toString();
                    bool isOk = false;
                    int integetCountThreads = integer.toInt(&isOk);
                    if (isOk) {
                        countThreads = integetCountThreads;
                    } else {
                        throw QString("Файл поврежден!\n"
                                      "Файл содержит неверный параметр.\n"
                                      "Параметр CountThreads должен содержать строку состоящую из цифр.\n"
                                      "Параметр CountThreads содержит строку %1.").arg(value.toString());
                    }
                } else {
                    throw QString("Файл поврежден!\n"
                                  "Файл содержит неверный параметр.\n"
                                  "Параметр CountThreads должен содержать строку состоящую из цифр.\n"
                                  "Параметр CountThreads содержит значение которое не является строкой.");
                }
            } else {
                throw QString("Файл поврежден!\n"
                              "Файл содержит неверный параметр.\n"
                              "Параметр CountThreads должен содержать строку состоящую из цифр.\n"
                              "Параметр CountThreads содержит значение равное null.");
            }
        } else {
            throw QString("Файл поврежден!\n"
                          "Файл содержит неверный параметр.\n"
                          "Параметр CountThreads должен содержать строку состоящую из цифр.\n"
                          "Параметр CountThreads содержит неопределенное значение.");
        }
    } else {
        throw QString("Файл поврежден!\n"
                      "Файл содержит неверную структуру.\n"
                      "Файл должен содержать параметр CountThreads.\n"
                      "В файле нет параметра CountThreads.");
    }
}
