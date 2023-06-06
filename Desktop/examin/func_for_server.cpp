#include "func_for_server.h"
#include <QString>
#include <QPointF>
#include <QVector>
#include <QtMath>

/**
 * @brief Функция разбора запроса от клиента.
 * @param str Строка запроса от клиента.
 * @param a Сокет клиента.
 * @return Результат выполнения запроса в виде массива байт.
 */


QByteArray parsing(QString str, QTcpSocket &a)
{
    QStringList parts = str.split('@');

    QString operation = parts[0];

    QStringList pointStrings = parts.mid(1);
    QVector<QPointF> points;

    for (const QString& pointString : pointStrings) {
        QStringList coordinates = pointString.split(',');
        if (coordinates.size() != 2) {
            return "Неверный формат координат.";
        }

        bool xConversionOk, yConversionOk;
        double x = coordinates[0].toDouble(&xConversionOk);
        double y = coordinates[1].toDouble(&yConversionOk);

        if (!xConversionOk || !yConversionOk) {
            return "Ошибка преобразования координат.";
        }

        points.append(QPointF(x, y));
    }

    if (operation == "perimeter") {
        double perimeter = calculatePerimeter(points);
        return QString("Периметр: %1").arg(perimeter).toUtf8();
    } else if (operation == "square") {
        double square = calculateSquare(points);
        return QString("Площадь: %1").arg(square).toUtf8();
    }


    return "Введите запрос: ";
}



//периметр
double calculatePerimeter(const QVector<QPointF>& points)
{
    double perimeter = 0.0;
    int pointCount = points.size();

    for (int i = 0; i < pointCount; ++i) {
        const QPointF& currentPoint = points[i];
        const QPointF& nextPoint = points[(i + 1) % pointCount];

        double dx = nextPoint.x() - currentPoint.x();
        double dy = nextPoint.y() - currentPoint.y();

        perimeter += qSqrt(dx * dx + dy * dy);
    }

    return perimeter;
}

//площад
double calculateSquare(const QVector<QPointF>& points)
{
    double square = 0.0;
    int pointCount = points.size();

    for (int i = 0; i < pointCount; ++i) {
        const QPointF& currentPoint = points[i];
        const QPointF& nextPoint = points[(i + 1) % pointCount];

        square += (currentPoint.x() * nextPoint.y() - nextPoint.x() * currentPoint.y());
    }

    return qFabs(square) / 2.0;
}


