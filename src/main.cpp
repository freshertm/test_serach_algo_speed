#include <QCoreApplication>
#include <QElapsedTimer>
#include <QDebug>
#include <QDateTime>

const qint32 repeats = 10000000;

struct Report {
  qint64 value;
  qint64 elapsed1;
  qint64 elapsed2;
  qint64 result1;
  qint64 result2;
  qint32 a2searches;
  qint32 a1searches;

  void print() {
      qInfo() << "v:" << value <<" e1:" << elapsed1 << " e2:" <<elapsed2 << "a1s"<< a1searches << "a2s:" << a2searches << QString((result1 == result2)?"OK":"FAIL");
  }
};

Report testf(QVector<qint32>a, int value){
    Report report;
    report.value = value;
    qint64 result1 = 0;
    qint64 result2 = 0;
    qint64 searches1 = 0;

    QElapsedTimer t;
    t.start();
    for (quint64 r=0; r<repeats; ++r){
        qint64 res = -1;
        for(qint32 i=a.count()-1; i>=0; --i)
        {
            searches1 += 1;
            if (a[i] <= value)
            {
                res = a[i];
                break;
            }
        }
        result1 += res;
    }

    qint64 el1 = t.elapsed();

    qint64 searches2 = 0;

    t.start();

    for (quint64 r=0; r<repeats; ++r){
        qint64 res = -1;

        if(value < a.first()){
            result2 -= 1;
            continue;
        }
        if(value >= a.last()) {
            result2 += a.last();
            continue;
        }
        qint32 pos = a.length() / 2;
        qint32 step = pos / 2;
        step += pos % 2;

        while (true){
            searches2 += 1;
            qint32 current = a[pos];
            qint32 next = a[pos+1];
            if(value >= current && value < next) {
                res = current;
                break;
            }
            if(value < current) {
                pos -= step;
            }
            else {
                pos += step;
            }
            step >>=1; //step = step / 2;
            if (step < 1) {
                step = 1;
            }
        }
        result2 += res;
    }

    qint64 el2 = t.elapsed();

    report.elapsed1 = el1;
    report.elapsed2 = el2;
    report.result1 = result1 / repeats;
    report.result2 = result2 / repeats;
    report.a1searches = searches1 / repeats;
    report.a2searches = searches2 / repeats;

    return report;
}


int main(int argc, char *argv[])
{
    if (argc != 3)
        return -1;

    QString value_s(argv[1]);
    qint32 value = value_s.toInt();

    QString asize_s(argv[2]);
    qint32 asize = asize_s.toInt();

    qDebug() << "checking values 0 .." << value;
    qDebug() << "Size of 'a' array: "<<asize;

    qsrand(QDateTime::currentMSecsSinceEpoch());

    qint32 sum1=0;
    qint32 sum2=0;
    qint32 min1=99999999;
    qint32 min2=99999999;
    qint32 max1=0;
    qint32 max2=0;

    //QVector<qint32> a = {3,4,6,9,10,12,14,15,17,19,21};

    QVector<qint32> a;
    a.reserve(asize);

    qint32 cur_value = 1;
    for(int i=0; i< asize; ++i) {
        cur_value += 1+ qrand() % 5;
        a.append(cur_value);
    }
    qInfo() << "a array:" << a;

    for (int i=0; i<=value; ++i) {
        Report r = testf(a, i);
        r.print();
        sum1 += r.elapsed1;
        sum2 += r.elapsed2;
        min1 = (r.elapsed1 < min1)? r.elapsed1: min1;
        min2 = (r.elapsed2 < min2)? r.elapsed2: min2;

        max1 = (r.elapsed1 > max1)? r.elapsed1: max1;
        max2 = (r.elapsed2 > max2)? r.elapsed2: max2;
    }

    qInfo() << "sum1: " << sum1 << " sum2:" << sum2;
    qInfo() << "avg1: " << sum1 / (value + 1) << " avg2:" << sum2 / (value + 1);
    qInfo() << "min1: " << min1 << " min2:" << min2;
    qInfo() << "max1: " << max1 << " max2:" << max2;

    return 0;
}
