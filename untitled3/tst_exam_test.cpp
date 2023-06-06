#include <QtTest>

// add necessary includes here

class exam_test : public QObject
{
    Q_OBJECT

public:
    exam_test();
    ~exam_test();

private slots:
    void test_case1();

};

exam_test::exam_test()
{

}

exam_test::~exam_test()
{

}

void exam_test::test_case1()
{
    QString
}

QTEST_APPLESS_MAIN(exam_test)

#include "tst_exam_test.moc"
