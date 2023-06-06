#ifndef FUNC_FOR_SERVER_H
#define FUNC_FOR_SERVER_H
#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QList>
#include <QStringList>
#include <QDebug>

QByteArray parsing(QString str, QTcpSocket &a);
double calculatePerimeter(const QVector<QPointF>& points);
double calculateSquare(const QVector<QPointF>& points);
QString processMessage(const QString& message);

////////////////////////////////////////////////


#endif // FUNC_FOR_SERVER_H
