#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include <QTextStream>
#include <QSet>
#include <iostream>


// Генерация таблицы истинности для заданного числа переменных
QStringList generateTruthTable(int numVariables)
{
    QStringList truthTable;

    int numCombinations = 1 << numVariables; // Количество комбинаций равно 2^количество переменных

    for (int i = 0; i < numCombinations; i++)
    {
        QString binaryString = QString("%1").arg(i, numVariables, 2, QChar('0'));
        truthTable.append(binaryString);
    }

    return truthTable;
}

// Получение минтермов на основе таблицы истинности и значений функции
QStringList getMinterms(const QStringList& truthTable, const QString& functionValues)
{
    QStringList minterms;

    for (int i = 0; i < truthTable.size(); i++)
    {
        if (functionValues[i] == '1')
        {
            minterms.append(truthTable[i]);
        }
    }

    return minterms;
}

// Комбинирование двух минтермов, если они отличаются только в одном разряде
bool combineMinterms(QString& minterm1, QString& minterm2)
{
    int differingIndex = -1;
    int differingCount = 0;

    for (int i = 0; i < minterm1.size(); i++)
    {
        if (minterm1[i] != minterm2[i])
        {
            differingIndex = i;
            differingCount++;
        }
    }

    if (differingCount != 1)
    {
        return false;
    }

    minterm1[differingIndex] = '-';
    minterm2[differingIndex] = '-';

    return true;
}

// Выполнение алгоритма Квайна-МакКласки для получения первичных импликант
QStringList performQuineMcCluskey(const QStringList& minterms)
{
    QStringList primeImplicants = minterms;
    QStringList essentialPrimeImplicants;

    bool combined = true;

    while (combined)
    {
        combined = false;
        QStringList newPrimeImplicants;

        for (int i = 0; i < primeImplicants.size(); i++)
        {
            for (int j = i + 1; j < primeImplicants.size(); j++)
            {
                if (combineMinterms(primeImplicants[i], primeImplicants[j]))
                {
                    combined = true;
                }
            }

            if (combined)
            {
                newPrimeImplicants.append(primeImplicants[i]);
            }

            else
            {
                essentialPrimeImplicants.append(primeImplicants[i]);
            }
        }

        primeImplicants = newPrimeImplicants;
    }

    QStringList mdnf;

    for (const QString& minterm : essentialPrimeImplicants)
    {
        QStringList literals;

        for (int i = 0; i < minterm.size(); i++)
        {
            if (minterm[i] == '0') {
                literals.append(QString("!x%1").arg(i + 1));
            }

            else if (minterm[i] == '1')
            {
                literals.append(QString("x%1").arg(i + 1));
            }
        }

        mdnf.append(literals.join(" && "));
    }

    return mdnf;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString functionValues = "1110";

    int numVariables = 2;

    QStringList truthTable = generateTruthTable(numVariables);

    QStringList minterms = getMinterms(truthTable, functionValues);
    QStringList mdnf = performQuineMcCluskey(minterms);

    QSet<QString> uniq = QSet<QString>(mdnf.begin(), mdnf.end());
    QStringList uniqList = QStringList(uniq.begin(), uniq.end());

    qDebug() << "МДНФ:" << uniqList.join(" || ");

    return a.exec();
}
