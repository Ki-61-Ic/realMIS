#include "util.h"
#include <QString>

void writeAcc(int acc)
{
    QFile file("/Users/Lihaotian/desktop/acc.txt");
    file.open(QIODevice::WriteOnly);
    file.close();
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream.seek(file.size());
        stream<<QString::number(acc)<<"\n";
        file.close();
    }
    qDebug()<<"文件已写入";
}

int readAcc()
{
    QString displayString;
    QFile file("/Users/Lihaotian/Desktop/acc.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        qDebug()<< str;
        displayString.append(str);
    }
    file.close();
    return displayString.toInt();
}
