#include "jsonstoring.h"

JsonStoring::JsonStoring()
{

}

void JsonStoring::storeGeneralData(GeneralData generalData)
{
     QJsonObject qJsonObject;
     qJsonObject.insert("torque", generalData.torque);
     // ground motion
     QJsonArray array;
     for(int i=0; i<generalData.groundMotion.size(); i++) {
         QJsonObject temp;
         temp.insert("name", generalData.groundMotion[i].name);
         temp.insert("fileDirectory", generalData.groundMotion[i].fileDirectory);
         temp.insert("timeStep", generalData.groundMotion[i].timeStep);
         array.push_front(temp);
     }
     qJsonObject.insert("groundMotions", array);
     // colibrate
     QJsonArray array2;
     for(int i=0; i<generalData.colibrateItems.size(); i++) {
         QJsonObject temp;
         temp.insert("name", generalData.colibrateItems[i].name);
         temp.insert("colibrate", generalData.colibrateItems[i].colibrate);
         array2.push_front(temp);
     }
     qJsonObject.insert("colibrateItems", array2);
     QString data = jsonToString(qJsonObject);
     storeToFile(data, GeneralDataFile);
}

GeneralData JsonStoring::getGeneralData()
{
   QString jsonString = getFileString(GeneralDataFile);
   GeneralData temp;
   if(jsonString == "") {
       cout<< "JsonStoring::getBoardData() does not exist"<<endl;
       return  temp;
   }
   QJsonDocument qJsonDocument = QJsonDocument::fromJson(jsonString.toUtf8());
   QJsonObject qJsonObject = qJsonDocument.object();
//   QJsonArray array = qJsonObject.find("groundMotions").;
   // get colibrate item
   temp.torque = static_cast<int>(qJsonObject.value("torque").toString().toInt()) ;
   return  temp;
}

QString JsonStoring::jsonToString(QJsonObject jsonObject)
{
    QJsonDocument doc(jsonObject);
    return  doc.toJson(QJsonDocument::Compact);
}

void JsonStoring::storeToFile(QString data, QString fileName)
{
    QFile file(fileName);
        if(file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text) )
        {
            QTextStream textStream( &file );
            QStringList stringList;
            textStream << data;
            file.close();
        } else {
            cout<< " file " << fileName.data() << " could not open" << endl;
        }
}

QString JsonStoring::getFileString(QString fileName)
{
    QString temp = "";
    QFile file(fileName);
    if(!file.exists()) {
        return temp;
    }
    if( !file.open(QFile::ReadOnly | QFile::Text) ) {
        cout << fileName.data() << " File not exists "<<endl;
    } else {
        QTextStream in(&file);
        temp = in.readLine();
        file.close();
    }

    return temp;
}
