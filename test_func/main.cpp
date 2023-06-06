#include <QString>
#include <QPointF>
#include <QList>
#include <cmath> // Добавляем заголовочный файл для стандартных математических функций
#include <QCoreApplication>
#include <QDebug>

// Функция для вычисления периметра многоугольника
qreal calculatePerimeter(const QList<QPointF>& points)
{
    qreal perimeter = 0.0;
    int numPoints = points.size();

    for (int i = 0; i < numPoints; ++i) {
        const QPointF& p1 = points[i];
        const QPointF& p2 = points[(i + 1) % numPoints];
        qreal dx = p2.x() - p1.x();
        qreal dy = p2.y() - p1.y();
        perimeter += std::sqrt(dx * dx + dy * dy); // Используем std::sqrt вместо qSqrt
    }

    return perimeter;
}

// Функция для вычисления площади многоугольника
qreal calculateArea(const QList<QPointF>& points)
{
    qreal area = 0.0;
    int numPoints = points.size();

    for (int i = 0; i < numPoints; ++i) {
        const QPointF& p1 = points[i];
        const QPointF& p2 = points[(i + 1) % numPoints];
        area += p1.x() * p2.y() - p2.x() * p1.y();
    }

    return std::fabs(area) / 2.0; // Используем std::fabs вместо qFabs
}

// Основная функция для обработки сообщения
QString processMessage(const QString& message)
{
    QStringList parts = message.split('@');
    QString figureType = parts[0];

    if (parts.size() != 4 || (figureType != "perimetr" && figureType != "square")) {
        return "Invalid message format";
    }

    QStringList pointStrings = parts.mid(1);
    QList<QPointF> points;

    for (const QString& pointString : pointStrings) {
        QStringList coords = pointString.split(',');
        if (coords.size() != 2) {
            return "Invalid coordinate format";
        }
        qreal x = coords[0].toDouble();
        qreal y = coords[1].toDouble();
        points.append(QPointF(x, y));
    }

    if (figureType == "perimetr") {
        qreal perimeter = calculatePerimeter(points);
        return QString::number(perimeter);
    } else if (figureType == "square") {
        qreal area = calculateArea(points);
        return QString::number(area);
    }

    return "Unknown figure type";
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString message = "perimetr@1,2@2,3@4,5";
    QString result = processMessage(message);
    qDebug() << "Result: " << result;

    return app.exec();
}
