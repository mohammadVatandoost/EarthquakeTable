#include "csv.h"

void appendDataToCSV(QVector<QStringList> dataList, QString fileDirection) {


//#ifdef linux
QFile csvFile(fileDirection);
  if(csvFile.open(QIODevice::WriteOnly | QIODevice::Append) )
  {
       QTextStream textStream( &csvFile );
       QStringList stringList;

       for( int row = 0; row < dataList.length(); row++ )
       {
           stringList.clear();
           for( int column = 0; column < dataList[row].length(); column++ )
           {
               stringList << dataList[row][column] ;
           }
           textStream << stringList.join( ',' )+"\n";
       }
       csvFile.close();
  } else {
       cout<< "can not opened file fileDirection"<<fileDirection.toStdString()<<endl;
  }

//#endif

//#ifdef _WIN32
//ofstream csvFile (fileDirection.toStdString(), std::ofstream::out | std::ofstream::app);
//if (csvFile.is_open())
//{
//    //    QTextStream textStream( &csvFile );
//        QStringList stringList;

//        for( int row = 0; row < dataList.length(); row++ )
//        {
//            stringList.clear();
//            for( int column = 0; column < dataList[row].length(); column++ )
//            {
//                stringList << dataList[row][column] ;
//            }
//            string temp = stringList.join( ',' ).toStdString()+"\n" ;
//            csvFile << temp;
//        }
//        csvFile.close();
//} else {
//    cout<< "can not opened file fileDirection"<<fileDirection.toStdString()<<endl;
//}

//#endif


}

QVector<QStringList> readCSV(QString fileLocation, QString splitString) {
    QFile file(fileLocation);
    QVector<QStringList> temp;
    if ( !file.open(QFile::ReadOnly | QFile::Text) ) {
        qDebug() << "File not exists";
    } else {
        QTextStream in(&file);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList stringList;
            for (QString item : line.split(splitString)) {
                stringList.append(item);
            }
            temp.append(stringList);
        }
        file.close();
    }
    return temp;
}
